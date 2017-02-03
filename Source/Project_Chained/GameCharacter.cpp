// Fill out your copyright notice in the Description page of Project Settings.

#include "Project_Chained.h"
#include "GameCharacter.h"

// Sets default values
AGameCharacter::AGameCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	SetupInputComponent();
}

// Called every frame
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input 
//TODO Add Movement
void AGameCharacter::SetupInputComponent()
{
	InputComponent = FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("Jump", IE_Pressed, this, &AGameCharacter::JumpPressed);
		InputComponent->BindAction("Jump", IE_Released, this, &AGameCharacter::JumpReleased);
		//InputComponent->BindAxis("MoveXAxis", this, &AGameCharacter::MoveX);
		//InputComponent->BindAxis("MoveYAxis", this, &AGameCharacter::MoveY);
	}
}

//TODO Jump works, but need to add functionality
void AGameCharacter::JumpPressed()
{
	ACharacter::Jump();
}
void AGameCharacter::JumpReleased()
{
	ACharacter::StopJumping();
}

