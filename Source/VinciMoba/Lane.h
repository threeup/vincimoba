// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Lane.generated.h"


UENUM(BlueprintType)
enum class ETileType : uint8
{
	LaneCenter,
	LaneEdge,
	Rock,
};


struct LaneData
{
	FIntVector IntVec;
	ETileType Val;
	LaneData(FIntVector InIntVec, ETileType Val);
};

UCLASS()
class VINCIMOBA_API ALane : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALane();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	ETileType GetData(int InX, int InY);
	ETileType GetData(FIntVector InIntVec);
	void AddDataBigger(FIntVector InIntVec, ETileType InVal);
	void Widen(int Min, int Max);

	TMap<FIntVector, LaneData> Data;
	
};
