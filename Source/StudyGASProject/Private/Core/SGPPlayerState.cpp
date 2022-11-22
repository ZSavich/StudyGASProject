// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/SGPPlayerState.h"
#include "Characters/Abilities/SGPAbilitySystemComponent.h"

ASGPPlayerState::ASGPPlayerState()
{
	// Create ability system component, and set it to be explicitly replicated
	AbilitySystemComponent = CreateDefaultSubobject<USGPAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
}

UAbilitySystemComponent* ASGPPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}
