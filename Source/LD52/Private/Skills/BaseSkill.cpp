// Copyright Denis Maximenko 2023


#include "Skills/BaseSkill.h"


ABaseSkill::ABaseSkill()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseSkill::BeginPlay()
{
	Super::BeginPlay();

}

void ABaseSkill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
