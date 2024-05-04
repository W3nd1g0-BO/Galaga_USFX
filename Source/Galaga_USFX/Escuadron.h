// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlanGestorEscuadraInterface.h"
#include "Escuadron.generated.h"

UCLASS()
class GALAGA_USFX_API AEscuadron : public AActor,public IPlanGestorEscuadraInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEscuadron();
private:
	FString FormaEscuadra;
	float VelEscuadra;
	int CantEnemigos;
	int NivelEscuadra;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void setFormacionEscuadron(FString _formaEscuadra);
	void setVelocidadEscuadron(float _velEscuadra);
	void setCantEnemigos(int _cantEnemigos);
	void setNivelEscuadron(int _nivelEscuadra);
	void DatosEscuadron();
};
