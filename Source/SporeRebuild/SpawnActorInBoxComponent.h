// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnActorInBoxComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPOREREBUILD_API USpawnActorInBoxComponent : public UActorComponent
{
	GENERATED_BODY()

  private:
	AActor *m_owner;
	float m_currentTime;

	UPROPERTY(EditAnywhere)
	float Duration;

	UPROPERTY(EditAnywhere)
	UClass *ActorToSpawn;

  public:
	// Sets default values for this component's properties
	USpawnActorInBoxComponent();

  protected:
	// Called when the game starts
	virtual void BeginPlay() override;

  public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	void SpawnNewActorInBoundingBox();
};
