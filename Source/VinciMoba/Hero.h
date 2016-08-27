// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ActorBase.h"
#include "Hero.generated.h"

UCLASS()
class VINCIMOBA_API AHero : public AActorBase
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHero();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	
	
};
