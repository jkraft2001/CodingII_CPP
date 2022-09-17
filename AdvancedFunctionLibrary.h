// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AdvancedFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTS_API UAdvancedFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Utilities", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "ActorClass"))
	static class AActor* GetNearestActorOfClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, FVector Location, float Radius = 512.f);
	
};
