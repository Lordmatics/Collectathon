// 27th July 2017 - Team Headless Sloth

#include "Collectathon/Pickups/BasePickup.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Collectathon/CustomComponents/Destroyable/DestroyableComponent.h"

// Sets default values
ABasePickup::ABasePickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("MyRoot"));
	RootComponent = MyRoot;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyPickupStaticMesh"));
	PickupMesh->SetupAttachment(RootComponent);
	PickupMesh->SetCollisionProfileName(FName(TEXT("Pickup")));

	Destroyable = CreateDefaultSubobject<UDestroyableComponent>(TEXT("DestroyableComponent"));

	OnPickedUp.AddDynamic(Destroyable, &UDestroyableComponent::HideSM);
	OnDestroyed.AddDynamic(Destroyable, &UDestroyableComponent::Kill);

}
void ABasePickup::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

// Called when the game starts or when spawned
void ABasePickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePickup::OnCollected(bool bKill)
{
	if (bKill)
	{
		if (OnDestroyed.IsBound())
		{
			OnDestroyed.Broadcast(this);
		}
	}
	else
	{
		if (OnPickedUp.IsBound())
		{
			OnPickedUp.Broadcast(PickupMesh);
		}
	}

}