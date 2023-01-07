// Copyright Denis Maximenko 2023


#include "SphericalMovement.h"
#include "SpherePawn.h"
#include "Kismet/KismetMathLibrary.h"


USphericalMovement::USphericalMovement()
{
	PrimaryComponentTick.bCanEverTick = true;
	OwnerSpherePawn = Cast<ASpherePawn>(GetOwner());
	IsMoving = false;
	MinimalDistance = 0.1f;
}

void USphericalMovement::TickComponent(float DeltaTime, ELevelTick TickType,
										FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsMoving)
	{
		const FVector2D CurrentLocation = OwnerSpherePawn->GetLocationOnPlanet();
		const FVector CurrentLocation3D = FVector(CurrentLocation.X, CurrentLocation.Y, 0);
		const FVector TargetPosition3D = FVector(CurrentLocation.X, CurrentLocation.Y, 0);
		const FVector NewLocation3D = UKismetMathLibrary:: VLerp(CurrentLocation3D, TargetPosition3D, Speed * DeltaTime);
		const FVector2D NewLocation = FVector2D(NewLocation3D.X,NewLocation3D.X);
		OwnerSpherePawn->SetLocationOnPlanet(NewLocation);

		IsMoving = CurrentLocation.Distance(CurrentLocation,NewLocation) > MinimalDistance;
	}
	
}

void USphericalMovement::SetSpeed(float NewSpeed)
{
	Speed = NewSpeed;
}

void USphericalMovement::MoveTo(FVector2D Vector2D)
{
	TargetPosition = Vector2D;
	IsMoving = true;
}

