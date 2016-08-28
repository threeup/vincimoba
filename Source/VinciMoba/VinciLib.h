// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class VINCIMOBA_API VinciLib
{
public:
	VinciLib();
	~VinciLib();

	static FIntVector ToIntV(FVector Vec);
	static FVector ToVec(FIntVector Vec);
};
