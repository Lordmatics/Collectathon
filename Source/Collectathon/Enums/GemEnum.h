// 27th July 2017 - Team Headless Sloth

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)        //"BlueprintType" is essential specifier
enum class EGemType : uint8
{
	E_GemA = 1			UMETA(DisplayName = "Gem_A"),
	E_GemB = 5			UMETA(DisplayName = "Gem_B"),
	E_GemC = 10			UMETA(DisplayName = "Gem_C"),
	E_GemD = 25			UMETA(DisplayName = "Gem_D"),
	E_GemE = 50			UMETA(DisplayName = "Gem_E"),
	E_GemF = 100		UMETA(DisplayName = "Gem_F"),
	E_GemG = 250		UMETA(DisplayName = "Gem_G")
};

/**
 * 
 */
class COLLECTATHON_API GemEnum
{
public:
	GemEnum();
	~GemEnum();
};
