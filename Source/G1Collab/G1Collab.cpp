// Fill out your copyright notice in the Description page of Project Settings.

#include "G1Collab.h"
#include "Misc/CommandLine.h"
#include "Misc/CoreDelegates.h"
#include "Misc/Parse.h"
#include "Modules/ModuleManager.h"

class FG1CollabGameModule final : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override
	{
		FDefaultGameModuleImpl::StartupModule();

		// Deliberately crash only when QA explicitly launches a packaged build with this flag.
		if (FParse::Param(FCommandLine::Get(), TEXT("STTSVerifyCrashReporter")))
		{
			FCoreDelegates::OnFEngineLoopInitComplete.AddLambda([]
			{
				UE_LOG(LogTemp, Fatal, TEXT("Intentional Steps to the Stars crash reporter verification."));
			});
		}
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FG1CollabGameModule, G1Collab, "G1Collab");
