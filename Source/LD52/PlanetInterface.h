// Fill out your copyright notice in the Description page of Project Settings.

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