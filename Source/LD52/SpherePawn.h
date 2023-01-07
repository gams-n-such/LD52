// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SphericalMovement.h"
#include "SpherePawn.generated.h"

UCLASS()
class LD52_API ASpherePawn : public APawn
{
	GENERATED_BODY()

public:
	ASpherePawn();

	UFUNCTION(BlueprintCallable, Category="ASpherePawn")
	void SetPlanet(APawn* NewPlanet);
	UFUNCTION(BlueprintCallable, Category="ASpherePawn")
	APawn* GetPlanet();
	UFUNCTION(BlueprintCallable, Category="ASpherePawn")
	float GetPlanetRadius();

	UFUNCTION(BlueprintCallable, Category="ASpherePawn")
	void SetLocationOnPlanet(FVector2D Vector);
	UFUNCTION(BlueprintCallable, Category="ASpherePawn")
	FVector2D GetLocationOnPlanet();
	
protected:
	UPROPERTY()
	APawn* Planet;
	UPROPERTY()
	float PlanetRadius;
	UPROPERTY()
	USphericalMovement* SphericalMovement;
	UPROPERTY()
	FVector2D LocationOnSphere;
};
