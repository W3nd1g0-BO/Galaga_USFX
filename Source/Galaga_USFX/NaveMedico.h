// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveApoyo.h"
#include "NaveMedico.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveMedico : public ANaveApoyo
{
	GENERATED_BODY()
public:
	ANaveMedico() {};
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	
public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void CreacionMalla();
	void Mover(float DeltaTime);
};
