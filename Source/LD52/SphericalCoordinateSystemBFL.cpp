// Copyright Denis Maximenko 2023


#include "SphericalCoordinateSystemBFL.h"

#include "Kismet/KismetMathLibrary.h"

FVector2D USphericalCoordinateSystemBFL::To2D(FVector Vector3D)
{
	const float Zenith = UKismetMathLibrary::Atan(
		UKismetMathLibrary::Sqrt(Vector3D.X*Vector3D.X + Vector3D.Y*Vector3D.Y)
		/Vector3D.Z);
	const float Azimuth = UKismetMathLibrary::Atan(Vector3D.Y / Vector3D.X);
	return FVector2D(Zenith,Azimuth);
}

FVector USphericalCoordinateSystemBFL::To3D(FVector2D Vector2D, float Radius)
{
	FVector Vector;
	Vector.X = Radius * UKismetMathLibrary::Sin(Vector2D.X) * UKismetMathLibrary::Cos(Vector2D.Y);
	Vector.Y = Radius * UKismetMathLibrary::Sin(Vector2D.X) * UKismetMathLibrary::Sin(Vector2D.Y);
	Vector.Z = Radius * UKismetMathLibrary::Cos(Vector2D.X);
	return Vector;
}