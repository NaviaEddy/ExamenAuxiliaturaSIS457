// Fill out your copyright notice in the Description page of Project Settings.

#include "EstrategiaMovimientoRandomico.h"
#include <Kismet/KismetMathLibrary.h>
#include "Viajante.h"

// Sets default values
AEstrategiaMovimientoRandomico::AEstrategiaMovimientoRandomico()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaMovimientoRandomico::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaMovimientoRandomico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaMovimientoRandomico::TipoMovimiento(AViajante* _viajante, float DeltaTime)
{
	if (!_viajante) return;
    TimerCambioDireccion += DeltaTime;
    if (TimerCambioDireccion >= IntervaloTiempoMax)
    {
        UsandoEjeX = !UsandoEjeX;
        DireccionActual = FMath::RandBool() ? 1.0f : -1.0f;
        IntervaloTiempoMax = FMath::RandRange(1.0f, 3.0f);
        TimerCambioDireccion = 0.0f;
    }

    FVector Dir;
    if (UsandoEjeX)
    {
        Dir = FVector(DireccionActual, 0.0f, 0.0f);
    }
    else
    {
        Dir = FVector(0.0f, DireccionActual, 0.0f);
    }

    FVector Offset = Dir * 50.0f * DeltaTime;

    _viajante->AddActorWorldOffset(Offset, true);
}

