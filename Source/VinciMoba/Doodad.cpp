// Fill out your copyright notice in the Description page of Project Settings.

#include "VinciMoba.h"
#include "Doodad.h"


// Sets default values
ADoodad::ADoodad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoodad::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoodad::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

