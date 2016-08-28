// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "VinciMoba.h"
#include "VinciMobaGameMode.h"
#include "VinciState.h"
#include "GameFramework/GameState.h"


AVinciMobaGameMode::AVinciMobaGameMode()
{

}

void AVinciMobaGameMode::StartPlay()
{
	Super::StartPlay();
	VState = Cast<AVinciState>(GameState);
}

void AVinciMobaGameMode::Tick(float DeltaSeconds)
{
	/*if (VState->Phase == EPhase::Spawner)
	{
		VState->SpawnStuff();
	}*/
}