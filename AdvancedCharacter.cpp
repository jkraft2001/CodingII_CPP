// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedCharacter.h"
#include <Componennts/TextRenderComponent.h>
#include <DrawDebugHelpers.h>

// Sets default values
AAdvancedCharacter::AAdvancedCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AlertTextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Alert"));
	if (AlertTextComponent) {
		AlertTextComponent->SetupAttachment(GetMesh(), "head");
	}

}

void GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const override {
	Location = GetMesh()->GetSocketLocation(EyeSocketName);
	Rotation = GetMesh()->GetSocketRotation(EyeSocketName);
}

void AAdvancedCharacter::FellOutOfWorld(const class UDamageType& damageType) {
	OnFellOutOfWorld();
}

// Called when the game starts or when spawned
void AAdvancedCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAdvancedCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Log, TEXT("Hello world!"));

	AActor* OtherActor = NULL;
	FVector ActorLocation;

	if (OtherActor != NULL) {
		ActorLocation = OtherActor->GetActorLocation();
	}

	FVector ActorLocation = GetActorLocation();

	DrawDebugSphere(GetWorld(), ActorLocation, 100.f, 16, FColor::Red);

}

// Called to bind functionality to input
void AAdvancedCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

