// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "SeverstalTestGameMode.generated.h"

UCLASS(minimalapi)
class ASeverstalTestGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASeverstalTestGameMode();


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> MainHUDClass;
	UPROPERTY()
	UUserWidget* MainHUDRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> InteractUIClass;
	UPROPERTY()
	UUserWidget* InteractWidgetRef;

	void ShowInteractOverlay();
	void HideInteractOverlay();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Gameplay")
	int GetPlayerHeath();
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void ChangePlayerHealth(int Value);
	UFUNCTION(BlueprintNativeEvent, Category = "Gameplay")
	void GameOver();
	virtual void GameOver_Implementation();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int PlayerHealth;
};



