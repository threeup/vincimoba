// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "HumanPlayer.generated.h"

/**
 * 
 */
UCLASS()
class VINCIMOBA_API AHumanPlayer : public APlayerController
{
	GENERATED_BODY()
public:
	AHumanPlayer();
	
	virtual void PostInitializeComponents() override;
	
};
