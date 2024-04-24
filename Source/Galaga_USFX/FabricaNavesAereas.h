// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricNaveEnemiga.h"
#include "NaveEnemiga.h"
#include "FabricaNavesAereas.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API AFabricaNavesAereas : public AFabricNaveEnemiga
{
	GENERATED_BODY()
public:
	virtual ANaveEnemiga* fabricarNave(FString fabNave) override;
};
