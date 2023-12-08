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
	//Get Enemy Class 
	class AEnemyAI* Enemy;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void RoundWon(bool bRoundWon);

	UFUNCTION(BlueprintCallable)
	int CalculateEnemyCount(int Enemies);

	UFUNCTION(BlueprintCallable)
	void SpawnSpot(FVector Spawn);

	UFUNCTION(BlueprintImplementableEvent)
	void GetASpawnPoint();

	UPROPERTY(EditAnywhere, Category = "C++")
	TSubclassOf<AEnemyAI> EnemyBP;
	
	int PreviousRoundEnemyStartCount = 0;

private:
	
	//Get Witch (Player) class
	class ATheWitchTrialsCharacter* Witch;
	

	float StartDelay = 3.f;

	void HandleGameStart();
	void SpawnEnemies();

	int SpawnCount = 3;
	
	int PreviousRound = 0;
	FVector Location;
	
	int32 TargetEnemies = 0;
	int32 GetTargetEnemyCount();
};



