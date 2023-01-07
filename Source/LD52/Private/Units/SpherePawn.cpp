// Copyright Denis Maximenko 2023


#include "Units/SpherePawn.h"

#include "Planet/PlanetInterface.h"
#include "Planet/SphericalCoordinateSystemBFL.h"
#include "Kismet/KismetMathLibrary.h"


ASpherePawn::ASpherePawn()
	: LocationOnPlanet (0,0)
{
	PrimaryActorTick.bCanEverTick = true;
	SphericalMovement =  CreateDefaultSubobject<USphericalMovement>(TEXT("SphericalMovement"));
}

void ASpherePawn::BeginPlay()
{
	Super::BeginPlay();
	SphericalMovement->SetOwnerSpherePawn(this);
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
	LocationOnPlanet = Vector2D;
	const FVector SpherePosition = USphericalCoordinateSystemBFL::To3D(Vector2D, PlanetRadius);
	const FVector NewLocation = Planet->GetActorLocation() + SpherePosition;
	const FVector Direction = NewLocation -GetActorLocation();
	const FRotator ActorRotator = UKismetMathLibrary::MakeRotFromZX(SpherePosition - Planet->GetActorLocation() , Direction);
	SetActorLocationAndRotation(NewLocation, ActorRotator);
}

FVector2D ASpherePawn::GetLocationOnPlanet()
{
	return LocationOnPlanet;
}

USphericalMovement* ASpherePawn::GetSphericalMovement()
{
	return SphericalMovement;
}
