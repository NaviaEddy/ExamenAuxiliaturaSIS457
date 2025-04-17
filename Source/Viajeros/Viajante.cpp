// Fill out your copyright notice in the Description page of Project Settings.


#include "Viajante.h"

// Sets default values
AViajante::AViajante()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		Plataforma(TEXT("StaticMesh'/Game/Meshs/EditorCube.EditorCube'"));

	PlataformaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plataforma_Mesh"));
	PlataformaMesh->SetRelativeScale3D(FVector(0.1, 0.1, 0.1));
	PlataformaMesh->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	PlataformaMesh->SetStaticMesh(Plataforma.Object);
	SetRootComponent(PlataformaMesh);

	EstrategiasMovimiento = nullptr;

}

// Called when the game starts or when spawned
void AViajante::BeginPlay()
{
	Super::BeginPlay();
	
}

void AViajante::AlternarMovimiento(AActor* _movimiento)
{
	EstrategiasMovimiento = Cast<IIMovimiento>(_movimiento);

	//Registrar error si el lanzamiento falla
	if (!EstrategiasMovimiento)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("¡Lanzamiento no valido! Consulte Registro de salida para obtener mas detalles.")));
		UE_LOG(LogTemp, Error, TEXT("AlterarManiobras(): ¡El actor no es una estrategia de EstrategiaNaveDeCombate! ¿Estas seguro de que el actor implementa esa interfaz?"));
	}
}

void AViajante::Emplear()
{
	if (!EstrategiasMovimiento) {
		UE_LOG(LogTemp, Error, TEXT("Emplear(): EstrategiaNaveDeCombate es NULL, asegurese de que este inicializada."));
		return;
	}
	//Ejecutar la maniobra de estrategia actual
	EstrategiasMovimiento->TipoMovimiento();
}

// Called every frame
void AViajante::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (EstrategiasMovimiento)
	{
		EstrategiasMovimiento->TipoMovimiento(this, DeltaTime);
	}

}

