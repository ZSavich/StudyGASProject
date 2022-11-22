// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/SGPCharacterBase.h"
#include "SGPHeroCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/*
 * A Player or AI Controlled Hero Character
 */
UCLASS()
class STUDYGASPROJECT_API ASGPHeroCharacter : public ASGPCharacterBase
{
	GENERATED_BODY()

protected:
	/*
	 * Base Properties
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GASProject|Camera")
	float BaseTurnRate = 45.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GASProject|Camera")
	float BaseLookUpRate = 45.f;

	UPROPERTY(BlueprintReadOnly, Category = "GASProject|Camera")
	float StartingCameraBoomArmLength;

	UPROPERTY(BlueprintReadOnly, Category = "GASProject|Camera")
	FVector StartingCameraBoomLocation;

	/*
	 * Actor's Components
	 */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "GASProject|Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "GASProject|Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

public:
	ASGPHeroCharacter(const class FObjectInitializer& ObjectInitializer);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// Only called on the Server. Calls before Server's AcknowledgePossession. 
	virtual void PossessedBy(AController* NewController) override;
	
protected:
	/*
	 * Mouse Inputs
	 */
	void LookUp(const float Value);
	void Turn(const float Value);
	void MoveForward(const float Value);
	void MoveRight(const float Value);

	// Client Only
	virtual void OnRep_PlayerState() override;
};
