// Copyright Denis Maximenko 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseSkill.generated.h"

UCLASS()
class LD52_API ABaseSkill : public AActor
{
	GENERATED_BODY()

public:
	ABaseSkill();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

};
