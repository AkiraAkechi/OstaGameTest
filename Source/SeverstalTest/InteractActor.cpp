// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractActor.h"
#include "Components/PrimitiveComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AInteractActor::AInteractActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AInteractActor::BeginPlay()
{
	Super::BeginPlay();

	GameModeRef = Cast<ASeverstalTestGameMode>(GetWorld()->GetAuthGameMode());
}

// Called every frame
void AInteractActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractActor::OnInteract_Implementation(AActor* Caller)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Green, TEXT("Interact"));
}

void AInteractActor::StartFocus_Implementation()
{
	Mesh->SetRenderCustomDepth(true);
	if(GameModeRef)
	{	GameModeRef->ShowInteractOverlay();	}
}

void AInteractActor::EndFocus_Implementation()
{
	Mesh->SetRenderCustomDepth(false);
	if (GameModeRef)
	{	GameModeRef->HideInteractOverlay();	}
}

void AInteractActor::ChainInteraction_Implementation(AActor* Caller)
{
}

