// Copyright Denis Maximenko 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"
#include "InvasionWorldSettings.generated.h"

class ABaseSkill;
class USoundBase;

/**
 * 
 */
UCLASS()
class LD52_API AInvasionWorldSettings : public AWorldSettings
{
	GENERATED_BODY()

public:
	AInvasionWorldSettings();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float StartingBiomass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName NextLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USoundBase* Music;
};
