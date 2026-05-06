// Fill out your copyright notice in the Description page of Project Settings.


#include "ChapterControlWorldSubsystem.h"

#include "Kismet/GameplayStatics.h"

bool UChapterControlWorldSubsystem::LoadLevel(int index)
{
	TArray<ULevelStreaming*> Levels = GetWorld()->GetStreamingLevels();
	if (GetWorld()->GetStreamingLevels().IsValidIndex(index))
	{
		Levels[index]->SetShouldBeLoaded(true);
		Levels[index]->SetShouldBeVisible(true);
		Levels[index]->OnLevelLoaded.AddDynamic(this, &UChapterControlWorldSubsystem::CallLevelLoaded);
		lastUsedLevelIndex = index;
		return true;
	}
	else
	{
		return false;
	}
}

bool UChapterControlWorldSubsystem::UnloadLevel(int index)
{
	TArray<ULevelStreaming*> Levels = GetWorld()->GetStreamingLevels();
	if (Levels.IsValidIndex(index))
	{
		Levels[index]->SetShouldBeLoaded(false);
		Levels[index]->SetShouldBeVisible(false);
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

