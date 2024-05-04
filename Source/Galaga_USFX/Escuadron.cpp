// Fill out your copyright notice in the Description page of Project Settings.


#include "Escuadron.h"

// Sets default values
AEscuadron::AEscuadron()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEscuadron::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscuadron::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEscuadron::setFormacionEscuadron(FString _formaEscuadra)
{
	FormaEscuadra = _formaEscuadra;
}

void AEscuadron::setVelocidadEscuadron(float _velEscuadra)
{
	VelEscuadra = _velEscuadra;
}

void AEscuadron::setCantEnemigos(int _cantEnemigos)
{
	CantEnemigos = _cantEnemigos;
}

void AEscuadron::setNivelEscuadron(int _nivelEscuadra)
{
	NivelEscuadra = _nivelEscuadra;
}

void AEscuadron::DatosEscuadron()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,
		FString::Printf(TEXT("Forma Escuadra: %s"), *FormaEscuadra));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,
		FString::Printf(TEXT("Vel de escuadra: %f"), VelEscuadra));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,
		FString::Printf(TEXT("Cantidad inicial de enemigos: %d"), CantEnemigos));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,
		FString::Printf(TEXT("El nivel de la escuadra: %d"), NivelEscuadra));
}




