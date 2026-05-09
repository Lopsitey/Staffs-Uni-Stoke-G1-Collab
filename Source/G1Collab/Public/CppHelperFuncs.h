// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CppHelperFuncs.generated.h"

/**
 * 
 */
UCLASS()
class G1COLLAB_API UCppHelperFuncs : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	// creates a instanced component
	UFUNCTION(BlueprintCallable, meta=(DeterminesOutputType="ComponentClass", DynamicOutputParam="ReturnValue"))
	static UActorComponent* CreateComponent(AActor *TargetActor, TSubclassOf<UActorComponent> ComponentClass, FTransform RelativeTransform, bool bManualAttachment = false)
	{
		if(!TargetActor || !ComponentClass)
			return nullptr;

		if(UActorComponent *Component = TargetActor->AddComponentByClass(ComponentClass, bManualAttachment, RelativeTransform, false))
		{
			TargetActor->AddInstanceComponent(Component);
			TargetActor->MarkPackageDirty();
			return Component;
		}

		return nullptr;
	}
};
