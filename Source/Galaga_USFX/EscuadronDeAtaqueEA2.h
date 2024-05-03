// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuilderEscuadronesDeAtaque.h"
#include "EscuadronDeAtaqueEA2.generated.h"

UCLASS()
class GALAGA_USFX_API AEscuadronDeAtaqueEA2 : public AActor, public IBuilderEscuadronesDeAtaque
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEscuadronDeAtaqueEA2();
private:
	//The Lodging Actor
	UPROPERTY(VisibleAnywhere, Category = "Escuadron EA2")
	class AEscuadron* escuadron;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	virtual void buildFormacionEscuadron() override;
	virtual void buildVelocidadEscuadron() override;
	virtual void buildCantEnemigos() override;
	virtual void buildNivelEscuadron() override;
	virtual class Escuadron* getEscuadron() override;
};
