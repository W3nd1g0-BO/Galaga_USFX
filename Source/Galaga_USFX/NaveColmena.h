// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveTransporte.h"
#include "NaveColmena.generated.h"
#include "Comp_MovimientoNaves.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveColmena : public ANaveTransporte
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
public:
	ANaveColmena();
	void CreacionMalla();
	void MoverPropio(float DeltaTime) override;

};
