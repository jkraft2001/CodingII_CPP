// Fill out your copyright notice in the Description page of Project Settings.


#include "AdvancedFunctionLibrary.h"
#include <Kismet/GameplayStatics.h>

class AActor* UAdvancedFunctionLibrary::GetNearestActorOfClass(const UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, FVector Location, float Radius /*=512.f*/) {
	AActor* NearestActor = NULL;
	float NearestDistance = Radius;

	TArray<AActor*> OutActors
		UGameplayStatics::GetAllActorsOfClass(WorldContextObject, ActorClass, OutActors);

	for (AActor* Actor : OutActors) {
		float Distance = FVector::Distance(Location, Actor->GetActorLocation());

		if (Distance < NearestDistance) {
			NearestActor = Actor;
			NearestDistance = Distance;
		}
	}

	return NearestActor;
}

