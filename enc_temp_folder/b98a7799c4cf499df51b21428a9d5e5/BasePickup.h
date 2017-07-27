// 27th July 2017 - Team Headless Sloth

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePickup.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickedUp, class UStaticMeshComponent*, SM);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDestroyed, ABasePickup*, Self);

UCLASS()
class COLLECTATHON_API ABasePickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasePickup();

	FOnPickedUp OnPickedUp;
	FOnDestroyed OnDestroyed;

	virtual void OnCollected(bool bKill);

	float GetValue() const;

protected:
	virtual void PostInitializeComponents() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Pickup")
		class UDestroyableComponent* Destroyable;

	UPROPERTY(EditAnywhere, Category = "Pickup")
		float Value;
private:

	UPROPERTY(VisibleDefaultsOnly, Category = "Pickup")
		USceneComponent* MyRoot;

	UPROPERTY(VisibleDefaultsOnly, Category = "Pickup")
		UStaticMeshComponent* PickupMesh;




	
	
};
