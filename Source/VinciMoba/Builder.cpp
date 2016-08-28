// Fill out your copyright notice in the Description page of Project Settings.

#include "VinciMoba.h"
#include "VinciState.h"
#include "Builder.h"
#include "Lane.h"
#include "VinciLib.h"
#include "VinciMobaGameMode.h"


// Sets default values
ABuilder::ABuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BuildState = EBuildEnum::BuildWaiting;
	
}

// Called when the game starts or when spawned
void ABuilder::BeginPlay()
{
	Super::BeginPlay();
	UWorld* World = GetWorld();
	Mode = Cast<AVinciMobaGameMode>(World->GetAuthGameMode());
	VState = Cast<AVinciState>(World->GetGameState());
	VState->BuilderBusy = true;
	MaxX = VState->MapSize;
	MaxY = VState->MapSize;
	
	DirX = 1;
	DirY = 0;
	Spacing = VState->Spacing;

	AActor* Spawned;
	Spawned = GetWorld()->SpawnActor(Mode->LaneClass, &FVector::ZeroVector, &FRotator::ZeroRotator, FActorSpawnParameters());
	MidLane = Cast<ALane>(Spawned);
	Spawned = GetWorld()->SpawnActor(Mode->LaneClass, &FVector::ForwardVector, &FRotator::ZeroRotator, FActorSpawnParameters());
	LeftLane = Cast<ALane>(Spawned);
	Spawned = GetWorld()->SpawnActor(Mode->LaneClass, &FVector::RightVector, &FRotator::ZeroRotator, FActorSpawnParameters());
	RightLane = Cast<ALane>(Spawned);

	BuildState = EBuildEnum::BuildMidLane;
}

bool ABuilder::BuildLane(ALane* Lane, int CrossPointX, int CrossPointY)
{
	//int dx = MaxX - CrossPointX;
	//int dy = MaxY - CrossPointY;
	//int slope = dy / dx;
	//int intercept = CrossPointY - slope*CrossPointX;
	FIntVector Origin = FIntVector(CrossPointX, CrossPointY, 0);
	FVector Dir = FVector(MaxX - CrossPointX, MaxY - CrossPointY, 0).GetSafeNormal();

	if (Lane->Data.Num() == 0)
	{
		GridPen.X = CrossPointX;
		GridPen.Y = CrossPointY;
		Lane->AddDataBigger(GridPen, ETileType::LaneCenter);
	}
	float DistToCrossPoint = FMath::Sqrt(FVector::DistSquaredXY(FVector(CrossPointX, CrossPointY, 0), FVector(GridPen.X, GridPen.Y, 0)));
	FIntVector Expected = Origin + VinciLib::ToIntV(DistToCrossPoint*Dir);
	int DiffX = FMath::Abs(GridPen.X - Expected.X);
	int DiffY = FMath::Abs(GridPen.Y - Expected.Y);

	int AllowedDiffX = FMath::Abs(Expected.X - MaxX / 2);
	int AllowedDiffY = FMath::Abs(Expected.Y - MaxY / 2);

	bool bTooFar = DiffX > AllowedDiffX || DiffY > AllowedDiffY;
	if (bTooFar)
	{
		if (GridPen.X > GridPen.Y)
		{
			GridPen.Y++;
		}
		else
		{
			GridPen.X++;
		}
	}
	else
	{
		if (GridPen.X >= (MaxX - 1))
		{
			GridPen.Y++;
		}
		else if (GridPen.Y >= (MaxY - 1))
		{
			GridPen.X++;
		}
		else
		{
			switch (FMath::RandRange(0, 2))
			{
			case 0:
				GridPen.X++;
				GridPen.Y++;
				break;
			case 1:
				GridPen.Y++;
				break;
			case 2:
				GridPen.X++;
				break;
			}
		}
	}
	Lane->AddDataBigger(GridPen, ETileType::LaneCenter);

	FIntVector FlipGridPen = FIntVector(-GridPen.Y, -GridPen.X, 10);
	Lane->AddDataBigger(FlipGridPen, ETileType::LaneCenter);

	if (GridPen.X >= MaxX-1 && GridPen.Y >= MaxY-1)
	{
		return true;
	}
	return false;
}

void ABuilder::AfterAdd()
{
	/*SpawnPos = FVector(FlipGridPen.X * Spacing, FlipGridPen.Y * Spacing, 150);
	SetActorLocation(SpawnPos);
	AVinciMobaGameMode* Mode = Cast<AVinciMobaGameMode>(GetWorld()->GetAuthGameMode());
	GetWorld()->SpawnActor(Mode->TreeClass, &SpawnPos, &FRotator::ZeroRotator, FActorSpawnParameters());*/
}

// Called every frame
void ABuilder::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (VState->Phase != EPhase::Builder)
	{
		return;
	}
	if (BuildState == EBuildEnum::BuildMidLane)
	{
		bool bDone = BuildLane(MidLane, 0, 0);
		if (bDone)
		{
			MidLane->Widen(2, 3);
			BuildState = EBuildEnum::BuildLeftLane;
		}
	}
	else if (BuildState == EBuildEnum::BuildLeftLane)
	{
		bool bDone = BuildLane(LeftLane, MaxX * 1 / 2, -MaxX * 1 / 2);
		if (bDone)
		{
			LeftLane->Widen(2, 3);
			BuildState = EBuildEnum::BuildRightLane;
		}
	}
	else if (BuildState == EBuildEnum::BuildRightLane)
	{
		bool bDone = BuildLane(RightLane, -MaxX * 1 / 2, MaxX * 1 / 2);
		if (bDone)
		{
			RightLane->Widen(2, 3);
			BuildState = EBuildEnum::BuildGrid;
			GridPen.X = -MaxX;
			GridPen.Y = -MaxY;
		}
	}
	else if (BuildState == EBuildEnum::BuildGrid)
	{
		if (DirY == 1)
		{
			if (GridPen.X == MaxX)
			{
				DirX = -1;
			}
			if (GridPen.X == -MaxX)
			{
				DirX = 1;
			}
			DirY = 0;
		}
		else if (GridPen.X == MaxX || GridPen.X == -MaxX)
		{
			DirX = 0;
			DirY = 1;
			if (GridPen.Y == MaxY)
			{
				BuildState = EBuildEnum::BuildDone;
			}
		}

		FVector Pos = FVector(GridPen.X * Spacing, GridPen.Y * Spacing, 0);
		
		SetActorLocation(Pos);
		ETileType LaneType = MidLane->GetData(GridPen.X, GridPen.Y);
		if (LaneType == ETileType::Rock)
		{
			LaneType = LeftLane->GetData(GridPen.X, GridPen.Y);
		}
		if (LaneType == ETileType::Rock)
		{
			LaneType = RightLane->GetData(GridPen.X, GridPen.Y);
		}
		if (LaneType == ETileType::Rock)
		{
			AVinciMobaGameMode* Mode = Cast<AVinciMobaGameMode>(GetWorld()->GetAuthGameMode());
			AActor* Spawned = GetWorld()->SpawnActor(Mode->RockClass, &Pos, &FRotator::ZeroRotator, FActorSpawnParameters());
			Spawned->SetFolderPath("Box");
		}
		GridPen.X += DirX;
		GridPen.Y += DirY;
	}
	else if (BuildState == EBuildEnum::BuildDone)
	{
		VState->Phase = EPhase::Spawner;
	}
}

