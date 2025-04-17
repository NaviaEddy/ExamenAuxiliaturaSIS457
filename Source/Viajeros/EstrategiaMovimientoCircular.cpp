// Fill out your copyright notice in the Description page of Project Settings.

#include "EstrategiaMovimientoCircular.h"
#include "Viajante.h"

// Sets default values
AEstrategiaMovimientoCircular::AEstrategiaMovimientoCircular()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaMovimientoCircular::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEstrategiaMovimientoCircular::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaMovimientoCircular::Inicializar(const FVector& InCentro, float InRadio)
{
	Centro = InCentro;
	Radio = InRadio;
}

void AEstrategiaMovimientoCircular::TipoMovimiento(AViajante* _viajante, float DeltaTime)
{
	Angulo += FMath::FRandRange(0.5f, 1.5f) * DeltaTime;

	float X = Centro.X + Radio * FMath::Cos(Angulo);
	float Y = Centro.Y + Radio * FMath::Sin(Angulo);

	FVector NuevaPosicion = FVector(X, Y, _viajante->GetActorLocation().Z);

	_viajante->SetActorLocation(NuevaPosicion);
}

