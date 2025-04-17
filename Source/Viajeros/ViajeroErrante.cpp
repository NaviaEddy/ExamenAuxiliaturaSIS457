// Fill out your copyright notice in the Description page of Project Settings.


#include "ViajeroErrante.h"

AViajeroErrante::AViajeroErrante()
{
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MatAsset(TEXT("Material'/Game/Materials/MaterialCube2.MaterialCube2'"));
	if (MatAsset.Succeeded())
	{
		MaterialToApply = MatAsset.Object;
	}
	PlataformaMesh->SetMaterial(0, MaterialToApply);
}
