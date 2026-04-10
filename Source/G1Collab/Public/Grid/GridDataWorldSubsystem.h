// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameplayTagContainer.h"

UENUM()
enum ELayerType
{
	Datalayer,
	DynamicLayer,
};


#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GridDataWorldSubsystem.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAllCellsFoundSigniture);


/**
 * 
 */
UCLASS()
class G1COLLAB_API UGridDataWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()


	//Cell Modification
	UFUNCTION(BlueprintCallable)
	void AddTagToCell(FVector2D Key, FGameplayTagContainer TagsToAdd);
	UFUNCTION(BlueprintCallable)
	bool QueryCell(FVector2D Key, FGameplayTagQuery Query);
	UFUNCTION(BlueprintCallable)
	void RemoveTagFromCell(FVector2D Key, FGameplayTagContainer TagsToRemove);

	//CellManagement
	UFUNCTION(BlueprintCallable)
	void AddCellToDataLayer(FVector2D GridPos, UObject* cell) {DataLayer.Add(GridPos,cell);}
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void OverrideDataLayer(TMap<FVector2D,UObject*> newLayer ){DataLayer = newLayer;};

	UFUNCTION(BlueprintCallable)	
	TMap<FVector2D,UObject*> GetDataLayer() {return DataLayer;}
	
	UPROPERTY(EditAnywhere)
	TMap<FVector2D,UObject*> DataLayer;
	UPROPERTY(EditAnywhere)
	TMap<FVector2D,UObject*> DynamicLayer;

	public:
	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FAllCellsFoundSigniture OnAllCellsFound;
};
