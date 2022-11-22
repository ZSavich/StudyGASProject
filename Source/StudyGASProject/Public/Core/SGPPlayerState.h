// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "SGPPlayerState.generated.h"

class USGPAbilitySystemComponent;

UCLASS()
class STUDYGASPROJECT_API ASGPPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASGPPlayerState();

	// Implement IAbilitySystemInterface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(Transient)
	TObjectPtr<USGPAbilitySystemComponent> AbilitySystemComponent;
};
