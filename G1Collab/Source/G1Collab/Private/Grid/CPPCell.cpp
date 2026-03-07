// Fill out your copyright notice in the Description page of Project Settings.


#include "G1Collab/Public/Grid/CPPCell.h"

UCPPCell::UCPPCell()
{
}

UCPPCell::UCPPCell(const FGameplayTagContainer tags)
{
	cellTags = tags;
}

bool UCPPCell::QueryTags_Implementation(FGameplayTagQuery query)
{
	return cellTags.MatchesQuery(query);
}

void UCPPCell::UpdateCell_Implementation(FGameplayTagContainer inputTags)
{
	cellTags.AppendTags(inputTags);
	IICell::UpdateCell_Implementation(inputTags);
}
