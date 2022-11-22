// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/SGPCharacterBase.h"
#include "Characters/Abilities/SGPAbilitySystemComponent.h"

ASGPCharacterBase::ASGPCharacterBase()
{
 	PrimaryActorTick.bCanEverTick = false;

}

void ASGPCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

UAbilitySystemComponent* ASGPCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}

bool ASGPCharacterBase::IsAlive() const
{
	return true; // ToDo: Compare Health
}

