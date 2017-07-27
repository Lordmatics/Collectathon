// 27th July 2017 - Team Headless Sloth

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DestroyableComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COLLECTATHON_API UDestroyableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDestroyableComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
		void HideSM(class UStaticMeshComponent* SM);

	UFUNCTION()
		void Kill(class ABasePickup* Pickup);
	
};
