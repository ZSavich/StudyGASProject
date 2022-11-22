// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/SGPPlayerController.h"
#include "AbilitySystemComponent.h"
#include "Core/SGPPlayerState.h"

// Server Only
void ASGPPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (ASGPPlayerState* PS = GetPlayerState<ASGPPlayerState>())
	{
		// Init ASC with PS (OwnerActor) and our new Pawn (AvatarActor)
		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, InPawn);
	}
}
