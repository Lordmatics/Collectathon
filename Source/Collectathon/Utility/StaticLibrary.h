// 27th July 2017 - Team Headless Sloth

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StaticLibrary.generated.h"

/**
 * 
 */
UCLASS()
class COLLECTATHON_API UStaticLibrary : public UObject
{
	GENERATED_BODY()

public:
		static void PointOnCircle(float radius, float angle, FVector& CentrePoint, FVector& OutPoint);
	
	
};
