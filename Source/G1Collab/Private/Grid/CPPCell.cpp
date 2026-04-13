// Fill out your copyright notice in the Description page of Project Settings.


#include "G1Collab/Public/Grid/CPPCell.h"

UCPPCell::UCPPCell()
{
}



bool UCPPCell::QueryTags_Implementation(FGameplayTagQuery query)
{
	return cellTags.MatchesQuery(query);
}

void UCPPCell::AppendCellTags_Implementation(FGameplayTagContainer inputTags)
{
	cellTags.AppendTags(inputTags);
	IICell::AppendCellTags_Implementation(inputTags);
	OnCellTagsUpdated.Broadcast(cellTags);
}

void UCPPCell::RemoveCellTags_Implementation(FGameplayTagContainer inputTags)
{
	cellTags.RemoveTags(inputTags);
	IICell::RemoveCellTags_Implementation(inputTags);
	OnCellTagsUpdated.Broadcast(cellTags);
}
