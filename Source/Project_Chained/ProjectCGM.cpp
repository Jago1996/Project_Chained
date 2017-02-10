// Fill out your copyright notice in the Description page of Project Settings.

#include "Project_Chained.h"
#include "The_Hunter.h"
#include "ProjectCGM.h"


AProjectCGM::AProjectCGM()
{
	DefaultPawnClass = AThe_Hunter::StaticClass();
}
