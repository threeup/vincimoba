// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "VinciMoba.h"
#include "VinciMobaGameMode.h"
#include "VinciMobaPawn.h"

AVinciMobaGameMode::AVinciMobaGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AVinciMobaPawn::StaticClass();
}

