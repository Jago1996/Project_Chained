// Fill out your copyright notice in the Description page of Project Settings.

#include "Project_Chained.h"
#include "GameCharacter.h"
#include "CharacterAbilitiesComponent.h"

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
}

// Called every frame
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input 
void AGameCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	check(InputComponent)

	InputComponent->BindAction("Jump", IE_Pressed, this, &AGameCharacter::JumpPressed);
	InputComponent->BindAction("Jump", IE_Released, this, &AGameCharacter::JumpReleased);
	InputComponent->BindAction("BasicAttack", IE_Pressed, this, &AGameCharacter::BasicAttackPressed);
	InputComponent->BindAction("BasicAttack", IE_Released, this, &AGameCharacter::BasicAttackReleased);
	InputComponent->BindAction("Ability 1", IE_Pressed, this, &AGameCharacter::Ability1Pressed);
	InputComponent->BindAction("Ability 1", IE_Released, this, &AGameCharacter::Ability1Released);
	InputComponent->BindAction("Ability 2", IE_Pressed, this, &AGameCharacter::Ability2Pressed);
	InputComponent->BindAction("Ability 2", IE_Released, this, &AGameCharacter::Ability2Released);
	InputComponent->BindAction("Ability 3", IE_Pressed, this, &AGameCharacter::Ability3Pressed);
	InputComponent->BindAction("Ability 3", IE_Released, this, &AGameCharacter::Ability3Released);
	InputComponent->BindAction("Ability Ultimate", IE_Pressed, this, &AGameCharacter::AbilityUltimatePressed);
	InputComponent->BindAction("Ability Ultimate", IE_Pressed, this, &AGameCharacter::AbilityUltimateReleased);

	InputComponent->BindAxis("MoveXAxis", this, &AGameCharacter::MoveX);
	InputComponent->BindAxis("MoveYAxis", this, &AGameCharacter::MoveY);
	InputComponent->BindAxis("Turn", this, &AGameCharacter::AddControllerYawInput);
	InputComponent->BindAxis("Lookup", this, &AGameCharacter::AddControllerPitchInput);

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

void AGameCharacter::BasicAttackPressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Basic Attack"));
}
void AGameCharacter::BasicAttackReleased()
{
	
}

void AGameCharacter::Ability1Pressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Ability 1!"));
}
void AGameCharacter::Ability1Released()
{
}

void AGameCharacter::Ability2Pressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Ability 2!"));
}
void AGameCharacter::Ability2Released()
{
}

void AGameCharacter::Ability3Pressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Ability 3!"));
}
void AGameCharacter::Ability3Released()
{
}

void AGameCharacter::AbilityUltimatePressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("ULTIMATE ACTIVATED: DIE, DIE, DIE"));
}
void AGameCharacter::AbilityUltimateReleased()
{
}

void AGameCharacter::MoveX(float xPos)
{
	if ((Controller != NULL) && (xPos != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, xPos);
	}
}
void AGameCharacter::MoveY(float yPos)
{
	if ((Controller != NULL) && (yPos != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, yPos);
	}
}