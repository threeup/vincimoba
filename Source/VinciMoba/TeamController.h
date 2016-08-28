// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"

#include "TeamController.generated.h"

class AActorBase;
/**
 * 
 */
UCLASS()
class VINCIMOBA_API ATeamController : public AAIController
{
	GENERATED_BODY()


public:
	FVector GetLocation();

	TArray<AActorBase*> Members;

	FIntVector HomeCoord;
	FVector HomeLocation;
};
