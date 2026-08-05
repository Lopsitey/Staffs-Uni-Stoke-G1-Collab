// Fill out your copyright notice in the Description page of Project Settings.


#include "ChapterControlWorldSubsystem.h"

#include "Kismet/GameplayStatics.h"

#include "Engine/LevelStreaming.h"
#include "Engine/PostProcessVolume.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "HAL/IConsoleManager.h"
#include "Misc/FileHelper.h"
#include "Misc/PackageName.h"
#include "Misc/Paths.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstance.h"

namespace
{
	// #region agent log
	static void AgentFogDebugDump(UWorld* World, const TCHAR* Phase)
	{
		if (!World)
		{
			return;
		}

		auto GetCVarInt = [](const TCHAR* Name) -> int32
		{
			if (IConsoleVariable* Var = IConsoleManager::Get().FindConsoleVariable(Name))
			{
				return Var->GetInt();
			}
			return -1;
		};

		const int32 SeparateTranslucency = GetCVarInt(TEXT("r.SeparateTranslucency"));
		const int32 SceneDepthAux = GetCVarInt(TEXT("r.Mobile.SceneDepthAux"));
		const int32 MobileAA = GetCVarInt(TEXT("r.Mobile.AntiAliasing"));
		const ERHIFeatureLevel::Type WorldFL = World->GetFeatureLevel();
		const TCHAR* FeatureLevel =
			(WorldFL <= ERHIFeatureLevel::ES3_1) ? TEXT("ES3_1") :
			(WorldFL == ERHIFeatureLevel::SM5) ? TEXT("SM5") : TEXT("SM6");
		const TCHAR* RunId = (SeparateTranslucency == 0) ? TEXT("post-fix") : TEXT("pre-fix");

		int32 PPVCount = 0;
		int32 FogBlendableCount = 0;
		float MaxFogWeight = 0.f;
		FString FogParamSummary;

		for (TActorIterator<APostProcessVolume> It(World); It; ++It)
		{
			++PPVCount;
			for (const FWeightedBlendable& Blendable : It->Settings.WeightedBlendables.Array)
			{
				UObject* Obj = Blendable.Object;
				if (!Obj || !Obj->GetName().Contains(TEXT("Fog")))
				{
					continue;
				}
				++FogBlendableCount;
				MaxFogWeight = FMath::Max(MaxFogWeight, Blendable.Weight);

				if (UMaterialInterface* Mat = Cast<UMaterialInterface>(Obj))
				{
					TArray<FMaterialParameterInfo> Infos;
					TArray<FGuid> Ids;
					Mat->GetAllScalarParameterInfo(Infos, Ids);
					for (int32 i = 0; i < Infos.Num(); ++i)
					{
						float Value = 0.f;
						Mat->GetScalarParameterValue(Infos[i], Value);
						FogParamSummary += FString::Printf(TEXT("%s=%.3f;"), *Infos[i].Name.ToString(), Value);
					}
				}
			}
		}

		FogParamSummary.ReplaceInline(TEXT("\""), TEXT("'"));

		const FString Data = FString::Printf(
			TEXT("{\"phase\":\"%s\",\"worldFeatureLevel\":\"%s\",\"globalFeatureLevel\":\"%s\",\"MobileAntiAliasing\":%d,\"SeparateTranslucency\":%d,\"SceneDepthAux\":%d,\"SupportLocalFogVolumes\":%d,\"ppvCount\":%d,\"fogBlendableCount\":%d,\"maxFogWeight\":%.3f,\"fogScalars\":\"%s\",\"map\":\"%s\"}"),
			Phase,
			FeatureLevel,
			(GMaxRHIFeatureLevel <= ERHIFeatureLevel::ES3_1) ? TEXT("ES3_1") :
			(GMaxRHIFeatureLevel == ERHIFeatureLevel::SM5) ? TEXT("SM5") : TEXT("SM6"),
			MobileAA,
			SeparateTranslucency,
			SceneDepthAux,
			GetCVarInt(TEXT("r.SupportLocalFogVolumes")),
			PPVCount,
			FogBlendableCount,
			MaxFogWeight,
			*FogParamSummary,
			*World->GetMapName());

		const int64 Timestamp = FDateTime::UtcNow().ToUnixTimestamp() * 1000;
		const FString Line = FString::Printf(
			TEXT("{\"sessionId\":\"ed81bc\",\"runId\":\"%s\",\"hypothesisId\":\"D\",\"location\":\"ChapterControlWorldSubsystem.cpp\",\"message\":\"Fog debug dump\",\"data\":%s,\"timestamp\":%lld}\n"),
			RunId,
			*Data,
			Timestamp);

		FFileHelper::SaveStringToFile(Line, *FPaths::Combine(FPaths::ProjectDir(), TEXT("debug-ed81bc.log")), FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM, &IFileManager::Get(), FILEWRITE_Append);
		FFileHelper::SaveStringToFile(Line, *FPaths::Combine(FPaths::ProjectLogDir(), TEXT("debug-ed81bc.log")), FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM, &IFileManager::Get(), FILEWRITE_Append);
		UE_LOG(LogTemp, Warning, TEXT("[FogDebug][D] %s | %s"), Phase, *Data);
	}
	// #endregion
}

