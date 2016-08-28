// Fill out your copyright notice in the Description page of Project Settings.

#include "VinciMoba.h"
#include "VinciLib.h"

VinciLib::VinciLib()
{
}

VinciLib::~VinciLib()
{
}


FIntVector VinciLib::ToIntV(FVector Vec)
{
	return FIntVector(FMath::RoundToInt(Vec.X), FMath::RoundToInt(Vec.Y), FMath::RoundToInt(Vec.Z));
}

FVector VinciLib::ToVec(FIntVector Vec)
{
	return FVector(Vec.X, Vec.Y, Vec.Z);
}
