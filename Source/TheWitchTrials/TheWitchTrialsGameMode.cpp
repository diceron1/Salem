// Copyright Epic Games, Inc. All Rights Reserved.

#include "TheWitchTrialsGameMode.h"
#include "TheWitchTrialsCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "EnemyAI.h"
#include "Kismet/GameplayStatics.h"


ATheWitchTrialsGameMode::ATheWitchTrialsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void ATheWitchTrialsGameMode::ActorDied(AActor* DeadActor)
{
	if(DeadActor == Witch)
	{
		RoundWon(false);
	}
	else if(AEnemyAI* DeadEnemy = Cast<AEnemyAI>(DeadActor))
	{
		//ToDo DeadEnemy->HandleDestruction();
		TargetEnemies--;
		if(TargetEnemies == 0)
		{
			RoundWon(true);
		}
	}
}

void ATheWitchTrialsGameMode::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();
}

void ATheWitchTrialsGameMode::HandleGameStart()
{
	TargetEnemies = GetTargetEnemyCount();
	Witch = Cast<ATheWitchTrialsCharacter>(UGameplayStatics::GetPlayerPawn(this,0));

	StartGame();

	//Add Player Controller code for Downed State
}

int32 ATheWitchTrialsGameMode::GetTargetEnemyCount()
{
	TArray<AActor*> Enemies;
	UGameplayStatics::GetAllActorsOfClass(this,AEnemyAI::StaticClass(), Enemies);
	return Enemies.Num();
}

