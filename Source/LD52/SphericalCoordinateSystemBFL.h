// Copyright Denis Maximenko 2023

#pragma once

#include "CoreMinimal.h"
#include "SphericalCoordinateSystemBFL.generated.h"


UCLASS()
class LD52_API USphericalCoordinateSystemBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = SphericalCoordinateSystem)
	static FVector2D To2D (FVector Vector3D);

	UFUNCTION(BlueprintCallable, Category = SphericalCoordinateSystem)
    static FVector To3D (FVector2D Vector2D, float Radius);
};
