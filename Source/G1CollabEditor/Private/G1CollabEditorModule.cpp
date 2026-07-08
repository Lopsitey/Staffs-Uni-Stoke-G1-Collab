#include "Modules/ModuleManager.h"

#include "Framework/Commands/UIAction.h"
#include "HAL/PlatformProcess.h"
#include "Misc/MessageDialog.h"
#include "Misc/Paths.h"
#include "ToolMenus.h"

#define LOCTEXT_NAMESPACE "FG1CollabEditorModule"

class FG1CollabEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override
	{
		UToolMenus::RegisterStartupCallback(
			FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FG1CollabEditorModule::RegisterMenus));
	}

	virtual void ShutdownModule() override
	{
		UToolMenus::UnRegisterStartupCallback(this);
		UToolMenus::UnregisterOwner(this);
	}

private:
	static bool TryMapGitBranchToSteamBranch(const FString& GitBranch, FString& OutSteamBranch)
	{
		const FString LowerBranch = GitBranch.ToLower();
		if (LowerBranch.Contains(TEXT("live")))
		{
			OutSteamBranch = TEXT("default");
			return true;
		}

		if (LowerBranch.Contains(TEXT("beta")))
		{
			OutSteamBranch = TEXT("beta");
			return true;
		}

		if (LowerBranch.Contains(TEXT("dev")))
		{
			OutSteamBranch = TEXT("dev");
			return true;
		}

		return false;
	}

	static bool TryGetCurrentGitBranch(FString& OutGitBranch, FString& OutError)
	{
		const FString ProjectPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
		const FString GitArgs = FString::Printf(
			TEXT("-C \"%s\" rev-parse --abbrev-ref HEAD"),
			*ProjectPath);

		int32 ReturnCode = 0;
		FString StdOut;
		FString StdErr;
		const bool bStarted = FPlatformProcess::ExecProcess(
			TEXT("git"),
			*GitArgs,
			&ReturnCode,
			&StdOut,
			&StdErr);

		if (!bStarted || ReturnCode != 0)
		{
			OutError = StdErr.TrimStartAndEnd();
			if (OutError.IsEmpty())
			{
				OutError = LOCTEXT("GitBranchUnknownError", "Git did not return a branch name.").ToString();
			}

			return false;
		}

		OutGitBranch = StdOut.TrimStartAndEnd();
		if (OutGitBranch.IsEmpty())
		{
			OutError = LOCTEXT("GitBranchEmptyError", "Git returned an empty branch name.").ToString();
			return false;
		}

		return true;
	}

	void RegisterMenus()
	{
		FToolMenuOwnerScoped OwnerScoped(this);

		UToolMenu* ToolsMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Tools");
		FToolMenuSection& Section = ToolsMenu->FindOrAddSection("G1CollabBuild");
		Section.Label = LOCTEXT("G1CollabBuildSection", "G1 Collab");

		Section.AddMenuEntry(
			"G1CollabPackageAndUploadSteam",
			LOCTEXT("PackageAndUploadSteamLabel", "Package and Upload to Steam"),
			LOCTEXT("PackageAndUploadSteamTooltip", "Packages the current Git branch and uploads it to the mapped Steam branch."),
			FSlateIcon(),
			FUIAction(FExecuteAction::CreateStatic(&FG1CollabEditorModule::LaunchSteamUploadScript)));
	}

	static void LaunchSteamUploadScript()
	{
#if PLATFORM_WINDOWS
		const FString LauncherPath = FPaths::ConvertRelativePathToFull(
			FPaths::ProjectDir() / TEXT("BuildScripts/PackageAndUploadSteam.cmd"));

		if (!FPaths::FileExists(LauncherPath))
		{
			FMessageDialog::Open(
				EAppMsgType::Ok,
				FText::Format(
					LOCTEXT("MissingSteamUploadLauncher", "Could not find the Steam upload launcher:\n{0}"),
					FText::FromString(LauncherPath)));
			return;
		}

		FString GitBranch;
		FString GitError;
		if (!TryGetCurrentGitBranch(GitBranch, GitError))
		{
			FMessageDialog::Open(
				EAppMsgType::Ok,
				FText::Format(
					LOCTEXT("GitBranchError", "Could not detect the current Git branch, so nothing was packaged or uploaded.\n\n{0}"),
					FText::FromString(GitError)));
			return;
		}

		FString SteamBranch;
		if (!TryMapGitBranchToSteamBranch(GitBranch, SteamBranch))
		{
			FMessageDialog::Open(
				EAppMsgType::Ok,
				FText::Format(
					LOCTEXT("InvalidSteamUploadBranch", "Current Git branch '{0}' is not valid for Steam upload.\n\nUse a branch name containing dev, beta, or live.\n\nNothing was packaged or uploaded."),
					FText::FromString(GitBranch)));
			return;
		}

		const EAppReturnType::Type Result = FMessageDialog::Open(
			EAppMsgType::YesNo,
			FText::Format(
				LOCTEXT(
					"ConfirmPackageAndUploadSteam",
					"Git branch:\n{0}\n\nSteam branch:\n{1}\n\nThis will open a packaging console. The console will wait until you close Unreal Editor, then package the project and upload to Steam.\n\nSave any dirty assets before continuing.\n\nContinue?"),
				FText::FromString(GitBranch),
				FText::FromString(SteamBranch)));

		if (Result != EAppReturnType::Yes)
		{
			return;
		}

		const FString LauncherArgs = FString::Printf(
			TEXT("-WaitForProcessId %u -SkipBranchConfirmation"),
			FPlatformProcess::GetCurrentProcessId());

		if (!FPlatformProcess::LaunchFileInDefaultExternalApplication(*LauncherPath, *LauncherArgs, ELaunchVerb::Open))
		{
			FMessageDialog::Open(
				EAppMsgType::Ok,
				FText::Format(
					LOCTEXT("FailedToLaunchSteamUpload", "Windows could not open the Steam upload launcher:\n{0}"),
					FText::FromString(LauncherPath)));
			return;
		}
#else
		FMessageDialog::Open(
			EAppMsgType::Ok,
			LOCTEXT("SteamUploadWindowsOnly", "Steam packaging/upload launcher is currently configured for Windows only."));
#endif
	}
};

IMPLEMENT_MODULE(FG1CollabEditorModule, G1CollabEditor)

#undef LOCTEXT_NAMESPACE
