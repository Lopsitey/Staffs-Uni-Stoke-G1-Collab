// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AudioControlSubsystem.generated.h"

class UAudioComponent;
class UMetaSoundSource;

/**
 * 
 */
UCLASS()
class G1COLLAB_API UAudioControlSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	UAudioComponent* CurrentMusicTrack = nullptr; // The music currently being played

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio", meta = (ClampMin = "0.0"))
	float MusicFadeInDuration = 5.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio", meta = (ClampMin = "0.0"))
	float MusicFadeOutDuration = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float MusicTargetVolume = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlayChapterMusic(USoundBase* SoundToPlay); // Plays chapter music with fade transition.
};
