// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/GridDataWorldSubsystem.h"

#include "Grid/CPPCell.h"
#include "Grid/ICell.h"

void UGridDataWorldSubsystem::AddTagToCell(FVector2D Key, FGameplayTagContainer TagsToAdd)
{

	if(DataLayer.Contains(Key))
	{

		UObject* cell = *DataLayer.Find(Key);
		IICell::Execute_AppendCellTags(cell, TagsToAdd);
	}
	
}

bool UGridDataWorldSubsystem::QueryCell(FVector2D Key, FGameplayTagQuery Query)
{

	if(DataLayer.Contains(Key))
	{

		UObject* cell = *DataLayer.Find(Key);
		return IICell::Execute_QueryTags(cell, Query);
	}

	return false;
}
void UGridDataWorldSubsystem::RemoveTagFromCell(FVector2D Key, FGameplayTagContainer TagsToRemove)
{

	if(DataLayer.Contains(Key))
	{

		UObject* cell = *DataLayer.Find(Key);
		IICell::Execute_RemoveCellTags(cell, TagsToRemove);
	}
	
}

UCPPCell* UGridDataWorldSubsystem::GetCellFromDataLayer(FVector2D GridPos, bool& bCellLocated)
{
	if(DataLayer.Contains(GridPos))
	{
		UObject* cell = *DataLayer.Find(GridPos);
		bCellLocated = true;
		return Cast<UCPPCell>(cell);
	}
	bCellLocated = false;
	return nullptr;	
}

UObject* UGridDataWorldSubsystem::GetObjectFromDynamicLayer(FVector2D GridPos, bool& bItemFound)
{

	if(DynamicLayer.Contains(GridPos))
	{

		UObject* cell = *DynamicLayer.Find(GridPos);
		bItemFound = true;
		return cell;
	}
	bItemFound = false;
	return nullptr;
}

void UGridDataWorldSubsystem::RemoveObjectFromDynamicLayer(FVector2D GridPos)
{
	if(DynamicLayer.Contains(GridPos))
	{
		DynamicLayer.Remove(GridPos);
	}
}
