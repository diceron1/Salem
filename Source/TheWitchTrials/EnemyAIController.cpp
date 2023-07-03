// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"


void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();

    //Get Pawn actor and set AI's focus to it.

    //Pawn
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    //focus
    SetFocus(PlayerPawn);

    
}

void AEnemyAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    //MoveTo Player
    MoveToActor(PlayerPawn, 300, false);
}
