// Fill out your copyright notice in the Description page of Project Settings.

#include "SGPAssetManager.h"
#include "AbilitySystemGlobals.h"

USGPAssetManager& USGPAssetManager::Get()
{
	if (USGPAssetManager* Singleton = Cast<USGPAssetManager>(GEngine->AssetManager))
	{
		return *Singleton;
	}
	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("Invalid AssetManager in DefaultEngine.ini, must be SGPAssetManager!"));
		return *NewObject<USGPAssetManager>(); // Never calls this
	}
}

void USGPAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	UAbilitySystemGlobals::Get().InitGlobalData();
}
