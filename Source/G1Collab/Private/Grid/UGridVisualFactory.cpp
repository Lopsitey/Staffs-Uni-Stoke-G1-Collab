// Fill out your copyright notice in the Description page of Project Settings.


#include "G1Collab/Public/Grid/UGridVisualFactory.h"


// Sets default values
AUGridVisualFactory::AUGridVisualFactory()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AUGridVisualFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUGridVisualFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

