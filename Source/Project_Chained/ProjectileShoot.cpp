// Fill out your copyright notice in the Description page of Project Settings.

#include "Project_Chained.h"
#include "TestActor.h"
#include "ProjectileShoot.h"


// Sets default values for this component's properties
UProjectileShoot::UProjectileShoot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

// Called when the game starts
void UProjectileShoot::BeginPlay()
{
	Super::BeginPlay();

	
}


// Called every frame
void UProjectileShoot::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UProjectileShoot::Shoot() 
{

	UWorld* const World = GetWorld();
	if (World)
	{
		const FVector& Location = GetOwner()->GetActorLocation() + FVector(0, 0, 2);
		const FActorSpawnParameters& SpawnParameters = FActorSpawnParameters();
		const FRotator& Rotation = FRotator();
		GetWorld()->SpawnActor<ATestActor>(ATestActor::StaticClass(), Location, Rotation, SpawnParameters);
	}
}
