// Copyright Epic Games, Inc. All Rights Reserved.

#include "SeverstalTestGameMode.h"
#include "SeverstalTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASeverstalTestGameMode::ASeverstalTestGameMode()
{
	PlayerHealth = 6;
	
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_PlayerCharacter"));
 
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ASeverstalTestGameMode::BeginPlay()
{
	if (MainHUDClass)
	{	
		MainHUDRef = CreateWidget<UUserWidget>(GetWorld(), MainHUDClass);
		if (MainHUDRef)
		{
			MainHUDRef->AddToViewport();
		}
	}

	if (InteractUIClass)
	{	InteractWidgetRef = CreateWidget<UUserWidget>(GetWorld(), InteractUIClass);	}
}

void ASeverstalTestGameMode::ShowInteractOverlay()
{
	if (InteractWidgetRef)
	{
		InteractWidgetRef->AddToViewport();
	}
}

void ASeverstalTestGameMode::HideInteractOverlay()
{
	if (InteractWidgetRef)
	{
		InteractWidgetRef->RemoveFromViewport();
	}
}

int ASeverstalTestGameMode::GetPlayerHeath()
{	
	return PlayerHealth;
}

void ASeverstalTestGameMode::ChangePlayerHealth(int Value)
{	
	PlayerHealth = PlayerHealth - Value;
	if (PlayerHealth <= 0)
	{
		GameOver();
	}
}

void ASeverstalTestGameMode::GameOver_Implementation()
{
}

