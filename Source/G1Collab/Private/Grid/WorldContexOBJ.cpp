// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid/WorldContexOBJ.h"

class UWorld* UWorldContexOBJ::GetWorld() const
{
	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		return GetOuter()->GetWorld();
	}
	else
	{
		return nullptr;
	}
}
