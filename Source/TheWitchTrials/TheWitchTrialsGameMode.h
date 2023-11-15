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

	UFUNCTION(BlueprintCallable)
	int CalculateEnemyCount(int Enemies);

	UPROPERTY(EditAnywhere, Category = "C++")
	TSubclassOf<AEnemyAI> Enemy;
	
	int PreviousRoundEnemyStartCount = 0;

private:
	
	//Get Witch (Player) class
	class ATheWitchTrialsCharacter* Witch;
	//Get Enemy Class 
	class AEnemyAI* Enemy;

	float StartDelay = 3.f;

	void HandleGameStart();
	void SpawnEnemies();

	int SpawnCount = 3;
	
	int PreviousRound = 0;
	FVector Location = FVector(400.f, 400.f, 300.f);
	
	int32 TargetEnemies = 0;
	int32 GetTargetEnemyCount();
};



