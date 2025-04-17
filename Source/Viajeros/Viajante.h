// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IMovimiento.h"
#include "Viajante.generated.h"

UCLASS()
class VIAJEROS_API AViajante : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AViajante();

	void AlternarMovimiento(AActor* _movimiento);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class IIMovimiento* EstrategiasMovimiento;

	// Static Mesh Component
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PlataformaMesh;

	// Color parameter for the material
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
	UMaterialInterface* MaterialToApply;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
