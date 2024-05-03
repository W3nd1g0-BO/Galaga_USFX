// Fill out your copyright notice in the Description page of Project Settings.


#include "EscuadronDeAtaqueEA3.h"

// Sets default values
AEscuadronDeAtaqueEA3::AEscuadronDeAtaqueEA3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEscuadronDeAtaqueEA3::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscuadronDeAtaqueEA3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEscuadronDeAtaqueEA3::buildFormacionEscuadron()
{

}
void AEscuadronDeAtaqueEA3::buildVelocidadEscuadron()
{
}

void AEscuadronDeAtaqueEA3::buildCantEnemigos()
{

}

void AEscuadronDeAtaqueEA3::buildNivelEscuadron()
{

}

Escuadron* AEscuadronDeAtaqueEA3::getEscuadron()
{
	return nullptr;
}
