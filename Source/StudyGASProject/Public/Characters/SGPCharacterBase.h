// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "SGPCharacterBase.generated.h"

class USGPAbilitySystemComponent;

UCLASS()
class STUDYGASPROJECT_API ASGPCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ASGPCharacterBase();

	UFUNCTION(BlueprintCallable, Category = "GASProject|Character")
	virtual bool IsAlive() const;
	
protected:
	virtual void BeginPlay() override;

	// Implementing IAbilitySystemInterface
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	TWeakObjectPtr<USGPAbilitySystemComponent> AbilitySystemComponent;
};
