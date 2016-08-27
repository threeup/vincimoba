// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameState.h"
#include "VinciState.generated.h"

/**
 * 
 */
UCLASS()
class VINCIMOBA_API AVinciState : public AGameState
{
	GENERATED_BODY()
	
	
public:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MapSize)
	float Spacing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MapSize)
	int MapSize;
};
