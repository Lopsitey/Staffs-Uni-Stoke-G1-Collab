// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ICell.h"
#include "UObject/Object.h"
#include "CPPCell.generated.h"
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCellUpdateSig, FGameplayTagContainer,Tags);
/**
 *  Data only, used to query the state of a tile
 */
UCLASS(BlueprintType, Blueprintable)
class G1COLLAB_API UCPPCell : public UObject, public IICell
{
	GENERATED_BODY()
	public:
	UCPPCell();
	UPROPERTY(EditAnywhere,blueprintReadWrite)
	FGameplayTagContainer cellTags;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "ICell")
	FCellUpdateSig OnCellTagsUpdated;

	UPROPERTY(BlueprintReadOnly, Category = "ICell")
	TMap<FName,int32> CellData;
	FORCEINLINE int32 GetCellData_Implementation(FName Key) {return *CellData.Find(Key);}
	FORCEINLINE void SetCellData_Implementation(FName Key, int32 Value) {CellData.Add(Key,Value);}



	
	bool QueryTags_Implementation(FGameplayTagQuery query) override;
	virtual void AppendCellTags_Implementation(FGameplayTagContainer inputTags) override;
	virtual void RemoveCellTags_Implementation(FGameplayTagContainer inputTags) override;
	FGameplayTagContainer GetTags_Implementation() override {return cellTags;};
};
