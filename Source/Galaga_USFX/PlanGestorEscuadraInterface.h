// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlanGestorEscuadraInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPlanGestorEscuadraInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_API IPlanGestorEscuadraInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void setFormacionEscuadron(FString formaEscuadra) = 0;
	virtual void setVelocidadEscuadron(float velEscuadra) = 0;
	virtual void setCantEnemigos(int cantEnemigos) = 0;
	virtual void setNivelEscuadron(int nivelEscuadra) = 0;
};
