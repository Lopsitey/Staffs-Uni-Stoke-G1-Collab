// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameplayTagContainer.h"

class UCPPCell;

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
	UCPPCell* GetCellFromDataLayer(FVector2D GridPos, bool& bCellLocated);
	UFUNCTION(BlueprintCallable)
	void ClearDataLayer(){DataLayer.Empty();}
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void OverrideDataLayer(TMap<FVector2D,UObject*> newLayer ){DataLayer = newLayer;};


	//DynamicLayer
	UFUNCTION(BlueprintCallable)
	void AddObjectToDynamicLayer(FVector2D GridPos, UObject* cell) {DynamicLayer.Add(GridPos,cell);}
	UFUNCTION(BlueprintCallable)
	UObject* GetObjectFromDynamicLayer(FVector2D GridPos,bool& bItemFound);
	UFUNCTION(BlueprintCallable)
	void RemoveObjectFromDynamicLayer(FVector2D GridPos);
	UFUNCTION(BlueprintCallable)
	void ClearDynamicLayer() {DynamicLayer.Empty();};

	UFUNCTION(BlueprintCallable)
	void ClearSystem(){DynamicLayer.Empty(); DataLayer.Empty();};
	UFUNCTION(BlueprintCallable)	
	TMap<FVector2D,UObject*> GetDataLayer() {return DataLayer;}
	UFUNCTION(BlueprintCallable)	
	TMap<FVector2D,UObject*> GetDynamicLayer() {return DynamicLayer;}
	
	
	
	UPROPERTY(VisibleAnywhere)
	TMap<FVector2D,UObject*> DataLayer;
	UPROPERTY(VisibleAnywhere)
	TMap<FVector2D,UObject*> DynamicLayer;

	public:
	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FAllCellsFoundSigniture OnAllCellsFound;
};
