// Copyright Epic Games, Inc. All Rights Reserved.


#include "ViajerosGameModeBase.h"
#include "EstrategiaMovimientoCircular.h"
#include "EstrategiaMovimientoRandomico.h"
#include "ViajeroErrante.h"
#include "ViajeroCuadrante.h"

AViajerosGameModeBase::AViajerosGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AViajerosGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	AViajeroCuadrante* cuadrante = GetWorld()->SpawnActor<AViajeroCuadrante>(AViajeroCuadrante::StaticClass(), FVector(-210.f, -180.f, 70), FRotator::ZeroRotator);
	AEstrategiaMovimientoRandomico* Randomico = GetWorld()->SpawnActor<AEstrategiaMovimientoRandomico>(AEstrategiaMovimientoRandomico::StaticClass());
	cuadrante->AlternarMovimiento(Randomico);
	cuadrante->Emplear();
	AViajeroErrante* errante = GetWorld()->SpawnActor<AViajeroErrante>(AViajeroErrante::StaticClass(), FVector(-210.f, 80.f, 70), FRotator::ZeroRotator);
	AEstrategiaMovimientoCircular* Circular = GetWorld()->SpawnActor<AEstrategiaMovimientoCircular>(AEstrategiaMovimientoCircular::StaticClass());
	errante->AlternarMovimiento(Circular);
	errante->Emplear();
}

void AViajerosGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
