// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPP_Coding2GameMode.h"
#include "CPP_Coding2Character.h"
#include "UObject/ConstructorHelpers.h"

ACPP_Coding2GameMode::ACPP_Coding2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
