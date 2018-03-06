// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyBasicMovementComponent.h"
#include "TimerManager.h"
#include "UnrealMathUtility.h"
#include "Runtime/Engine/Classes/GameFramework/FloatingPawnMovement.h"


// Sets default values for this component's properties
UEnemyBasicMovementComponent::UEnemyBasicMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyBasicMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEnemyBasicMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AActor* owner = GetOwner();
	if (owner)
	{
		if (m_timerHandle.IsValid() == false)
			owner->GetWorldTimerManager().SetTimer(m_timerHandle, this, &UEnemyBasicMovementComponent::MakeNewMovementVector, 1.0f);

		UFloatingPawnMovement* movementComponent = owner->FindComponentByClass<UFloatingPawnMovement>();
		if (movementComponent)
		{
			movementComponent->AddInputVector(m_movementDirection, true);
		}
	}
}

void UEnemyBasicMovementComponent::MakeNewMovementVector()
{
	float x, z;

	x = FMath::FRandRange(-0.2f, 0.2f);
	z = FMath::FRandRange(-0.2f, 0.2f);
	m_movementDirection = FVector(x, 0, z);
	UE_LOG(LogTemp, Log, TEXT("Update Motion"));
	m_timerHandle.Invalidate();
}
