// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "GameCharacter.generated.h"

USTRUCT()
struct FCharacterChar {
	GENERATED_USTRUCT_BODY()

	FString Test = "Test";
};

USTRUCT()
struct FCharacterSpeed {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Speed")
		float MaxSpeed = 0.f;
	UPROPERTY(VisibleAnywhere, Category = "Speed")
		float Acceleration = 0.f;
	UPROPERTY(VisibleAnywhere, Category = "Speed")
		float Momentum = 0.f;
};

USTRUCT()
struct FCharacterOffense {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Offense")
		float Power = 0.f;
	UPROPERTY(VisibleAnywhere)
		float Penetration = 0.f;
};

USTRUCT()
struct FCharacterDefense {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere)
		float Armor = 0.f;
	UPROPERTY(VisibleAnywhere)
		float Health = 0.f;
	UPROPERTY(VisibleAnywhere)
		float HealthRegen = 0.f;
};

USTRUCT()
struct FCharacterUtility {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere)
		float Energy = 0.f;
	UPROPERTY(VisibleAnywhere)
		float EnergyRegen = 0.f;
};

USTRUCT()
struct FCharacterAbilities
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere)
		FString Basic = "";
	UPROPERTY(VisibleAnywhere)
		float BasicRate = 0.f;

	UPROPERTY(VisibleAnywhere)
		FString Ability1 = "";
	UPROPERTY(VisibleAnywhere)
		float Ability1_Regen = 0.f;

	UPROPERTY(VisibleAnywhere)
		FString Ability2 = "";
	UPROPERTY(VisibleAnywhere)
		float Ability2_Regen = 0.f;

	UPROPERTY(VisibleAnywhere)
		FString Ability3 = "";
	UPROPERTY(VisibleAnywhere)
		float Ability3_Regen = 0.f;

	UPROPERTY(VisibleAnywhere)
		FString UltimateRegen = "";
	UPROPERTY(VisibleAnywhere)
		float AbilityUltimate_Regen = 0.f;
};

UCLASS()
class PROJECT_CHAINED_API AGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGameCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Stats for character
	
	UPROPERTY(EditAnywhere, Category = "CharacterStats")
		FCharacterChar CharacterChar;

	UPROPERTY(EditAnywhere, Category = "CharacterStats")
		FCharacterSpeed CharacterStats;

	UPROPERTY(EditAnywhere, Category = "CharacterStats")
		FCharacterOffense CharacterOffense;

	UPROPERTY(EditAnywhere, Category = "CharacterStats")
		FCharacterDefense CharacterDefense;

	UPROPERTY(EditAnywhere, Category = "CharacterStats")
		FCharacterUtility CharacterUtility;

	UPROPERTY(EditAnywhere, Category = "CharacterStats")
		FCharacterAbilities CharacterAbilities;
};
