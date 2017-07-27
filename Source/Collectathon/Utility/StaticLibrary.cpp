// 27th July 2017 - Team Headless Sloth

#include "Collectathon/Utility/StaticLibrary.h"

void UStaticLibrary::PointOnCircle(float radius, float angle, FVector& CentrePoint, FVector& OutPoint)
{
	//x = radius * cos(angle)
	//y = radius * sin(angle)

	float DegToRad = angle * (PI / 180.0f);
	OutPoint.X = CentrePoint.X + (radius * FMath::Cos(DegToRad));
	OutPoint.Y = CentrePoint.Y + (radius * FMath::Sin(DegToRad));
	OutPoint.Z = CentrePoint.Z;
}




