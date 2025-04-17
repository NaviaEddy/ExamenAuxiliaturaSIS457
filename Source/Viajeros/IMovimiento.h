// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Viajante.h"
#include "IMovimiento.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIMovimiento : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VIAJEROS_API IIMovimiento
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void TipoMovimiento(class AViajante* _viajante, float DeltaTime) = 0;
};
