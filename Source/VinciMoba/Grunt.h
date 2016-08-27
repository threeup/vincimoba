// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ActorBase.h"
#include "Grunt.generated.h"

UCLASS()
class VINCIMOBA_API AGrunt : public AActorBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrunt();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
