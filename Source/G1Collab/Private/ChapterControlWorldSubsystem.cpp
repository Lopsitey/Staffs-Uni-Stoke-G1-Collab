// Fill out your copyright notice in the Description page of Project Settings.


#include "ChapterControlWorldSubsystem.h"

#include "Kismet/GameplayStatics.h"

#include "Engine/LevelStreaming.h"
#include "Engine/World.h"
#include "Misc/PackageName.h"

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