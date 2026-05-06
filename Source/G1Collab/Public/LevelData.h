// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "LevelData.generated.h"

USTRUCT(BlueprintType,Blueprintable)
struct FLevelCellData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector2D cellPosition = FVector2D::ZeroVector;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FGameplayTagContainer cellTags = FGameplayTagContainer();


	
};

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class G1COLLAB_API ULevelDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FLevelCellData> cellData;
};
