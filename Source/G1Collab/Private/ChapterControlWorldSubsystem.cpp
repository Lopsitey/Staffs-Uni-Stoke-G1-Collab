// Fill out your copyright notice in the Description page of Project Settings.


#include "ChapterControlWorldSubsystem.h"

#include "Kismet/GameplayStatics.h"

void UChapterControlWorldSubsystem::SetChapterData(UDA_ChapterData* inData)
{
	ChapterData = inData;
}

bool UChapterControlWorldSubsystem::LoadLevel(int index)
{

	if (ChapterData == nullptr)
	{
		return false;
	}

	if (ChapterData->LevelNameArray.IsValidIndex(index))
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

