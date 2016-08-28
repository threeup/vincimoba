// Fill out your copyright notice in the Description page of Project Settings.

#include "VinciMoba.h"
#include "VinciState.h"
#include "TeamController.h"
#include "VinciLib.h"
#include "VinciMobaGameMode.h"


AVinciState::AVinciState()
{
	Phase = EPhase::Setup;
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickEnabled(true);
}

void AVinciState::BeginPlay()
{
	UWorld* World = GetWorld();
	Super::BeginPlay();
	Phase = EPhase::Builder;
	
}

void AVinciState::Tick(float DeltaSeconds)
{
	if (Phase == EPhase::Spawner)
	{
		SpawnStuff();
	}
}

void AVinciState::SpawnStuff()
{
	UWorld* World = GetWorld();
	FIntVector RedHome = FIntVector(MapSize - 1, MapSize - 1, 0);
	FVector RedHomePosition = VinciLib::ToVec(RedHome)*Spacing;
	RedTeam = World->SpawnActor<ATeamController>(RedHomePosition, FRotator::ZeroRotator);
	RedTeam->SetActorLabel(TEXT("RedTeam"));
	RedTeam->HomeCoord = RedHome;
	RedTeam->HomeLocation = RedHomePosition;
	FIntVector BlueHome = FIntVector(-(MapSize - 1), -(MapSize - 1), 0);
	FVector BlueHomePosition = VinciLib::ToVec(BlueHome)*Spacing;
	BlueTeam = World->SpawnActor<ATeamController>(BlueHomePosition, FRotator::ZeroRotator);
	BlueTeam->SetActorLabel(TEXT("BlueTeam"));
	BlueTeam->HomeCoord = BlueHome;
	BlueTeam->HomeLocation = BlueHomePosition;

	AVinciMobaGameMode* Mode = Cast<AVinciMobaGameMode>(World->GetAuthGameMode());
	FVector RedLocation = RedTeam->GetLocation();
	FVector BlueLocation = BlueTeam->GetLocation();

	FActorSpawnParameters SpawnParam = FActorSpawnParameters();

	SpawnParam.Name = TEXT("RedHeroOne");
	AActor* RedHeroOne = World->SpawnActor(Mode->DefaultHeroClass, &RedLocation, &FRotator::ZeroRotator, SpawnParam);
	RedHeroOne->Rename(TEXT("RedOne"));
	RedHeroOne->SetActorLabel(TEXT("RedOneLab"));

	SpawnParam = FActorSpawnParameters();
	SpawnParam.Name = TEXT("BlueHeroOne");
	AActor* BlueHeroOne = World->SpawnActor(Mode->DefaultHeroClass, &BlueLocation, &FRotator::ZeroRotator, SpawnParam);
	BlueHeroOne->SetActorLabel(TEXT("BlueHeroOne"));

	Phase = EPhase::Action;
}