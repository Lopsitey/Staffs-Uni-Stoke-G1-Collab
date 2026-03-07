// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ICell.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCellUpdateSig);
// This class does not need to be modified.
UINTERFACE(MinimalAPI,BlueprintType, Blueprintable)
class UICell : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class G1COLLAB_API IICell
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "ICell")
	bool QueryTags(FGameplayTagQuery query);
	virtual bool QueryTags_Implementation(FGameplayTagQuery query){return false;};
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "ICell")
	void UpdateCellTags(FGameplayTagContainer inputTags);
	virtual void UpdateCell_Implementation(FGameplayTagContainer inputTags){};
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "ICell")
	FGameplayTagContainer GetTags();
	virtual FGameplayTagContainer GetTags_Implementation(){return FGameplayTagContainer();};
};
