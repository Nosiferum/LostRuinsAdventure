// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LostRuinsPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LOSTRUINSADVENTURE_API ALostRuinsPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void GameHasEnded(AActor* EndGameFocus, bool bIsWinner) override;


private:
	void QuitGameAfterDelay() const;
	
private:
	UPROPERTY(EditAnywhere, Category="End Game")
	float RestartDelay = 2.f;
	UPROPERTY(EditAnywhere, Category="End Game")
	TSubclassOf<UUserWidget> LoseScreenClass;
	UPROPERTY(EditAnywhere, Category="End Game")
	TSubclassOf<UUserWidget> WinScreenClass;

	FTimerHandle RestartTimer;
	
};
