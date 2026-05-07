// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/SoftWorldReference.h"
#include "DA_ChapterData.generated.h"

/**
 * 
 */
UCLASS()
class G1COLLAB_API UDA_ChapterData : public UPrimaryDataAsset
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	TSoftObjectPtr<UTexture2D> LoadScreenTexture;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	FSoftWorldReference Chapter;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	FSoftWorldReference NextChapter;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	FName ChapterName;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Data")
	TArray<FName> LevelNameArray;
};
