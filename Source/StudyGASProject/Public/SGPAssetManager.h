// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "SGPAssetManager.generated.h"

UCLASS()
class STUDYGASPROJECT_API USGPAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static USGPAssetManager& Get();

	/** Starts initial load, gets called from InitializeObjectReferences **/
	virtual void StartInitialLoading() override;
};
