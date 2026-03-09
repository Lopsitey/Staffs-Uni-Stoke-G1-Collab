// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ICell.h"
#include "UObject/Object.h"
#include "CPPCell.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class G1COLLAB_API UCPPCell : public UObject, public IICell
{
	GENERATED_BODY()
	public:
	UCPPCell();
	UCPPCell(const FGameplayTagContainer tags);
	UPROPERTY(EditAnywhere,blueprintReadWrite)
	FGameplayTagContainer cellTags;

	bool QueryTags_Implementation(FGameplayTagQuery query) override;
	virtual void AppendCellTags_Implementation(FGameplayTagContainer inputTags) override;
	virtual void RemoveCellTags_Implementation(FGameplayTagContainer inputTags) override;
	FGameplayTagContainer GetTags_Implementation() override {return cellTags;};
};
