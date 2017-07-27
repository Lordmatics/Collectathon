// 27th July 2017 - Team Headless Sloth

#include "Collectathon/CustomComponents/Inventory/InventoryComponent.h"
#include "Collectathon/Pickups/BasePickup.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	Currency = 0.0f;
	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::AddToInventory(class ABasePickup* Pickup)
{
	if (!Pickup) { UE_LOG(LogTemp, Warning, TEXT("Pickup: was nullptr")); return; }
	Pickup->OnDestroyed.AddDynamic(this, &UInventoryComponent::RemoveFromInventory);
	Inventory.Add(Pickup);
	UE_LOG(LogTemp, Warning, TEXT("Pickup: %s , was added"), *Pickup->GetName());
}

void UInventoryComponent::RemoveFromInventory(class ABasePickup* Pickup)
{
	if (!Pickup) { UE_LOG(LogTemp, Warning, TEXT("Pickup: was nullptr")); return; }
	Inventory.Remove(Pickup);
}

void UInventoryComponent::AddCurrency(float Value)
{
	if (Value <= 0.0f) return;
	Currency += Value;
}

bool UInventoryComponent::SpendCurrency(float Value)
{
	bool Rv = true;
	Currency >= Value ? Currency -= Value : Rv = false;
	return Rv;
}