// Copyright Denis Maximenko 2023


#include "Planet/SphericalCoordinateSystemBFL.h"

#include "Kismet/KismetMathLibrary.h"

FVector2D USphericalCoordinateSystemBFL::To2D(FVector Vector3D)
{
	const float Zenith =
		UKismetMathLibrary::RadiansToDegrees(
			UKismetMathLibrary::Atan(
				UKismetMathLibrary::Sqrt(
					Vector3D.X * Vector3D.X + Vector3D.Y * Vector3D.Y
					) /
				Vector3D.Z
			)
		);
				
	float Azimuth =
		UKismetMathLibrary::RadiansToDegrees(
			UKismetMathLibrary::Atan(Vector3D.Y / Vector3D.X)
		);
	if (Vector3D.X <= 0.0f)
	{
		Azimuth = (180.0f - FMath::Abs(Azimuth)) * FMath::Sign(Vector3D.Y);
	}

	return FVector2D(Zenith,Azimuth);
}

FVector USphericalCoordinateSystemBFL::To3D(FVector2D Vector2D, float Radius)
{
	const float Zenith = UKismetMathLibrary::DegreesToRadians(Vector2D.X);
	const float Azimuth = UKismetMathLibrary::DegreesToRadians(Vector2D.Y);
	FVector Vector;
	Vector.X = Radius * UKismetMathLibrary::Sin(Zenith) * UKismetMathLibrary::Cos(Azimuth);
	Vector.Y = Radius * UKismetMathLibrary::Sin(Zenith) * UKismetMathLibrary::Sin(Azimuth);
	Vector.Z = Radius * UKismetMathLibrary::Cos(Zenith);
	return Vector;
}