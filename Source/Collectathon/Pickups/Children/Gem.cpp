// 27th July 2017 - Team Headless Sloth

#include "Collectathon/Pickups/Children/Gem.h"
#include "Collectathon/CustomComponents/Destroyable/DestroyableComponent.h"


AGem::AGem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OnPickedUp.AddDynamic(Destroyable, &UDestroyableComponent::HideSM);
	OnDestroyed.AddDynamic(Destroyable, &UDestroyableComponent::Kill);

	
}

void AGem::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	Value = (float)GemType;

}

// Called when the game starts or when spawned
void AGem::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGem::OnCollected(bool bKill)
{
	Super::OnCollected(bKill);
}