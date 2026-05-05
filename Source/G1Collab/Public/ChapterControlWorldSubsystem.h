// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ChapterControlWorldSubsystem.generated.h"


UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLevelLoadedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBeginLevelUnLoad);
/**
 *  
 */
UCLASS()
class G1COLLAB_API UChapterControlWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	public:

	UPROPERTY(BlueprintReadOnly)
	int32 LevelIndex;


	
	UPROPERTY(BlueprintAssignable)
	FLevelLoadedSignature OnLevelLoaded;
	UPROPERTY(BlueprintAssignable,BlueprintCallable)
	FBeginLevelUnLoad BeginLevelUnLoad;
	
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE int32 GetLevelIndex(){return LevelIndex;}
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void IncrementLevelIndex() {LevelIndex++;};

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void DecrementLevelIndex() {LevelIndex--;};

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void SetLevelIndex(int32 Index) {LevelIndex = Index;}
	
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE void ResetLevelIndex() {LevelIndex = 0;}
	
	UFUNCTION(BlueprintCallable, Category = "Level Instance World Subsystem")
	bool LoadLevel(int index);
	
	UFUNCTION(BlueprintCallable, Category = "Level Instance World Subsystem")
	bool UnloadLevel(int index);


private:
	UFUNCTION()
	void CallLevelLoaded();

	int32 lastUsedLevelIndex;
};
