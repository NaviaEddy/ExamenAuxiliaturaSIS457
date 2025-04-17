// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IMovimiento.h"
#include "EstrategiaMovimientoRandomico.generated.h"

UCLASS()
class VIAJEROS_API AEstrategiaMovimientoRandomico : public AActor, public IIMovimiento
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaMovimientoRandomico();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void TipoMovimiento(class AViajante* _viajante, float DeltaTime) override;
};
