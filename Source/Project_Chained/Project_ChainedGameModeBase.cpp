// Fill out your copyright notice in the Description page of Project Settings.

#include "Project_Chained.h"
#include "Project_ChainedGameModeBase.h"
#include "GameCharacter.h"

AProject_ChainedGameModeBase::AProject_ChainedGameModeBase()
{
	DefaultPawnClass = AGameCharacter::StaticClass();
}