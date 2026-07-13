[CmdletBinding()]
param(
    [ValidateSet("Win64")]
    [string] $Platform = "Win64",

    [ValidateSet("Shipping", "Development", "DebugGame")]
    [string] $Configuration = "Shipping",

    [switch] $Preview,
    [switch] $SkipUpload,
    [switch] $ArchivePackage,
    [switch] $AllowDirtyWorkingTree,
    [switch] $SkipBranchConfirmation,
    [switch] $SkipLiveConfirmation,

    [int] $WaitForProcessId = 0
)

$ErrorActionPreference = "Stop"
Set-StrictMode -Version Latest

function Assert-NativeSuccess {
    param(
        [Parameter(Mandatory = $true)]
        [string] $Message
    )

    if ($LASTEXITCODE -ne 0) {
        throw "$Message Exit code: $LASTEXITCODE"
    }
}

function Get-FirstExistingPath {
    param(
        [AllowEmptyString()]
        [AllowNull()]
        [string[]] $Paths
    )

    if (-not $Paths) {
        return $null
    }

    foreach ($Path in $Paths) {
        if (-not [string]::IsNullOrWhiteSpace($Path) -and (Test-Path -LiteralPath $Path)) {
            return (Resolve-Path -LiteralPath $Path).Path
        }
    }

    return $null
}

function Get-RequiredPath {
    param(
        [Parameter(Mandatory = $true)]
        [string] $Name,

        [AllowEmptyString()]
        [AllowNull()]
        [string[]] $Candidates,

        [Parameter(Mandatory = $true)]
        [string] $EnvironmentVariable
    )

    $Path = Get-FirstExistingPath -Paths $Candidates
    if ($Path) {
        return $Path
    }

    throw "Could not find $Name. Set $EnvironmentVariable to the full path and run this script again."
}

function Get-SteamBranchForGitBranch {
    param(
        [Parameter(Mandatory = $true)]
        [string] $BranchName
    )

    $LowerBranch = $BranchName.ToLowerInvariant()
    if ($LowerBranch.Contains("live")) {
        return "default"
    }

    if ($LowerBranch.Contains("beta")) {
        return "beta"
    }

    if ($LowerBranch.Contains("dev")) {
        return "dev"
    }

    throw "Current Git branch '$BranchName' is not valid for Steam upload. Use a branch name containing dev, beta, or live."
}

