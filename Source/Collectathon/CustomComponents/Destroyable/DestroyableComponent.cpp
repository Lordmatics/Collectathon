// 27th July 2017 - Team Headless Sloth

#include "Collectathon/CustomComponents/Destroyable/DestroyableComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Collectathon/Pickups/BasePickup.h"

// Sets default values for this component's properties
UDestroyableComponent::UDestroyableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UDestroyableComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDestroyableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDestroyableComponent::HideSM(UStaticMeshComponent* SM)
{
	if (!SM) return;
	UStaticMeshComponent& Address = *(SM);
	Address.SetVisibility(false);
	Address.SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UDestroyableComponent::Kill(ABasePickup* Pickup)
{
	if (!Pickup) return;
	Pickup->Destroy();
}