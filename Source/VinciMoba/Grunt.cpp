// Fill out your copyright notice in the Description page of Project Settings.

#include "VinciMoba.h"
#include "Grunt.h"


// Sets default values
AGrunt::AGrunt()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGrunt::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrunt::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

