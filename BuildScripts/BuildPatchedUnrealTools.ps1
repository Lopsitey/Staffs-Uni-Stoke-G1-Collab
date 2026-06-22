param(
    [string]$EngineRoot = "C:\Program Files\Epic Games\UE_5.6\Engine"
)

$ErrorActionPreference = "Stop"

$runDotnet = (Get-Command "dotnet" -ErrorAction Stop).Source

$ubtProject = Join-Path $EngineRoot `
    "Source\Programs\UnrealBuildTool\UnrealBuildTool.csproj"

$iosProject = Join-Path $EngineRoot `
    "Source\Programs\AutomationTool\IOS\IOS.Automation.csproj"

$iosSource = Join-Path $EngineRoot `
    "Source\Programs\AutomationTool\IOS\IOSPlatform.Automation.cs"

$builtUbtPath = Join-Path $EngineRoot `
    "Source\Programs\UnrealBuildTool\bin\Development\UnrealBuildTool.dll"

$installedUbtPath = Join-Path $EngineRoot `
    "Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.dll"

# IOS.Automation builds directly into this installed-engine directory.
$installedIosPath = Join-Path $EngineRoot `
    "Binaries\DotNET\AutomationTool\AutomationScripts\Platforms\IOS\IOS.Automation.dll"

$patchMarker = "Copied automatic iOS provision into staged package"

foreach ($requiredPath in @(
    $ubtProject,
    $iosProject,
    $iosSource
)) {
    if (-not (Test-Path -LiteralPath $requiredPath)) {
        throw "Required path was not found: $requiredPath"
    }
}

if (Get-Process "UnrealEditor" -ErrorAction SilentlyContinue) {
    throw "Close Unreal Editor before rebuilding and replacing its tool assemblies."
}

function Invoke-UnrealDotNetBuild {
    param(
        [Parameter(Mandatory)]
        [string]$Project
    )

    Write-Host ""
    Write-Host "============================================================"
    Write-Host "Building:"
    Write-Host "  $Project"
    Write-Host "============================================================"

    $buildArguments = @(
        "build"
        $Project
        "-c"
        "Development"
        "--no-incremental"
        "-p:NuGetAudit=false"
        "-p:TreatWarningsAsErrors=false"
    )

    & $runDotnet @buildArguments

    if ($LASTEXITCODE -ne 0) {
        throw "Build failed for $Project with exit code $LASTEXITCODE."
    }

    Write-Host ""
    Write-Host "[SUCCESS] Project build completed:"
    Write-Host "          $Project"
}

function Get-Sha256 {
    param(
        [Parameter(Mandatory)]
        [string]$Path
    )

    return (Get-FileHash `
        -LiteralPath $Path `
        -Algorithm SHA256).Hash
}

function Test-BinaryContainsText {
    param(
        [Parameter(Mandatory)]
        [string]$Path,

        [Parameter(Mandatory)]
        [string]$Text
    )

    [byte[]]$bytes = [System.IO.File]::ReadAllBytes($Path)

    # Check single-byte/UTF-8 representation.
    $utf8Text = [System.Text.Encoding]::UTF8.GetString($bytes)
    if ($utf8Text.Contains($Text)) {
        return $true
    }

    # .NET user strings are normally stored as UTF-16. Check both possible
    # byte alignments in the PE file.
    $unicodeText = [System.Text.Encoding]::Unicode.GetString($bytes)
    if ($unicodeText.Contains($Text)) {
        return $true
    }

    if ($bytes.Length -gt 1) {
        $shiftedUnicodeText =
            [System.Text.Encoding]::Unicode.GetString(
                $bytes,
                1,
                $bytes.Length - 1
            )

        if ($shiftedUnicodeText.Contains($Text)) {
            return $true
        }
    }

    return $false
}

# Ensure the intended iOS patch is actually saved before compiling.
if (-not (Select-String `
    -LiteralPath $iosSource `
    -Pattern $patchMarker `
    -SimpleMatch `
    -Quiet)) {

    throw @"
The iOS Automation source does not contain the expected patch marker:

$patchMarker

Check that IOSPlatform.Automation.cs was saved before running this script.
"@
}

Write-Host ""
Write-Host "[OK] iOS Automation source contains the provisioning patch marker."

$oldInstalledUbtHash = $null
if (Test-Path -LiteralPath $installedUbtPath) {
    $oldInstalledUbtHash = Get-Sha256 $installedUbtPath
}

