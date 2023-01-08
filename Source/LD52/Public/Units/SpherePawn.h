// Copyright Denis Maximenko 2023

#pragma once

#include "CoreMinimal.h"
#include "Planet/SphericalMovement.h"
#include "SpherePawn.generated.h"

UCLASS()
class LD52_API ASpherePawn : public APawn
{
	GENERATED_BODY()

public:
	ASpherePawn();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category="ASpherePawn")
	void SetPlanet(AActor* NewPlanet);
	UFUNCTION(BlueprintCallable, Category="ASpherePawn")
	AActor* GetPlanet();
	UFUNCTION(BlueprintCallable, Category="ASpherePawn")
	float GetPlanetRadius();

	UFUNCTION(BlueprintCallable, Category="ASpherePawn")
	void SetLocationOnPlanet(FVector2D Vector);
	UFUNCTION(BlueprintCallable, Category="ASpherePawn")
	FVector2D GetLocationOnPlanet();

	UFUNCTION(BlueprintCallable, Category="ASpherePawn")
	USphericalMovement* GetSphericalMovement();

	UFUNCTION(BlueprintCallable, Category="SphericalMovement")
	void MoveTo(FVector2D Vector2D);
	UFUNCTION(BlueprintCallable, Category="SphericalMovement")
	void MoveTo3D(FVector Vector);
	
protected:
	UPROPERTY()
	AActor* Planet;
	UPROPERTY()
	float PlanetRadius;
	UPROPERTY(BlueprintReadOnly)
	USphericalMovement* SphericalMovement;
	UPROPERTY()
	FVector2D LocationOnPlanet;
};
