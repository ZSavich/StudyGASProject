// Copyright Epic Games, Inc. All Rights Reserved.

#include "StudyGASProjectGameMode.h"
#include "StudyGASProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStudyGASProjectGameMode::AStudyGASProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
