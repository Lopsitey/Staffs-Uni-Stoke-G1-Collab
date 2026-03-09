// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPCell.h"
#include "UObject/NoExportTypes.h"
#include "UGridDataFactory.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class G1COLLAB_API UUGridDataFactory : public UActorComponent
{
	GENERATED_BODY()
	
	void BeginPlay() override;
	UFUNCTION()
	void ConstructGrid(UObject* Leveldata);
	public:
	UFUNCTION()
	UObject* RetrieveCellInformation(FVector2D key) {return *cellInformation.Find(key);}
	UPROPERTY(blueprintreadwrite)
	TMap<FVector2D,UObject*> cellInformation;
	
};