void UChapterControlWorldSubsystem::SetChapterData(UDA_ChapterData* inData)
{
	ChapterData = inData;
}

bool UChapterControlWorldSubsystem::LoadLevel(int index, FName LevelName = NAME_None)
{
	if (ChapterData == nullptr)
		return false;
	
	if (LevelName != NAME_None && ChapterData->LevelNameArray.FindByKey(LevelName))
	{
		UE_LOG(
		  LogTemp,
		  Warning,
		  TEXT("Load Level - Attempted To Load: %s"),
		  *LevelName.ToString()
		);
		// #region agent log
		AgentFogDebugDump(GetWorld(), TEXT("LoadLevel"));
		// #endregion
		ULevelStreaming* Level = UGameplayStatics::GetStreamingLevel(this,LevelName);
		if (Level == nullptr) {return false;}

		Level->SetShouldBeLoaded(true);
		Level->SetShouldBeVisible(true);
		Level->OnLevelLoaded.AddDynamic(this, &UChapterControlWorldSubsystem::CallLevelLoaded);
		lastUsedLevelIndex = index;
		return true;
	}
	
	else if (ChapterData->LevelNameArray.IsValidIndex(index))
	{
		ULevelStreaming* Level = UGameplayStatics::GetStreamingLevel(this,ChapterData->LevelNameArray[index]);
		if (Level == nullptr) {return false;}

		Level->SetShouldBeLoaded(true);
		Level->SetShouldBeVisible(true);
		Level->OnLevelLoaded.AddDynamic(this, &UChapterControlWorldSubsystem::CallLevelLoaded);
		lastUsedLevelIndex = index;
		return true;
	}else
	{
		return false;
	}
}

bool UChapterControlWorldSubsystem::UnloadLevel(int index)
{
	
	if (ChapterData == nullptr)
	{
		return false;
	}

	if (ChapterData->LevelNameArray.IsValidIndex(index))
	{
		ULevelStreaming* Level = UGameplayStatics::GetStreamingLevel(this,ChapterData->LevelNameArray[index]);
		if (Level == nullptr) {return false;}

		Level->SetShouldBeLoaded(false);
		Level->SetShouldBeVisible(false);
		lastUsedLevelIndex = index;
		return true;
	}
	else
	{
		return false;
	}

	
}

void UChapterControlWorldSubsystem::CallLevelLoaded()
{
	OnLevelLoaded.Broadcast();

	// #region agent log
	AgentFogDebugDump(GetWorld(), TEXT("LevelLoaded"));
	// #endregion

	GetWorld()->GetStreamingLevels()[lastUsedLevelIndex]->OnLevelLoaded.RemoveAll(this);
}

bool UChapterControlWorldSubsystem::TryGetOnlyVisibleSublevelName(
	FName& OutLevelName) const
{
	OutLevelName = NAME_None;

#if WITH_EDITOR
	const UWorld* EditorWorld = GetWorld();
	
	if (!IsValid(EditorWorld))
		return false;

   // This function is intended to inspect the level-editor world,
    // or than a PIE world - mainly anything that's not a packaged game.
	if (EditorWorld->WorldType != EWorldType::Editor &&
	 EditorWorld->WorldType != EWorldType::PIE)
	{
		return false;
	}
        
    const ULevelStreaming* OnlyVisibleLevel = nullptr;
    for (const ULevelStreaming* StreamingLevel :
         EditorWorld->GetStreamingLevels())
    {
    	//skips if invalid
        if (!IsValid(StreamingLevel))
            continue;
            
        // Only consider ordinary sublevels represented in
        // the editor's Levels collection.
        if (!StreamingLevel->ShowInLevelCollection())
            continue;
    	
        if (!StreamingLevel->GetShouldBeVisibleInEditor())
            continue;

        //stops if a visible level was already found - ensures it only ever finds one in the loop
          if (OnlyVisibleLevel != nullptr)
        {
            UE_LOG(
                LogTemp,
                Warning,
                TEXT("More than one visible sublevel: %s and %s"),
                *OnlyVisibleLevel->GetWorldAssetPackageName(),
                *StreamingLevel->GetWorldAssetPackageName()
            );

            return false;
        }

        OnlyVisibleLevel = StreamingLevel;
    }

	//stops if no levels were found
    if (OnlyVisibleLevel == nullptr)
        return false;
        
        FString PackageName =
        OnlyVisibleLevel->GetWorldAssetPackageName();

	
    PackageName = UWorld::RemovePIEPrefix(PackageName);

    OutLevelName = FName(
        *FPackageName::GetShortName(PackageName)
    );

    UE_LOG(
        LogTemp,
        Warning,
        TEXT("Only visible sublevel: %s"),
        *OutLevelName.ToString()
    );

    return true;
#else
    return false;//do nothing if not in editor
#endif
}