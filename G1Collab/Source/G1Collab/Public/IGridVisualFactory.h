// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IGridVisualFactory.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI,Blueprintable)
class UIGridVisualFactory : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class G1COLLAB_API IIGridVisualFactory
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateVisualCell(FVector2D Cellpos);
	virtual void UpdateVisualCell_Implementation(FVector2D){};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ConstructVisualCells(const TMap<FVector2D,UObject*>& gridData);
	virtual void ConstructVisualCells_Implementation(const TMap<FVector2D,UObject*>& gridData){};
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

};
