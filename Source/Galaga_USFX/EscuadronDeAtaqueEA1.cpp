// Fill out your copyright notice in the Description page of Project Settings.


#include "EscuadronDeAtaqueEA1.h"

// Sets default values
AEscuadronDeAtaqueEA1::AEscuadronDeAtaqueEA1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEscuadronDeAtaqueEA1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscuadronDeAtaqueEA1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEscuadronDeAtaqueEA1::buildFormacionEscuadron()
{

}

void AEscuadronDeAtaqueEA1::buildVelocidadEscuadron()
{
}

void AEscuadronDeAtaqueEA1::buildCantEnemigos()
{

}

void AEscuadronDeAtaqueEA1::buildNivelEscuadron()
{

}

Escuadron* AEscuadronDeAtaqueEA1::getEscuadron()
{
	return nullptr;
}

