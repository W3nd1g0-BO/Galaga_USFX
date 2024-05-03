// Fill out your copyright notice in the Description page of Project Settings.


#include "EscuadronDeAtaqueEA5.h"

// Sets default values
AEscuadronDeAtaqueEA5::AEscuadronDeAtaqueEA5()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEscuadronDeAtaqueEA5::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscuadronDeAtaqueEA5::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEscuadronDeAtaqueEA5::buildFormacionEscuadron()
{
}
void AEscuadronDeAtaqueEA5::buildVelocidadEscuadron()
{
}

void AEscuadronDeAtaqueEA5::buildCantEnemigos()
{

}

void AEscuadronDeAtaqueEA5::buildNivelEscuadron()
{

}

Escuadron* AEscuadronDeAtaqueEA5::getEscuadron()
{
	return nullptr;
}

