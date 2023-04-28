// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LostRuinsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class LOSTRUINSADVENTURE_API ULostRuinsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TArray<AActor*> ArtifactList = TArray<AActor*>();
	
};
