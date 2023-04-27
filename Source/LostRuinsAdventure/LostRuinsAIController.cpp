// Fill out your copyright notice in the Description page of Project Settings.


#include "LostRuinsAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void ALostRuinsAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior)
		RunBehaviorTree(AIBehavior);

	GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
}
