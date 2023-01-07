// Fill out your copyright notice in the Description page of Project Settings.


#include "SpherePawn.h"

#include "PlanetInterface.h"
#include "SphericalCoordinateSystemBFL.h"


ASpherePawn::ASpherePawn()
	: LocationOnSphere (0,0)
{
	PrimaryActorTick.bCanEverTick = true;
	SphericalMovement =  CreateDefaultSubobject<USphericalMovement>(TEXT("SphericalMovement"));
}

void ASpherePawn::SetPlanet(APawn* NewPlanet)
{
	Planet = NewPlanet;
	PlanetRadius = IPlanetInterface::Execute_GetRadius(NewPlanet);
}

APawn* ASpherePawn::GetPlanet()
{
	return Planet;
}

float ASpherePawn::GetPlanetRadius()
{
	return PlanetRadius;
}

void ASpherePawn::SetLocationOnPlanet(FVector2D Vector2D)
{
	LocationOnSphere = Vector2D;
	const FVector SpherePosition = USphericalCoordinateSystemBFL::To3D(Vector2D,PlanetRadius);
	const FVector NewPosition = Planet->GetActorLocation() + SpherePosition;
	SetActorLocation(NewPosition);
}

FVector2D ASpherePawn::GetLocationOnPlanet()
{
	return USphericalCoordinateSystemBFL::To2D(GetActorLocation());
}

