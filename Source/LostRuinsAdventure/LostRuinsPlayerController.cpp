// Fill out your copyright notice in the Description page of Project Settings.


#include "LostRuinsPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void ALostRuinsPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALostRuinsPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	
	if (bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);

		if (WinScreen)
			WinScreen->AddToViewport();
		
		GetWorldTimerManager().SetTimer(RestartTimer, this, &ALostRuinsPlayerController::QuitGameAfterDelay , RestartDelay);
		
	}

	else
	{
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);

		if (LoseScreen)
			LoseScreen->AddToViewport();
		
		GetWorldTimerManager().SetTimer(RestartTimer, this, &ALostRuinsPlayerController::RestartLevel , RestartDelay);
	}
	
	
}

void ALostRuinsPlayerController::QuitGameAfterDelay() const
{
	UKismetSystemLibrary::QuitGame(this, GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, false);
}


