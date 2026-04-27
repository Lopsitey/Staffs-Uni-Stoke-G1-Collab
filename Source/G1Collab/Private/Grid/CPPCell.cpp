// Fill out your copyright notice in the Description page of Project Settings.


#include "G1Collab/Public/Grid/CPPCell.h"

UCPPCell::UCPPCell()
{
	
}



bool UCPPCell::QueryTags_Implementation(FGameplayTagQuery query)
{
	return GetTags_Implementation().MatchesQuery(query);
}

void UCPPCell::AppendCellTags_Implementation(FGameplayTagContainer inputTags)
{

	for (auto tag : inputTags.GetGameplayTagArray())
	{
		if (CellTags.Contains(tag))
		{
			CellTags.Add(tag) =  *CellTags.Find(tag) + 1;
		}
		else
		{
			CellTags.Add(tag) =  1;
		}
	}
	
	OnCellTagsUpdated.Broadcast(GetTags_Implementation());
	
}

void UCPPCell::RemoveCellTags_Implementation(FGameplayTagContainer inputTags)
{
	
	

	for (auto tag : inputTags.GetGameplayTagArray())
	{
		if (CellTags.Contains(tag))
		{
			CellTags.Add(tag) =  *CellTags.Find(tag) - 1;
			
			//Removes tag if count is 0
			if (*CellTags.Find(tag) == 0)
			{
				CellTags.Remove(tag);
			}
		}
	}
	OnCellTagsUpdated.Broadcast(GetTags_Implementation());
}

FGameplayTagContainer UCPPCell::GetTags_Implementation()
{

	TArray<FGameplayTag> tags;
	CellTags.GetKeys(tags);
	return FGameplayTagContainer::CreateFromArray(tags);
	
}
