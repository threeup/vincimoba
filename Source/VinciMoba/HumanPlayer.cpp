// Fill out your copyright notice in the Description page of Project Settings.

#include "VinciMoba.h"
#include "HumanPlayer.h"

AHumanPlayer::AHumanPlayer()
{

}


void AHumanPlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();


	StateName = NAME_Playing; 
}
