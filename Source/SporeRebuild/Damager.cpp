// Fill out your copyright notice in the Description page of Project Settings.

#include "Damager.h"
#include "Attackable.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"


// Sets default values for this component's properties
UDamager::UDamager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDamager::BeginPlay()
{
	Super::BeginPlay();

	AActor* owner = GetOwner();
	if (owner)
	{
		UCapsuleComponent* capsule = owner->FindComponentByClass<UCapsuleComponent>();
		if (capsule)
		{
			capsule->OnComponentBeginOverlap.AddDynamic(this,& UDamager::BeginOverlap);
		}

	}

	
}


// Called every frame
void UDamager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDamager::BeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UAttackable* attackable = OtherActor->FindComponentByClass<UAttackable>();
	if (attackable)
	{
		attackable->DealDamage(Damage); 
	}
}

