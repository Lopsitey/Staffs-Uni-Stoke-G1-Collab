// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UObject/Interface.h"

#include "IGridDataFactory.generated.h"
// This class does not need to be modified.
UINTERFACE(MinimalAPI,Blueprintable)
class UIGridDataFactory : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class G1COLLAB_API IIGridDataFactory
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	 TMap<FVector2D,UObject*>  ConstructGrid();
	virtual  TMap<FVector2D,UObject*>  ConstructGrid_Implementation() = 0;
	
};

