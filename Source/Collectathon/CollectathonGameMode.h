// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CollectathonGameMode.generated.h"

UCLASS(minimalapi)
class ACollectathonGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACollectathonGameMode();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Gem Class")
		TSubclassOf<class ABasePickup> PickupClass;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		float Radius;
	UPROPERTY(EditAnywhere, Category = "Spawning")
		FVector Centre;
};



