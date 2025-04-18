// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ViajerosGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class VIAJEROS_API AViajerosGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AViajerosGameModeBase();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