function Remove-PackageArchive {
    param(
        [Parameter(Mandatory = $true)]
        [string] $OutputRoot,

        [Parameter(Mandatory = $true)]
        [string] $SteamPackageRoot
    )

    if (-not (Test-Path -LiteralPath $OutputRoot)) {
        return
    }

    $ResolvedOutputRoot = (Resolve-Path -LiteralPath $OutputRoot).Path.TrimEnd('\', '/')
    $ResolvedSteamPackageRoot = (Resolve-Path -LiteralPath $SteamPackageRoot).Path.TrimEnd('\', '/')
    $ExpectedPrefix = $ResolvedSteamPackageRoot + [System.IO.Path]::DirectorySeparatorChar

    if (-not $ResolvedOutputRoot.StartsWith($ExpectedPrefix, [System.StringComparison]::OrdinalIgnoreCase)) {
        throw "Refusing to delete package archive outside Steam package root. Path: $ResolvedOutputRoot"
    }

    Remove-Item -LiteralPath $ResolvedOutputRoot -Recurse -Force
}

$ProjectRoot = (Resolve-Path -LiteralPath (Join-Path $PSScriptRoot "..")).Path
$ProjectFile = Join-Path $ProjectRoot "G1Collab.uproject"
$ProjectConfig = Get-Content -Raw -LiteralPath $ProjectFile | ConvertFrom-Json
$EngineAssociation = $ProjectConfig.EngineAssociation
$GameTarget = "StepsToTheStars"

$Timestamp = Get-Date -Format "yyyyMMdd-HHmmss"
$LogRoot = Join-Path $ProjectRoot "Saved\CI\Logs"
$LogPath = Join-Path $LogRoot "PackageAndUploadSteam-$Timestamp.log"
New-Item -ItemType Directory -Force -Path $LogRoot | Out-Null

$ScriptExitCode = 1
$TranscriptStarted = $false
try {
    Start-Transcript -Path $LogPath -Force | Out-Null
    $TranscriptStarted = $true

    $RunUAT = Get-RequiredPath `
        -Name "RunUAT.bat" `
        -EnvironmentVariable "UE_RUNUAT" `
        -Candidates @(
            $env:UE_RUNUAT,
            "C:\Program Files\Epic Games\UE_$EngineAssociation\Engine\Build\BatchFiles\RunUAT.bat",
            "C:\Program Files\Epic Games\UE_5.6\Engine\Build\BatchFiles\RunUAT.bat"
        )

    $SteamCMD = Get-RequiredPath `
        -Name "steamcmd.exe" `
        -EnvironmentVariable "STEAMCMD_EXE" `
        -Candidates @(
            $env:STEAMCMD_EXE,
            "C:\Program Files (x86)\Steam\steamworks_sdk_164\sdk\tools\ContentBuilder\builder\steamcmd.exe",
            "C:\Program Files (x86)\Steam\steamcmd.exe"
        )

    $SteamAppId = if ($env:STEAM_APP_ID) { $env:STEAM_APP_ID } else { "4927910" }
    $SteamDepotId = if ($env:STEAM_DEPOT_ID) { $env:STEAM_DEPOT_ID } else { "4927911" }
    $SteamUsername = if ($env:STEAM_USERNAME) { $env:STEAM_USERNAME } else { "davr547" }

    $BranchName = (& git -C $ProjectRoot rev-parse --abbrev-ref HEAD).Trim()
    Assert-NativeSuccess "Failed to detect the current Git branch."

    $CommitHash = (& git -C $ProjectRoot rev-parse --short HEAD).Trim()
    Assert-NativeSuccess "Failed to detect the current Git commit."

    $SteamBranch = Get-SteamBranchForGitBranch -BranchName $BranchName

    $GitStatus = & git -C $ProjectRoot status --porcelain
    Assert-NativeSuccess "Failed to check Git working tree state."

    if ($GitStatus -and -not $AllowDirtyWorkingTree) {
        $StatusText = $GitStatus -join [Environment]::NewLine
        throw "Working tree has uncommitted changes. Commit or stash before uploading, or rerun with -AllowDirtyWorkingTree.$([Environment]::NewLine)$StatusText"
    }

    if (-not $SkipBranchConfirmation) {
        $BranchConfirmation = Read-Host "Upload Git branch '$BranchName' to Steam branch '$SteamBranch'? Type Y to continue"
        if ($BranchConfirmation -notin @("Y", "y", "Yes", "yes")) {
            throw "Cancelled before packaging."
        }
    }

    if ($SteamBranch -eq "default" -and -not $SkipLiveConfirmation) {
        $Confirmation = Read-Host "Type UPLOAD DEFAULT to package Git branch '$BranchName' and upload to Steam default"
        if ($Confirmation -ne "UPLOAD DEFAULT") {
            throw "Cancelled before Steam default upload."
        }
    }

    if ($WaitForProcessId -gt 0) {
        $ProcessToWaitFor = Get-Process -Id $WaitForProcessId -ErrorAction SilentlyContinue
        if ($ProcessToWaitFor) {
            Write-Host "Waiting for process $WaitForProcessId ($($ProcessToWaitFor.ProcessName)) to exit before packaging..."
            Write-Host "Close Unreal Editor when you are ready to continue."
            Wait-Process -Id $WaitForProcessId
            Write-Host "Process $WaitForProcessId has exited."
            Write-Host ""
        }
    }

    $SteamPackageRoot = Join-Path $ProjectRoot "Saved\CI\SteamPackage"
    $OutputRoot = Join-Path $SteamPackageRoot "$Timestamp-$BranchName-$CommitHash"
    $PackageOut = Join-Path $OutputRoot $Platform
    $SteamPipeOut = Join-Path $ProjectRoot "Saved\CI\SteamPipeOutput"
    $TempVdf = Join-Path $ProjectRoot "Saved\CI\steam_app_build_$Timestamp.vdf"

    if (Test-Path -LiteralPath $PackageOut) {
        Remove-Item -LiteralPath $PackageOut -Recurse -Force
    }

    New-Item -ItemType Directory -Force -Path $PackageOut | Out-Null
    New-Item -ItemType Directory -Force -Path $SteamPipeOut | Out-Null

    Write-Host "Project: $ProjectFile"
    Write-Host "Git branch: $BranchName"
    Write-Host "Steam branch: $SteamBranch"
    Write-Host "Commit: $CommitHash"
    Write-Host "Configuration: $Configuration"
    Write-Host "Package output: $PackageOut"
    Write-Host "Log: $LogPath"
    Write-Host ""

    $UatArgs = @(
        "BuildCookRun",
        "-project=$ProjectFile",
        "-target=$GameTarget",
        "-platform=$Platform",
        "-clientconfig=$Configuration",
        "-build",
        "-cook",
        "-stage",
        "-pak",
        "-archive",
        "-archivedirectory=$PackageOut",
        "-prereqs",
        "-nodebuginfo",
        "-NoP4",
        "-utf8output"
    )

    & $RunUAT @UatArgs
    Assert-NativeSuccess "Unreal packaging failed."

    $Exe = Get-ChildItem -LiteralPath $PackageOut -Recurse -File -Filter "$GameTarget.exe" | Select-Object -First 1
    if (-not $Exe) {
        $Exe = Get-ChildItem -LiteralPath $PackageOut -Recurse -File -Filter "*.exe" |
            Where-Object { $_.Name -notlike "*Prereq*" } |
            Select-Object -First 1
    }

    if (-not $Exe) {
        throw "No game EXE found in packaged output."
    }

    $PakOrUcas = Get-ChildItem -LiteralPath $PackageOut -Recurse -File |
        Where-Object { $_.Extension -in @(".pak", ".ucas") } |
        Select-Object -First 1

    if (-not $PakOrUcas) {
        throw "No .pak or .ucas files found. Package looks incomplete."
    }

    $FileCount = (Get-ChildItem -LiteralPath $PackageOut -Recurse -File).Count
    if ($FileCount -lt 20) {
        throw "Only $FileCount files found. Package looks malformed."
    }

    Write-Host "Package validation passed."
    Write-Host "EXE found: $($Exe.FullName)"
    Write-Host ""

    $PreviewValue = if ($Preview) { "1" } else { "0" }
    $SetLiveBranch = if ($SteamBranch -eq "default") { "" } else { $SteamBranch }
    $Vdf = @"
"AppBuild"
{
    "AppID" "$SteamAppId"
    "Desc" "Auto upload from $BranchName commit $CommitHash"
    "Verbose" "1"
    "Preview" "$PreviewValue"
    "SetLive" "$SetLiveBranch"

    "ContentRoot" "$PackageOut"
    "BuildOutput" "$SteamPipeOut"

    "Depots"
    {
        "$SteamDepotId"
        {
            "FileMapping"
            {
                "LocalPath" "*"
                "DepotPath" "."
                "Recursive" "1"
            }

            "FileExclusion" "*.pdb"
            "FileExclusion" "*.log"
            "FileExclusion" "Saved\*"
            "FileExclusion" "Intermediate\*"
        }
    }
}
"@

    $Vdf | Set-Content -Path $TempVdf -Encoding ASCII
    Write-Host "Generated Steam build script: $TempVdf"
    if ($SteamBranch -eq "default") {
        Write-Host "Steam default builds cannot be set live automatically; set this build live in Steamworks after upload."
    }

    if ($SkipUpload) {
        Write-Host "Skipping Steam upload because -SkipUpload was supplied."
    }
    else {
        $SteamArgs = @("+login", $SteamUsername, "+run_app_build", $TempVdf, "+quit")
        & $SteamCMD @SteamArgs
        Assert-NativeSuccess "Steam upload failed."

        Remove-Item -LiteralPath $TempVdf -Force -ErrorAction SilentlyContinue
        Write-Host ""
        Write-Host "Done. Uploaded $BranchName / $CommitHash to Steam branch '$SteamBranch'."

        if ($ArchivePackage) {
            Write-Host "Archived package kept at: $OutputRoot"
        }
        elseif ($Preview) {
            Write-Host "Steam preview mode was enabled; package kept at: $OutputRoot"
        }
        else {
            Write-Host "Deleting local packaged build after successful Steam upload: $OutputRoot"
            Remove-PackageArchive -OutputRoot $OutputRoot -SteamPackageRoot $SteamPackageRoot
        }
    }

    $ScriptExitCode = 0
}
catch {
    Write-Host ""
    Write-Host "ERROR: $($_.Exception.Message)" -ForegroundColor Red
    $ScriptExitCode = 1
}
finally {
    if ($TranscriptStarted) {
        Stop-Transcript | Out-Null
        Write-Host "Transcript saved to $LogPath"
    }
}

exit $ScriptExitCode
