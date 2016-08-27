// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Builder.generated.h"

class ALane;
class AVinciMobaGameMode;
class AVinciState;

UENUM(BlueprintType)		
enum class EBuildEnum : uint8
{
	BuildWaiting,
	BuildMidLane,
	BuildLeftLane,
	BuildRightLane,
	BuildGrid,
	BuildDone
};


UCLASS()
class VINCIMOBA_API ABuilder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilder();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	EBuildEnum BuildState;

	float Spacing;

	ALane* MidLane;
	ALane* LeftLane;
	ALane* RightLane;

	void AfterAdd();
private:
	FIntVector GridPen;
	int DirX;
	int DirY;
	int MaxX;
	int MaxY;
	AVinciMobaGameMode* Mode;
	AVinciState* VState;
	
	bool BuildLane(ALane* Lane, int CrossPointX, int CrossPointY);
	FIntVector ToIntV(FVector Vec);
	FVector ToVec(FIntVector Vec);
};
