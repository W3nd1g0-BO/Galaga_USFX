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
	int tipoMovimiento;
	float velocidad;
	FVector trayectoria;
	FBox limitedeMapa = FBox(FVector(-2000.0f, -2000.0f, 0.0f), FVector(2000.0f, 2000.0f, 500.0f));

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetTipoMovimiento(int tipo);

	void Mov_FormZigZag(float DeltaTime);

	void Mov_FormInfinito(float DeltaTime);
};
