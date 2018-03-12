// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnActorInBoxComponent.h"

// Sets default values for this component's properties
USpawnActorInBoxComponent::USpawnActorInBoxComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void USpawnActorInBoxComponent::BeginPlay()
{
	Super::BeginPlay();

	m_owner = GetOwner();
}

// Called every frame
void USpawnActorInBoxComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (m_owner != nullptr)
	{
		m_currentTime += DeltaTime;

		if (m_currentTime > Duration)
		{
			SpawnNewActorInBoundingBox();
			m_currentTime = 0;
		}
	}
}

void USpawnActorInBoxComponent::SpawnNewActorInBoundingBox()
{
	if (m_owner != nullptr)
	{
		FBox boundingBox = m_owner->GetComponentsBoundingBox(false);

		FActorSpawnParameters spawnParams;
		spawnParams.Owner = m_owner;
		spawnParams.Instigator = m_owner->GetInstigator();	

		FVector randomLocation = FMath::RandPointInBox(boundingBox);

		// spawn actor
		AActor *resultActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, randomLocation, FRotator::ZeroRotator, spawnParams);
	}
}
