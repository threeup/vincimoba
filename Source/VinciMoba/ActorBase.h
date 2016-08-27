// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ActorBase.generated.h"

class ATeamController;
class AHumanPlayer;

UCLASS()
class VINCIMOBA_API AActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void JoinTeam(ATeamController* InTeam);
	void Possessed(AHumanPlayer* InHuman);
	
	ATeamController* Team;

	AHumanPlayer* Human;
	
};
