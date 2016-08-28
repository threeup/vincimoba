// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "VinciState.generated.h"

class ATeamController;


UENUM(BlueprintType)
enum class EPhase : uint8
{
	Setup,
	Builder,
	Spawner,
	Action,
};

UCLASS()
class VINCIMOBA_API AVinciState : public AGameState
{
	GENERATED_BODY()
	
	
public:
	AVinciState();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MapSize)
	float Spacing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MapSize)
	int MapSize;

	ATeamController* RedTeam;
	ATeamController* BlueTeam;

	bool BuilderBusy;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Phase)
	EPhase Phase;

private:
	void SpawnStuff();
};
