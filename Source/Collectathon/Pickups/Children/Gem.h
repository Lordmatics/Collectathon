// 27th July 2017 - Team Headless Sloth

#pragma once

#include "CoreMinimal.h"
#include "Pickups/BasePickup.h"
#include "Collectathon/Enums/GemEnum.h"
#include "Gem.generated.h"

/**
 * 
 */
UCLASS()
class COLLECTATHON_API AGem : public ABasePickup
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AGem();

	virtual void OnCollected(bool bKill) override;

protected:
	virtual void PostInitializeComponents() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, Category = "Gem")
		EGemType GemType;
	
};
