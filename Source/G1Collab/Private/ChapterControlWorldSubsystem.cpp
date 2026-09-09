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
	}
	return false;
}

bool UChapterControlWorldSubsystem::UnloadLevel(const int Index)
{
	if (ChapterData == nullptr || ChapterData->LevelNameArray.IsValidIndex(Index) == false) 
		return false;
	
	ULevelStreaming* Level = UGameplayStatics::GetStreamingLevel(this,ChapterData->LevelNameArray[Index]);
	if (Level == nullptr) return false;

	Level->SetShouldBeLoaded(false);
	Level->SetShouldBeVisible(false);
	lastUsedLevelIndex = Index;
	return true;
}

void UChapterControlWorldSubsystem::CallLevelLoaded()
{
	OnLevelLoaded.Broadcast();

	GetWorld()->GetStreamingLevels()[lastUsedLevelIndex]->OnLevelLoaded.RemoveAll(this);
}

//If only one sublevel is visible - Outputs the name and index of the chapter-data. 
///@returns True if exactly one visible sublevel is found, false otherwise.
bool UChapterControlWorldSubsystem::TryGetOnlyVisibleSublevel(FName& OutLevelName, int32& OutLevelIndex) const
{
	OutLevelName = NAME_None;
	OutLevelIndex = INDEX_NONE;

#if WITH_EDITOR
	const UWorld* EditorWorld = GetWorld();

	if (!IsValid(EditorWorld))
		return false;

	// This helper is editor-focused and should not run for non-editor world types.
	if (EditorWorld->WorldType != EWorldType::Editor &&
		EditorWorld->WorldType != EWorldType::PIE)
	{
		return false;
	}

	const TArray<ULevelStreaming*>& StreamingLevels = EditorWorld->GetStreamingLevels();
	const ULevelStreaming* OnlyVisibleLevel = nullptr;

	for (const ULevelStreaming* StreamingLevel : StreamingLevels)
	{
		// Skip invalid streaming entries.
		if (!IsValid(StreamingLevel))
			continue;

		// Only consider sublevels represented in the editor's Levels collection.
		if (!StreamingLevel->ShowInLevelCollection())
			continue;

		// Only consider levels currently visible in the editor.
		if (!StreamingLevel->GetShouldBeVisibleInEditor())
			continue;

		// Enforce exactly one visible sublevel.
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

	if (OnlyVisibleLevel == nullptr)
		return false;

	// Convert package path to level name.
	FString PackageName = OnlyVisibleLevel->GetWorldAssetPackageName();
	PackageName = UWorld::RemovePIEPrefix(PackageName);

	OutLevelName = FName(*FPackageName::GetShortName(PackageName));

	// Gets the index from chapter data ordering instead of streaming-level iteration order.
	if (ChapterData == nullptr)
		return false;

	OutLevelIndex = ChapterData->LevelNameArray.IndexOfByKey(OutLevelName);
	return OutLevelIndex != INDEX_NONE;
#else
	return false;
#endif
}
