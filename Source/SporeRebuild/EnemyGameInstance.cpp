// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyGameInstance.h"
#include "Engine/World.h"

void UEnemyGameInstance::OnStart()
{
	Super::OnStart();

	auto world = GetWorld();
	if (world)
	{
		auto mode = world->GetAuthGameMode();
		
	}
}
