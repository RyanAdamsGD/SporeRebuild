// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EnemyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SPOREREBUILD_API UEnemyGameInstance : public UGameInstance
{
	GENERATED_BODY()

private:
	TArray<UBlueprint> AvailableEnemyBPs;
protected:
	virtual void OnStart();


	
	
};
