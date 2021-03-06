// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SporeRebuildGameMode.h"
#include "SporeRebuildCharacter.h"

ASporeRebuildGameMode::ASporeRebuildGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = ASporeRebuildCharacter::StaticClass();	
}
