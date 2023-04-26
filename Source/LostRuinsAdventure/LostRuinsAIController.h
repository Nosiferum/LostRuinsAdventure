// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "LostRuinsAIController.generated.h"

/**
 * 
 */
UCLASS()
class LOSTRUINSADVENTURE_API ALostRuinsAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	APawn* PlayerPawn;
};
