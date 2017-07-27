// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "CollectathonGameMode.h"
#include "CollectathonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACollectathonGameMode::ACollectathonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/BP_Extensions/Character/BP_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
