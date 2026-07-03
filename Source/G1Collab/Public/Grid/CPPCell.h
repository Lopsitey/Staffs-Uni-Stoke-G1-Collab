// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ICell.h"
#include "UObject/Object.h"
#include "CPPCell.generated.h"
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCellUpdateSig, FGameplayTagContainer,Tags);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLightUpdateSig);

/**
 *  Data only, used to query the state of a tile
 */
UCLASS(BlueprintType, Blueprintable)
class G1COLLAB_API UCPPCell : public UObject, public IICell
{
	GENERATED_BODY()
	public:
	UCPPCell();
	

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ICell")
	FCellUpdateSig OnCellTagsUpdated;
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ICell")
	FLightUpdateSig OnLightTagsUpdated;
	
	UPROPERTY(BlueprintReadOnly, Category = "ICell")
	TMap<FGameplayTag,int32> CellTags;
	FORCEINLINE int32 GetCellData_Implementation(FGameplayTag Key) {return *CellTags.Find(Key);}
	FORCEINLINE void SetCellData_Implementation(FGameplayTag Key, int32 Value) {CellTags.Add(Key,Value);}



	
	bool QueryTags_Implementation(FGameplayTagQuery query) override;
	virtual void AppendCellTags_Implementation(FGameplayTagContainer inputTags) override;
	virtual void RemoveCellTags_Implementation(FGameplayTagContainer inputTags) override;
	FGameplayTagContainer GetTags_Implementation() override ;
};
