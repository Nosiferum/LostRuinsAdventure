// Fill out your copyright notice in the Description page of Project Settings.


#include "LostRuinsAIController.h"

#include "Kismet/GameplayStatics.h"

void ALostRuinsAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	SetFocus(PlayerPawn);
	MoveTo(PlayerPawn);
}
