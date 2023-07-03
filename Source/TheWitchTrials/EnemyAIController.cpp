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
