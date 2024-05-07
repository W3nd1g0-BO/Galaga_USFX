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

	UEstrategiaMovimiento();
public:
	//declaracion de variables que las funciones de movimiento usara
	FVector PosicionActual;
	FVector NuevaPosicion;

	FVector velocidad;

protected:
	virtual void BeginPlay() override;
public:
	
	AActor* nave = GetOwner();

	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction);

	void SetElegirMovimiento(FString _elegirMovimiento) { ElegirMovimiento = _elegirMovimiento; };

	virtual UComp_MovimientoNaves* FuncElegirMovimiento(FString _tipoMovimiento, float DeltaTime) override;
	void ComprobarLimites(FVector& NuevaPosicion);

	void Mov_lineal(float DeltaTime);
	void Mov_Aleatoriamente(float DeltaTime);
	void Mov_FormInfinito(float DeltaTime);
	void Mov_Horizontal(float DeltaTime);
	void Mov_Estacionario(float DeltaTime);
};
