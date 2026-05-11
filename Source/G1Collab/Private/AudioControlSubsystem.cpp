// Fill out your copyright notice in the Description page of Project Settings.

#include "AudioControlSubsystem.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

void UAudioControlSubsystem::PlayChapterMusic(USoundBase* SoundToPlay)
{
	if (!IsValid(SoundToPlay))//Ensures the input is valid
		return;

	if (IsValid(CurrentMusicTrack))//Ensures the track to fade is valid
		CurrentMusicTrack->FadeOut(MusicFadeOutDuration, 0.0f);//0 being the volume to fade to

	UWorld* World = GetWorld();//Ensures the world to play the sound in is valid - extra precaution as required for the func
	if (!IsValid(World))
	{
		CurrentMusicTrack = nullptr;
		return;
	}

	//Spawns the new sound
	UAudioComponent* NewTrack = UGameplayStatics::SpawnSound2D(
		World,
		SoundToPlay,
		MusicTargetVolume,
		1.0f,
		0.0f,
		nullptr,
		true,
		false);

	//Returns if it failed to create the new track for whatever reason
	if (!IsValid(NewTrack))
	{
		CurrentMusicTrack = nullptr;
		return;
	}

	//Sets the current track to the new track
	CurrentMusicTrack = NewTrack;
	//Fades it in
	CurrentMusicTrack->FadeIn(MusicFadeInDuration, MusicTargetVolume, 0.0f);
}
