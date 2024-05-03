// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BuilderEscuadronesDeAtaque.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBuilderEscuadronesDeAtaque : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_API IBuilderEscuadronesDeAtaque
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void buildFormacionEscuadron() = 0;
	virtual void buildVelocidadEscuadron() = 0;
	virtual void buildCantEnemigos() = 0;
	virtual void buildNivelEscuadron() = 0;
	virtual class Escuadron* getEscuadron() = 0;
};
