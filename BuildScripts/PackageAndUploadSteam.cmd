@echo off
setlocal

cd /d "%~dp0.."

powershell.exe -NoProfile -ExecutionPolicy Bypass -File "%~dp0PackageAndUploadSteam.ps1" %*
set "EXIT_CODE=%ERRORLEVEL%"

echo.
if "%EXIT_CODE%"=="0" (
    echo Package/upload completed successfully.
) else (
    echo Package/upload failed with exit code %EXIT_CODE%.
)

pause
exit /b %EXIT_CODE%
