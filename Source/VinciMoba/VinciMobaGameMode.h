// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameFramework/GameMode.h"
#include "ActorBase.h"
#include "VinciMobaGameMode.generated.h"

UCLASS(minimalapi)
class AVinciMobaGameMode : public AGameMode
{
	GENERATED_BODY()

	
	
public:
	AVinciMobaGameMode();

	virtual void StartPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
	TSubclassOf<class AActorBase> DefaultHeroClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
	TSubclassOf<class AActorBase> DefaultGruntClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
	TSubclassOf<class AActorBase> TreeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
	TSubclassOf<class AActorBase> RockClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
	TSubclassOf<class AActor> LaneClass;

};



