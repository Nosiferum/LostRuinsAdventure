// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

#include "LostRuinsAdventureCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<ALostRuinsAdventureCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	
	CapsuleComponent = FindComponentByClass<UCapsuleComponent>();

	if (CapsuleComponent)
		CapsuleComponent->OnComponentHit.AddDynamic(this, &AEnemyCharacter::OnHit);
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyCharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& HitResult)
{
	const AActor* MyOwner = GetOwner();

	if (MyOwner == nullptr) return;

	AController* MyOwnerInstigator = MyOwner->GetInstigatorController();
	const TSubclassOf<UDamageType> DamageTypeClass = UDamageType::StaticClass();

	if (OtherActor && OtherActor != this && OtherActor != MyOwner && OtherActor->ActorHasTag("Player"))
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, MyOwnerInstigator, this, DamageTypeClass);
		Destroy();
	}
}

