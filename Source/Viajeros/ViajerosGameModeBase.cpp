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
	AViajeroErrante* errante = GetWorld()->SpawnActor<AViajeroErrante>(AViajeroErrante::StaticClass(), FVector(-210.f, 80.f, 70), FRotator::ZeroRotator);
	FVector Centro = errante->GetActorLocation();
	AEstrategiaMovimientoCircular* Circular = GetWorld()->SpawnActor<AEstrategiaMovimientoCircular>(AEstrategiaMovimientoCircular::StaticClass());
	Circular->Inicializar(Centro, 100.f);
	errante->AlternarMovimiento(Circular);
}

void AViajerosGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
