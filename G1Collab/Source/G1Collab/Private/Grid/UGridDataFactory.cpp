// Fill out your copyright notice in the Description page of Project Settings.


#include "G1Collab/Public/Grid/UGridDataFactory.h"

#include "GameplayTagsManager.h"


void UUGridDataFactory::BeginPlay()
{
	
	ConstructGrid(nullptr);
	Super::BeginPlay();
}

void UUGridDataFactory::ConstructGrid(UObject* Leveldata)
{
	
	for (int x = 0; x <= 2; x++){

		for (int y = 0; y <= 2; y++)
		{
			
			FGameplayTagContainer cellTag = FGameplayTagContainer();
			if (FMath::RandBool())
			{
				cellTag.AddTag(UGameplayTagsManager::Get().RequestGameplayTag("cellTag.Floor"));
			}
			else
			{
				cellTag.AddTag(UGameplayTagsManager::Get().RequestGameplayTag("cellTag.Empty"));
				cellTag.AddTag(UGameplayTagsManager::Get().RequestGameplayTag("cellTag.State.Shadow"));
			}			UCPPCell* cell = NewObject<UCPPCell>();
			cell->UpdateCell_Implementation(cellTag);
			
			cellInformation.Add(FVector2D(x,y),cell);
			
		}
	}
	
}
