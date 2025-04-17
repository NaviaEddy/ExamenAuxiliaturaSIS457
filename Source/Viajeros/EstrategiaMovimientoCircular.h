// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IMovimiento.h"
#include "EstrategiaMovimientoCircular.generated.h"

UCLASS()
class VIAJEROS_API AEstrategiaMovimientoCircular : public AActor, public IIMovimiento
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaMovimientoCircular();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector Centro;
	float Radio;
	float Angulo;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void TipoMovimiento(class AViajante* _viajante, float DeltaTime) override;

};
