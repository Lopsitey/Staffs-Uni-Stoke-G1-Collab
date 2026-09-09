// Fill out your copyright notice in the Description page of Project Settings.


#include "CppHelperFuncs.h"

#include "RHIFeatureLevel.h"

bool UCppHelperFuncs::IsRunningSM5()
{
	return GMaxRHIFeatureLevel == ERHIFeatureLevel::SM5;
}
