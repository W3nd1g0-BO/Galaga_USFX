// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveCazaComun.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveCazaComun : public ANaveEnemigaCaza
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
public:
	ANaveCazaComun();
	void CreacionMalla();
	//void Mover(float DeltaTime) override;
};
