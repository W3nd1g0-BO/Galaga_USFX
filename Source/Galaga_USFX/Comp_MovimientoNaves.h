// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Comp_MovimientoNaves.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAGA_USFX_API UComp_MovimientoNaves : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UComp_MovimientoNaves();
public:

	FBox limitedeMapa;
	FString ElegirMovimiento;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:
	void SetLimitesMapa(FBox limites);
	
public:	

	virtual void TickComponent(float DeltaTime, ELevelTick
		TickType, FActorComponentTickFunction* ThisTickFunction)
		override;

	virtual UComp_MovimientoNaves* FuncElegirMovimiento(FString _tipoMovimiento,float DeltaTime);
};
