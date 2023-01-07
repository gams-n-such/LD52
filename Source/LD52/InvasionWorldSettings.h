// Copyright Denis Maximenko 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "InvasionWorldSettings.generated.h"

/**
 * 
 */
UCLASS()
class LD52_API AInvasionWorldSettings : public AWorldSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float StartingBiomass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AvailableSkills;
};
