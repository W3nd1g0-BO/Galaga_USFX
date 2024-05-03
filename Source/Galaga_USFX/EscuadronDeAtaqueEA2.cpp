// Fill out your copyright notice in the Description page of Project Settings.


#include "EscuadronDeAtaqueEA2.h"

// Sets default values
AEscuadronDeAtaqueEA2::AEscuadronDeAtaqueEA2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEscuadronDeAtaqueEA2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscuadronDeAtaqueEA2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEscuadronDeAtaqueEA2::buildFormacionEscuadron()
{

}
void AEscuadronDeAtaqueEA2::buildVelocidadEscuadron()
{
}

void AEscuadronDeAtaqueEA2::buildCantEnemigos()
{

}

void AEscuadronDeAtaqueEA2::buildNivelEscuadron()
{

}

Escuadron* AEscuadronDeAtaqueEA2::getEscuadron()
{
	return nullptr;
}
