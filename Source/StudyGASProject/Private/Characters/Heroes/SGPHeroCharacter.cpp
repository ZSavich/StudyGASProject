// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/Heroes/SGPHeroCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Characters/Abilities/SGPAbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "Core/SGPPlayerState.h"
#include "Kismet/KismetMathLibrary.h"

ASGPHeroCharacter::ASGPHeroCharacter(const FObjectInitializer& ObjectInitializer)
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->SetRelativeLocation(FVector(0.f, 0.f, 68.5f));

	FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->FieldOfView = 80.f;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);

	// Makes sure that the animations play on the Server so that we can use bone and socket transforms
	// to do things like spawning projectiles and other FX
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionProfileName(FName("NoCollision"));
}

void ASGPHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASGPHeroCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASGPHeroCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ASGPHeroCharacter::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &ASGPHeroCharacter::Turn);
}

// Server Only
void ASGPHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (ASGPPlayerState* PS = GetPlayerState<ASGPPlayerState>())
	{
		// Set the ASC on the Server. Clients do this in OnRep_PlayerState()
		AbilitySystemComponent = Cast<USGPAbilitySystemComponent>(PS->GetAbilitySystemComponent());

		// AI won't have PlayerController so we can init again here just to be sure. No harm in initing twice for heroes that have PlayerController
		if (AbilitySystemComponent.Get())
		{
			AbilitySystemComponent.Get()->InitAbilityActorInfo(PS, this);
		}
	}
}

// Client Only
void ASGPHeroCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if (ASGPPlayerState* PS = GetPlayerState<ASGPPlayerState>())
	{
		// Set the ASC for clients. Server does this in PossessedBy.
		AbilitySystemComponent = Cast<USGPAbilitySystemComponent>(PS->GetAbilitySystemComponent());

		// Init ASC Actor Info for Clients. Server will init its ASC when it Possesses a new Actor.
		if (AbilitySystemComponent.Get())
		{
			AbilitySystemComponent.Get()->InitAbilityActorInfo(PS, this);
		}
	}
}

void ASGPHeroCharacter::LookUp(const float Value)
{
	if (IsAlive())
	{
		AddControllerPitchInput(Value);
	}
}

void ASGPHeroCharacter::Turn(const float Value)
{
	if (IsAlive())
	{
		AddControllerYawInput(Value);
	}
}

void ASGPHeroCharacter::MoveForward(const float Value)
{
	AddMovementInput(UKismetMathLibrary::GetForwardVector(FRotator(0.f, GetControlRotation().Yaw, 0.f)), Value);
}

void ASGPHeroCharacter::MoveRight(const float Value)
{
	AddMovementInput(UKismetMathLibrary::GetRightVector(FRotator(0.f, GetControlRotation().Yaw, 0.f)), Value);
}
