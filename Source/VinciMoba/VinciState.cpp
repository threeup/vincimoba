// Fill out your copyright notice in the Description page of Project Settings.

#include "VinciMoba.h"
#include "VinciState.h"
#include "VinciMobaGameMode.h"



void AVinciState::BeginPlay()
{
	UWorld* World = GetWorld();
	AVinciMobaGameMode* Mode = Cast<AVinciMobaGameMode>(World->GetAuthGameMode());
	
	
	
	FTransform x = this->GetActorTransform();
	FActorSpawnParameters SpawnP = FActorSpawnParameters();

	World->SpawnActor(Mode->DefaultHeroClass, &x, SpawnP);
	Super::BeginPlay();

	
}