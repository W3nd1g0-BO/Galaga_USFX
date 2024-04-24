// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Comp_MovimientoNaves.h"
#include "EstrategiaMovimiento.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API UEstrategiaMovimiento : public UComp_MovimientoNaves
{
	GENERATED_BODY()
	
public:
	AActor* nave = GetOwner();
	void FuncElegirMovimiento(FString _tipoMovimiento) override;

	void Mov_Aleatoriamente();
	void Mov_FormInfinito();
	void Mov_Horizontal();
};
