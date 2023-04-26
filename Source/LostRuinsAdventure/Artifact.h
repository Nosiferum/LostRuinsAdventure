// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Artifact.generated.h"

UCLASS()
class LOSTRUINSADVENTURE_API AArtifact : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArtifact();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UFUNCTION()
	void TakeArtifact(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	class UCapsuleComponent* CapsuleComponent;

};
