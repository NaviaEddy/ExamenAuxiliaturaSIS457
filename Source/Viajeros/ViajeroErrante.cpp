// Fill out your copyright notice in the Description page of Project Settings.


#include "ViajeroErrante.h"

AViajeroErrante::AViajeroErrante()
{
}

void AViajeroErrante::AlternarManiobras(AActor* _movimiento)
{
	EstrategiasMovimiento = Cast<IIMovimiento>(_movimiento);

	//Registrar error si el lanzamiento falla
	if (!EstrategiasMovimiento)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("¡Lanzamiento no valido! Consulte Registro de salida para obtener mas detalles.")));
		UE_LOG(LogTemp, Error, TEXT("AlterarManiobras(): ¡El actor no es una estrategia de EstrategiaNaveDeCombate! ¿Estas seguro de que el actor implementa esa interfaz?"));
	}
}

void AViajeroErrante::Emplear()
{
	if (!EstrategiasMovimiento) {
		UE_LOG(LogTemp, Error, TEXT("Emplear(): EstrategiaNaveDeCombate es NULL, asegurese de que este inicializada."));
		return;
	}
	//Ejecutar la maniobra de estrategia actual
	EstrategiasMovimiento->TipoMovimiento();
}
