// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SGPPlayerController.generated.h"

UCLASS()
class STUDYGASPROJECT_API ASGPPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	// Server Only
	virtual void OnPossess(APawn* InPawn) override;
	
};
