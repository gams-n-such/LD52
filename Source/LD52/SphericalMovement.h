// Copyright Denis Maximenko 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SphericalMovement.generated.h"


class ASpherePawn;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class LD52_API USphericalMovement : public UActorComponent
{
	GENERATED_BODY()

public:
	USphericalMovement();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category="SphericalMovement")
	void SetSpeed(float NewSpeed);
	UFUNCTION(BlueprintCallable, Category="SphericalMovement")
	float GetSpeed() const {return Speed; }

	UFUNCTION(BlueprintCallable, Category="SphericalMovement")
	void MoveTo(FVector2D Vector2D);

protected:
	UPROPERTY(BlueprintReadWrite, Category="SphericalMovement")
	ASpherePawn* OwnerSpherePawn;
	UPROPERTY(BlueprintReadWrite, Category="SphericalMovement")
	float Speed;
	UPROPERTY(BlueprintReadWrite, Category="SphericalMovement")
	FVector2D TargetPosition;
	UPROPERTY(BlueprintReadWrite, Category="SphericalMovement")
	bool IsMoving;
	UPROPERTY(BlueprintReadWrite, Category="SphericalMovement")
	float MinimalDistance;
};
