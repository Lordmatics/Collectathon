// 27th July 2017 - Team Headless Sloth

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COLLECTATHON_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	void AddToInventory(class ABasePickup* Pickup);

	UFUNCTION()
		void RemoveFromInventory(class ABasePickup* Pickup);

	void AddCurrency(float Value);
	bool SpendCurrency(float Value);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category = "Inventory")
		TArray<class ABasePickup*> Inventory;

	UPROPERTY(EditAnywhere, Category = "Inventory")
		float Currency;
	
};
