// Copyright Epic Games, Inc. All Rights Reserved.

#include "TheWitchTrialsGameMode.h"
#include "TheWitchTrialsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATheWitchTrialsGameMode::ATheWitchTrialsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
