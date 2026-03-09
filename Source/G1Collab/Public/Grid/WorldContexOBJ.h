// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorldContexOBJ.generated.h"

/**
 * 
 */
UCLASS(Blueprintable,BlueprintType)
class G1COLLAB_API UWorldContexOBJ : public UObject
{
	GENERATED_BODY()

	virtual class UWorld* GetWorld() const override;
};
