// Copyright Denis Maximenko 2023


#include "Planet/SphericalMovement.h"
#include "Units/SpherePawn.h"

USphericalMovement::USphericalMovement()
{
	PrimaryComponentTick.bCanEverTick = true;
	IsMoving = false;
	MinimalDistance = 1;
	
}

void USphericalMovement::TickComponent(float DeltaTime, ELevelTick TickType,
										FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsMoving)
	{
		const FVector2D CurrentLocation = OwnerSpherePawn->GetLocationOnPlanet();
		const FVector2D NormalizeDirection = (TargetLocation - CurrentLocation)/
			FVector2D::Distance(TargetLocation, CurrentLocation);
		const FVector2D NewLocation = CurrentLocation + NormalizeDirection * Speed * DeltaTime;
		
		OwnerSpherePawn->SetLocationOnPlanet(NewLocation);
		IsMoving = FVector2D::Distance(CurrentLocation,TargetLocation) > MinimalDistance;
	}
	
}

void USphericalMovement::SetSpeed(float NewSpeed)
{
	Speed = NewSpeed;
}

void USphericalMovement::SetOwnerSpherePawn(ASpherePawn* NewOwnerSpherePawn)
{
	OwnerSpherePawn = NewOwnerSpherePawn;
}

void USphericalMovement::MoveTo(FVector2D Vector2D)
{
	TargetLocation = Vector2D;
	IsMoving = true;
}

