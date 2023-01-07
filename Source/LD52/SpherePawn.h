// Copyright Denis Maximenko 2023

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
	virtual void BeginPlay() override;

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

	UFUNCTION(BlueprintCallable, Category="ASpherePawn")
	USphericalMovement* GetSphericalMovement();
	
protected:
	UPROPERTY()
	APawn* Planet;
	UPROPERTY()
	float PlanetRadius;
	UPROPERTY()
	USphericalMovement* SphericalMovement;
	UPROPERTY()
	FVector2D LocationOnPlanet;
};
