// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "CollectathonGameMode.h"
#include "CollectathonCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Collectathon/Utility/StaticLibrary.h"
#include "Collectathon/Pickups/BasePickup.h"

ACollectathonGameMode::ACollectathonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/BP_Extensions/Character/BP_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ACollectathonGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Working spawn code, for gem circles
	UWorld* const World = GetWorld();
	if (!World || !PickupClass) return;
	float Angle = 360.0f / 5;
	for (size_t i = 0; i < 5; i++)
	{
		FVector SpawnPos; UStaticLibrary::PointOnCircle(Radius, Angle * i, Centre, SpawnPos);
		World->SpawnActor<ABasePickup>(PickupClass, SpawnPos, FRotator::ZeroRotator);
	}

}