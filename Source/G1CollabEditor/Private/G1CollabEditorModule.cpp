#include "Modules/ModuleManager.h"

#include "Framework/Commands/UIAction.h"
#include "Framework/Application/SlateApplication.h"
#include "HAL/PlatformProcess.h"
#include "Misc/MessageDialog.h"
#include "Misc/Paths.h"
#include "Styling/AppStyle.h"
#include "ToolMenus.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SWindow.h"
#include "Widgets/Text/STextBlock.h"

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
	enum class ESteamUploadChoice
	{
		Cancel,
		UploadAndDeletePackage,
		UploadAndArchivePackage
	};

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
			OutSteamBranch = TEXT("developer");
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

	static bool TryGetGitWorkingTreeStatus(FString& OutStatus, FString& OutError)
	{
		const FString ProjectPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
		const FString GitArgs = FString::Printf(
			TEXT("-C \"%s\" status --porcelain"),
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
				OutError = LOCTEXT("GitStatusUnknownError", "Git did not return the working tree status.").ToString();
			}

			return false;
		}

		OutStatus = StdOut.TrimStartAndEnd();
		return true;
	}

	static ESteamUploadChoice OpenSteamUploadPrompt(const FString& GitBranch, const FString& SteamBranch)
	{
		ESteamUploadChoice Choice = ESteamUploadChoice::Cancel;

		TSharedRef<SWindow> DialogWindow = SNew(SWindow)
			.Title(LOCTEXT("ConfirmPackageAndUploadSteamTitle", "Package and Upload to Steam"))
			.SizingRule(ESizingRule::Autosized)
			.AutoCenter(EAutoCenter::PreferredWorkArea)
			.SupportsMinimize(false)
			.SupportsMaximize(false);

		const FText Message = FText::Format(
			LOCTEXT(
				"ConfirmPackageAndUploadSteam",
				"Git branch:\n{0}\n\nSteam branch:\n{1}\n\nThis will open a packaging console. The console will wait until you close Unreal Editor, then package the project and upload to Steam.\n\nSave any dirty assets before continuing.\n\nYes uploads to Steam and deletes the local packaged build from Saved after SteamCMD succeeds.\n\nYes and archive uploads to Steam and keeps the packaged build under Saved/CI/SteamPackage.\n\nContinue?"),
			FText::FromString(GitBranch),
			FText::FromString(SteamBranch));

		DialogWindow->SetContent(
			SNew(SBorder)
			.BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
			.Padding(18.0f)
			[
				SNew(SVerticalBox)

				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.0f, 0.0f, 0.0f, 18.0f)
				[
					SNew(STextBlock)
					.Text(Message)
					.AutoWrapText(true)
					.WrapTextAt(760.0f)
				]

				+ SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Right)
				[
					SNew(SHorizontalBox)

					+ SHorizontalBox::Slot()
					.AutoWidth()
					.Padding(0.0f, 0.0f, 8.0f, 0.0f)
					[
						SNew(SButton)
						.Text(LOCTEXT("PackageAndUploadYes", "Yes"))
						.ContentPadding(FAppStyle::GetMargin("StandardDialog.ContentPadding"))
						.OnClicked_Lambda([&Choice, DialogWindow]()
						{
							Choice = ESteamUploadChoice::UploadAndDeletePackage;
							DialogWindow->RequestDestroyWindow();
							return FReply::Handled();
						})
					]

					+ SHorizontalBox::Slot()
					.AutoWidth()
					.Padding(0.0f, 0.0f, 8.0f, 0.0f)
					[
						SNew(SButton)
						.Text(LOCTEXT("PackageAndUploadArchive", "Yes and archive"))
						.ContentPadding(FAppStyle::GetMargin("StandardDialog.ContentPadding"))
						.OnClicked_Lambda([&Choice, DialogWindow]()
						{
							Choice = ESteamUploadChoice::UploadAndArchivePackage;
							DialogWindow->RequestDestroyWindow();
							return FReply::Handled();
						})
					]

					+ SHorizontalBox::Slot()
					.AutoWidth()
					[
						SNew(SButton)
						.Text(LOCTEXT("PackageAndUploadNo", "No"))
						.ContentPadding(FAppStyle::GetMargin("StandardDialog.ContentPadding"))
						.OnClicked_Lambda([&Choice, DialogWindow]()
						{
							Choice = ESteamUploadChoice::Cancel;
							DialogWindow->RequestDestroyWindow();
							return FReply::Handled();
						})
					]
				]
			]);

		FSlateApplication::Get().AddModalWindow(DialogWindow, nullptr);
		return Choice;
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

		FString GitStatus;
		FString GitStatusError;
		if (!TryGetGitWorkingTreeStatus(GitStatus, GitStatusError))
		{
			FMessageDialog::Open(
				EAppMsgType::Ok,
				FText::Format(
					LOCTEXT("GitStatusError", "Could not check the Git working tree, so nothing was packaged or uploaded.\n\n{0}"),
					FText::FromString(GitStatusError)));
			return;
		}

		if (!GitStatus.IsEmpty())
		{
			FMessageDialog::Open(
				EAppMsgType::Ok,
				FText::Format(
					LOCTEXT("DirtyGitWorkingTree", "Working tree has uncommitted changes. Commit or stash before uploading.\n\n{0}\n\nNothing was packaged or uploaded."),
					FText::FromString(GitStatus)));
			return;
		}

		const ESteamUploadChoice UploadChoice = OpenSteamUploadPrompt(GitBranch, SteamBranch);
		if (UploadChoice == ESteamUploadChoice::Cancel)
		{
			return;
		}

		const FString LauncherArgs = FString::Printf(
			TEXT("-WaitForProcessId %u -SkipBranchConfirmation%s"),
			FPlatformProcess::GetCurrentProcessId(),
			UploadChoice == ESteamUploadChoice::UploadAndArchivePackage ? TEXT(" -ArchivePackage") : TEXT(""));

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
