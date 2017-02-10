// Fill out your copyright notice in the Description page of Project Settings.

#include "Project_Chained.h"
#include "ProjectileShoot.h"


// Sets default values for this component's properties
UProjectileShoot::UProjectileShoot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

// Called when the game starts
void UProjectileShoot::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UProjectileShoot::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

