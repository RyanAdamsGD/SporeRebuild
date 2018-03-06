// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyBasicMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPOREREBUILD_API UEnemyBasicMovementComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	FVector m_movementDirection;
	FTimerHandle m_timerHandle;
public:	
	// Sets default values for this component's properties
	UEnemyBasicMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void MakeNewMovementVector();
		
	
};
