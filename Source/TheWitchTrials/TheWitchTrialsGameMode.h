// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TheWitchTrialsGameMode.generated.h"

UCLASS(minimalapi)
class ATheWitchTrialsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATheWitchTrialsGameMode();

	void ActorDied(AActor* DeadActor);
	
	void BeginPlay();

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void RoundWon(bool bRoundWon);

private:

	//Get Witch (Player) class
	class ATheWitchTrialsCharacter* Witch;

	float StartDelay = 3.f;

	void HandleGameStart();

	int32 TargetEnemies = 0;
	int32 GetTargetEnemyCount();
};



