// Fill out your copyright notice in the Description page of Project Settings.

#include "VinciMoba.h"
#include "Decoration.h"


// Sets default values for this component's properties
UDecoration::UDecoration()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDecoration::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDecoration::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	this->AddRelativeRotation(FRotator(0.0f, RotationSpeed*DeltaTime, 0.0f));
}

