// Fill out your copyright notice in the Description page of Project Settings.

#include "DestroyActorOnOverlap.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"
#include "PaperSpriteComponent.h"

// Sets default values
ADestroyActorOnOverlap::ADestroyActorOnOverlap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereRadius = 100.0f;
	collisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	collisionSphere->InitSphereRadius(SphereRadius);
	collisionSphere->SetCollisionProfileName("Trigger");
	RootComponent = collisionSphere;

	sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	sprite->AttachTo(RootComponent);

	collisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ADestroyActorOnOverlap::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ADestroyActorOnOverlap::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADestroyActorOnOverlap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebugSphere(GetWorld(), GetActorLocation(), SphereRadius, 20, FColor::Purple, false, -1, 0, 1);
}

void ADestroyActorOnOverlap::OnOverlapBegin(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp,
													int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	// TODO: Change to collide with player and ai players
	if(OtherActor != nullptr && OtherActor != this && OtherComp != nullptr && OtherActor == GetWorld()->GetFirstPlayerController()->AcknowledgedPawn)
	{
		Destroy();
	} 
}
