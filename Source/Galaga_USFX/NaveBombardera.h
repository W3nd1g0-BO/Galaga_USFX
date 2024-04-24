// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveArtillera.h"
#include "NaveBombardera.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveBombardera : public ANaveArtillera
{
	GENERATED_BODY()
public:
	ANaveBombardera();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
};
