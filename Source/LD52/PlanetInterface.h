// Copyright Denis Maximenko 2023

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlanetInterface.generated.h"

UINTERFACE()
class UPlanetInterface : public UInterface
{
	GENERATED_BODY()
};

class LD52_API IPlanetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	float GetRadius();
};
