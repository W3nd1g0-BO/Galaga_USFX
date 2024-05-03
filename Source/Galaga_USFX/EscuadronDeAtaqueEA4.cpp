// Fill out your copyright notice in the Description page of Project Settings.


#include "EscuadronDeAtaqueEA4.h"

// Sets default values
AEscuadronDeAtaqueEA4::AEscuadronDeAtaqueEA4()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEscuadronDeAtaqueEA4::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscuadronDeAtaqueEA4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEscuadronDeAtaqueEA4::buildFormacionEscuadron()
{
}
void AEscuadronDeAtaqueEA4::buildVelocidadEscuadron()
{
}

void AEscuadronDeAtaqueEA4::buildCantEnemigos()
{

}

void AEscuadronDeAtaqueEA4::buildNivelEscuadron()
{

}

Escuadron* AEscuadronDeAtaqueEA4::getEscuadron()
{
	return nullptr;
}
