// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveTransporte.h"

void ANaveTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

ANaveTransporte::ANaveTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim.Shape_Trim'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
}

void ANaveTransporte::Mover(float DeltaTime)
{
	// Obtiene la posici�n actual del actor
	FVector PosicionActual = GetActorLocation();

	//Define la velocidad de la nave
	float velocidadX = 100.0f;
	float velocidadY = 0.0f;

	// Genera nuevas coordenadas X e Y aleatorias
	float NuevaX = velocidadX * DeltaTime;
	float NuevaY = velocidadY * DeltaTime;

	// Crea un nuevo vector de posici�n con las coordenadas aleatorias y la misma Z que la posici�n actual
	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

	// Establece la nueva posici�n del actor
	SetActorLocation(NuevaPosicion);
}

//void ANaveTransporte::Destruir()
//{
//}
//
//void ANaveTransporte::Da�o()
//{
//}
//
//void ANaveTransporte::Atacar()
//{
//}
