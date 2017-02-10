// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "The_Hunter.generated.h"

class UProjectileShoot;

UCLASS()
class PROJECT_CHAINED_API AThe_Hunter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AThe_Hunter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void JumpPressed();
	void JumpReleased();
	void MoveX(float xPos);
	void MoveY(float yPos);

	void BasicAttackPressed();
	void BasicAttackReleased();
	void Ability1Pressed();
	void Ability1Released();
	void Ability2Pressed();
	void Ability2Released();
	void Ability3Pressed();
	void Ability3Released();
	void AbilityUltimatePressed();
	void AbilityUltimateReleased();

	UProjectileShoot* ProjectileShoot;
};
