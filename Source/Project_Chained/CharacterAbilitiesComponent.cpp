// Fill out your copyright notice in the Description page of Project Settings.

#include "Project_Chained.h"
#include "CharacterAbilitiesComponent.h"


// Sets default values for this component's properties
UCharacterAbilitiesComponent::UCharacterAbilitiesComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UCharacterAbilitiesComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UCharacterAbilitiesComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
}

void UCharacterAbilitiesComponent::BasicAttack()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
}

void UCharacterAbilitiesComponent::Ability1()
{
}

void UCharacterAbilitiesComponent::Ability2()
{
}

void UCharacterAbilitiesComponent::Ability3()
{
}

void UCharacterAbilitiesComponent::AbilityUltimate()
{
}

