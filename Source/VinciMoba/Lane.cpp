// Fill out your copyright notice in the Description page of Project Settings.

#include "VinciMoba.h"
#include "Lane.h"

LaneData::LaneData(FIntVector InIntVec, ETileType InVal)
{
	IntVec = InIntVec;
	Val = InVal;
}

// Sets default values
ALane::ALane()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALane::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALane::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

ETileType ALane::GetData(int InX, int InY)
{
	for (auto It = Data.CreateConstIterator(); It; ++It)
	{
		LaneData DataIt = It.Value();
		if (DataIt.IntVec.X == InX && DataIt.IntVec.Y == InY)
		{
			return DataIt.Val;
		}
	}
	return ETileType::Rock;
}

ETileType ALane::GetData(FIntVector InIntVec)
{
	if (Data.Contains(InIntVec))
	{
		return Data[InIntVec].Val;
	}
	return ETileType::Rock;
}

void ALane::AddDataBigger(FIntVector InIntVec, ETileType InVal)
{
	if (Data.Contains(InIntVec))
	{
		if (Data[InIntVec].Val == ETileType::LaneCenter)
		{
			return;
		}
		Data[InIntVec].Val = InVal;
	}
	else
	{
		Data.Add(InIntVec, LaneData(InIntVec,InVal));
	}
}

void ALane::Widen(int Min, int Max)
{
	TArray<LaneData> CenterArray;
	for (auto It = Data.CreateConstIterator(); It; ++It)
	{
		LaneData DataIt = It.Value();
		CenterArray.Add(DataIt);
	}
	for (auto It = CenterArray.CreateConstIterator(); It; ++It)
	{
		LaneData DataIt = *It;
		int StepMax = Min;
		for (int step = 0; step < StepMax; ++step)
		{
			AddDataBigger(DataIt.IntVec + FIntVector(step, 0, 0), ETileType::LaneEdge);
			AddDataBigger(DataIt.IntVec + FIntVector(0, step, 0), ETileType::LaneEdge);
			AddDataBigger(DataIt.IntVec + FIntVector(-step, 0, 0), ETileType::LaneEdge);
			AddDataBigger(DataIt.IntVec + FIntVector(0, step, 0), ETileType::LaneEdge);
		}
	}
}
