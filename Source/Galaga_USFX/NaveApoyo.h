// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveApoyo.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveApoyo : public ANaveEnemiga
{
	GENERATED_BODY()
public:
	ANaveApoyo() {};
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Mover(float DeltaTime);
	virtual void Tick(float DeltaTime) override;
};
