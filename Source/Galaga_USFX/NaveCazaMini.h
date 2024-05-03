// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemigaCaza.h"
#include "NaveCazaMini.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveCazaMini : public ANaveEnemigaCaza
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	ANaveCazaMini();
};
