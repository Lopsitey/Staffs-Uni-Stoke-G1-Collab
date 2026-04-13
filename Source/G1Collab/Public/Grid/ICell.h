// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ICell.generated.h"


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
	void AppendCellTags(FGameplayTagContainer inputTags);
	virtual void AppendCellTags_Implementation(FGameplayTagContainer inputTags){};

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "ICell")
	void RemoveCellTags(FGameplayTagContainer inputTags);
	virtual void RemoveCellTags_Implementation(FGameplayTagContainer inputTags){};

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "ICell")
	int32 GetCellData(FName Key);
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "ICell")
	void SetCellData(FName Key, int32 Value);
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category = "ICell")
	FGameplayTagContainer GetTags();
	virtual FGameplayTagContainer GetTags_Implementation(){return FGameplayTagContainer();};
};
