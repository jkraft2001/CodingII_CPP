// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Human.generated.h"

UCLASS()
class CPP_CODING2_API AHuman : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHuman();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FString PlayerName = "Ted";

	UPROPERTY(EditAnywhere) 
	float Speed = 10;

	// todo replace with enum
	UPROPERTY(EditAnywhere)
	int32 ElementalType = 0;	// 0=Fire, 1=Ice, 2=Candy, 3=Slime

	UPROPERTY(EditAnywhere)
	FString Elements[4];

	UPROPERTY(EditAnywhere)
	float Health = 10;

	UPROPERTY(EditAnywhere)
	float Damage = 4;


	// declaring a public function that returns nothing
	UFUNCTION(BlueprintCallable)		// is that right? Blueprint callable.
	void RandomizeHuman();

	UFUNCTION(BlueprintCallable)
	void TakeDamage(AHuman* attacker);

	UFUNCTION(BlueprintCallable)
	float DamageMultiplier(int32 GivenElemType);

	UFUNCTION(BlueprintCallable) float GetHealth() const;

	UFUNCTION(BlueprintCallable)void SetHealth(const float By);

};

/*
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Human.generated.h"

UCLASS();
class CPP_CODING2_API AHuman : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHuman();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FString PlayerName = "Ash's Pikachu";

	UPROPERTY(EditAnywhere)
	float speed = 10;

	UPROPERTY(EditAnywhere)
	int32 elementalType = 0;

	UPROPERTY(EditAnywhere)
	FString Elements[4];

	UPROPERTY(EditAnywhere)
	float health = 10;

	UPROPERTY(EditAnywhere)
	float damage = 4;

	UPROPERTY(EditAnywhere)
	float givenDamage = 4;

	UFUNCTION(BlueprintCallable)
	void RandomizeHuman();

	UFUNCTION(BlueprintCallable)
	void TakeDamage(AHuman* attacker);

	UFUNCTION(BlueprintCallable)
	float DamageMultiplier(int32 givenElemType);

	
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AContoller* EventInstigator, AActor* DamageCauser) override;

	float Health = 0;
	float DefaultHealth = 100;	
	
};*/