$oldInstalledIosHash = $null
$oldInstalledIosTime = $null

if (Test-Path -LiteralPath $installedIosPath) {
    $oldInstalledIosHash = Get-Sha256 $installedIosPath
    $oldInstalledIosTime =
        (Get-Item -LiteralPath $installedIosPath).LastWriteTimeUtc
}

Invoke-UnrealDotNetBuild -Project $ubtProject

$iosBuildStartedUtc = [DateTime]::UtcNow
Invoke-UnrealDotNetBuild -Project $iosProject

foreach ($requiredOutput in @(
    $builtUbtPath,
    $installedUbtPath,
    $installedIosPath
)) {
    if (-not (Test-Path -LiteralPath $requiredOutput)) {
        throw "Expected build output was not found: $requiredOutput"
    }
}

# -------------------------------------------------------------------------
# Install and verify UnrealBuildTool
# -------------------------------------------------------------------------

Write-Host ""
Write-Host "Installing UnrealBuildTool:"
Write-Host "  Source:      $builtUbtPath"
Write-Host "  Destination: $installedUbtPath"

Copy-Item `
    -LiteralPath $builtUbtPath `
    -Destination $installedUbtPath `
    -Force

$builtUbtHash = Get-Sha256 $builtUbtPath
$installedUbtHash = Get-Sha256 $installedUbtPath

if ($builtUbtHash -ne $installedUbtHash) {
    throw @"
UnrealBuildTool copy verification failed.

Built hash:
$builtUbtHash

Installed hash:
$installedUbtHash
"@
}

$newInstalledUbt = Get-Item -LiteralPath $installedUbtPath

Write-Host ""
Write-Host "[SUCCESS] UnrealBuildTool.dll was copied and verified."
Write-Host "          Path:   $installedUbtPath"
Write-Host "          SHA256: $installedUbtHash"
Write-Host "          Time:   $($newInstalledUbt.LastWriteTime)"

if ($null -ne $oldInstalledUbtHash) {
    if ($oldInstalledUbtHash -eq $installedUbtHash) {
        Write-Host "          Note: compiled contents are unchanged from the previous DLL."
    }
    else {
        Write-Host "          Previous installed DLL had different contents."
    }
}

# -------------------------------------------------------------------------
# Verify IOS.Automation
# -------------------------------------------------------------------------

# This project outputs directly into the installed AutomationTool directory,
# so there is no separate source DLL to copy afterwards.
$newInstalledIos = Get-Item -LiteralPath $installedIosPath
$newInstalledIosHash = Get-Sha256 $installedIosPath

if ($newInstalledIos.LastWriteTimeUtc -lt $iosBuildStartedUtc.AddSeconds(-2)) {
    throw @"
IOS.Automation.dll exists, but its timestamp was not updated by this build.

Path:
$installedIosPath

Timestamp:
$($newInstalledIos.LastWriteTimeUtc)

Build began:
$iosBuildStartedUtc
"@
}

if (-not (Test-BinaryContainsText `
    -Path $installedIosPath `
    -Text $patchMarker)) {

    throw @"
IOS.Automation.dll was built, but the compiled DLL does not contain the
expected patch marker:

$patchMarker

This usually means the edited source file was not part of the project that
produced the installed DLL.
"@
}

Write-Host ""
Write-Host "[SUCCESS] IOS.Automation.dll was rebuilt in its installed location."
Write-Host "          Path:   $installedIosPath"
Write-Host "          SHA256: $newInstalledIosHash"
Write-Host "          Time:   $($newInstalledIos.LastWriteTime)"
Write-Host "          Compiled patch marker: FOUND"

if ($null -ne $oldInstalledIosHash) {
    if ($oldInstalledIosHash -eq $newInstalledIosHash) {
        Write-Host "          Note: compiled contents are unchanged from the previous DLL."
    }
    else {
        Write-Host "          Previous installed DLL had different contents."
    }
}

Write-Host ""
Write-Host "============================================================"
Write-Host "[SUCCESS] BOTH PATCHED UNREAL TOOLS ARE INSTALLED AND VERIFIED"
Write-Host "============================================================"
Write-Host "UnrealBuildTool:"
Write-Host "  $installedUbtPath"
Write-Host ""
Write-Host "IOS Automation:"
Write-Host "  $installedIosPath"
Write-Host ""
