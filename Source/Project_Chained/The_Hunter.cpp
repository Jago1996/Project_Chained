// Fill out your copyright notice in the Description page of Project Settings.

#include "Project_Chained.h"
#include "ProjectileShoot.h"
#include "The_Hunter.h"


// Sets default values
AThe_Hunter::AThe_Hunter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProjectileShoot = CreateDefaultSubobject<UProjectileShoot>(FName("ProjectileShoot"));
}

// Called when the game starts or when spawned
void AThe_Hunter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AThe_Hunter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AThe_Hunter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	InputComponent->BindAction("BasicAttack", IE_Pressed, this, &AThe_Hunter::BasicAttackPressed);
	InputComponent->BindAction("BasicAttack", IE_Released, this, &AThe_Hunter::BasicAttackReleased);
	InputComponent->BindAction("Ability 1", IE_Pressed, this, &AThe_Hunter::Ability1Pressed);
	InputComponent->BindAction("Ability 1", IE_Released, this, &AThe_Hunter::Ability1Released);
	InputComponent->BindAction("Ability 2", IE_Pressed, this, &AThe_Hunter::Ability2Pressed);
	InputComponent->BindAction("Ability 2", IE_Released, this, &AThe_Hunter::Ability2Released);
	InputComponent->BindAction("Ability 3", IE_Pressed, this, &AThe_Hunter::Ability3Pressed);
	InputComponent->BindAction("Ability 3", IE_Released, this, &AThe_Hunter::Ability3Released);
	InputComponent->BindAction("Ability Ultimate", IE_Pressed, this, &AThe_Hunter::AbilityUltimatePressed);
	InputComponent->BindAction("Ability Ultimate", IE_Pressed, this, &AThe_Hunter::AbilityUltimateReleased);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AThe_Hunter::JumpPressed);
	InputComponent->BindAction("Jump", IE_Released, this, &AThe_Hunter::JumpReleased);
	InputComponent->BindAxis("MoveXAxis", this, &AThe_Hunter::MoveX);
	InputComponent->BindAxis("MoveYAxis", this, &AThe_Hunter::MoveY);
	InputComponent->BindAxis("Turn", this, &AThe_Hunter::AddControllerYawInput);
	InputComponent->BindAxis("Lookup", this, &AThe_Hunter::AddControllerPitchInput);
}

void AThe_Hunter::JumpPressed()
{
	ACharacter::Jump();
}
void AThe_Hunter::JumpReleased()
{
	ACharacter::StopJumping();
}
void AThe_Hunter::MoveX(float xPos)
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
void AThe_Hunter::MoveY(float yPos)
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

void AThe_Hunter::BasicAttackPressed()
{
	ProjectileShoot->Shoot();
}
void AThe_Hunter::BasicAttackReleased()
{

}
void AThe_Hunter::Ability1Pressed()
{
	
}
void AThe_Hunter::Ability1Released()
{
}
void AThe_Hunter::Ability2Pressed()
{
	
}
void AThe_Hunter::Ability2Released()
{
}
void AThe_Hunter::Ability3Pressed()
{
	
}
void AThe_Hunter::Ability3Released()
{
}
void AThe_Hunter::AbilityUltimatePressed()
{
	
}
void AThe_Hunter::AbilityUltimateReleased()
{
}