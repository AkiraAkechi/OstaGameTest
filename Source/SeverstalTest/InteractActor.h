// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"
#include "SeverstalTestGameMode.h"
#include "InteractActor.generated.h"

UENUM(BlueprintType)
enum class EObjectColor: uint8
{
	OC_Cyan		= 0		UMETA(DisplayName = "Cyan"),
	OC_Magenta	= 1		UMETA(DisplayName = "Magenta"),
	OC_Yellow	= 2		UMETA(DisplayName = "Yellow"),
	OC_Black	= 3		UMETA(DisplayName = "Black"),
	OC_Red		= 4		UMETA(DisplayName = "Red"),
	OC_Green	= 5		UMETA(DisplayName = "Green"),
	OC_Blue		= 6		UMETA(DisplayName = "Blue"),
};

UCLASS()
class SEVERSTALTEST_API AInteractActor : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractActor();


	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EObjectColor ColorEnumValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interaction)
	UAnimMontage* InteractionMontage; 
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category = Interaction)
	bool isChainInteraction = false;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category = Interaction)
	TArray<AActor*> ManagedActors;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category = Interaction)
	TMap<AInteractActor* , bool> InteractionChain;
	UPROPERTY(EditAnywhere, BlueprintreadWrite, Category = Interaction)
	bool bChairInOrder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Interaction)
	int32 InteractionChainIndex;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	ASeverstalTestGameMode* GameModeRef;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnInteract(AActor* Caller);
	virtual void OnInteract_Implementation(AActor* Caller);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void StartFocus();
	virtual void StartFocus_Implementation();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void EndFocus();
	virtual void EndFocus_Implementation();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void ChainInteraction(AActor* Caller);
	virtual void ChainInteraction_Implementation(AActor* Caller);
};
