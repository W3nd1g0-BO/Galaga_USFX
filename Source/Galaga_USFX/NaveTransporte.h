// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveTransporte.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveTransporte : public ANaveEnemiga
{
	GENERATED_BODY()

protected:
	virtual void Tick(float DeltaTime) override;
public:
	ANaveTransporte();
public:
	virtual void Mover(float DeltaTime);
	//virtual void Destruir();
	//virtual void Daño();
	//virtual void Atacar();
};
