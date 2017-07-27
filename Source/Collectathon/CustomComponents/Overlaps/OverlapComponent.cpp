// 27th July 2017 - Team Headless Sloth

#include "Collectathon/CustomComponents/Overlaps/OverlapComponent.h"
#include "Components/PrimitiveComponent.h"


// Sets default values for this component's properties
UOverlapComponent::UOverlapComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UOverlapComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOverlapComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UOverlapComponent::OnTriggerEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherbodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor) { UE_LOG(LogTemp, Warning, TEXT("OtherActor: was nullptr")); return; }
	UE_LOG(LogTemp, Warning, TEXT("OtherActor: %s , was overlapped ENTER"), *OtherActor->GetName());
	if (OnOverlapEnter.IsBound())
	{
		OnOverlapEnter.Broadcast(OtherActor);
	}
}

void UOverlapComponent::OnTriggerExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherbodyIndex)
{
	if (!OtherActor) { UE_LOG(LogTemp, Warning, TEXT("OtherActor: was nullptr")); return; }
	UE_LOG(LogTemp, Warning, TEXT("OtherActor: %s , was overlapped EXIT"), *OtherActor->GetName());
	if (OnOverlapExit.IsBound())
	{
		OnOverlapExit.Broadcast(OtherActor);
	}
}
