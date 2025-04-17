// Fill out your copyright notice in the Description page of Project Settings.


#include "ViajeroCuadrante.h"

AViajeroCuadrante::AViajeroCuadrante()
{
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MatAsset(TEXT("Material'/Game/Materials/MaterialCube1.MaterialCube1'"));
	if (MatAsset.Succeeded())
	{
		MaterialToApply = MatAsset.Object;
	}
	PlataformaMesh->SetMaterial(0, MaterialToApply);
}

