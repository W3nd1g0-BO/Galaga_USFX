// Fill out your copyright notice in the Description page of Project Settings.


#include "Comp_MovimientoNaves.h"

// Sets default values for this component's properties
UComp_MovimientoNaves::UComp_MovimientoNaves()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
			

// Called when the game starts
void UComp_MovimientoNaves::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UComp_MovimientoNaves::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//LLamamos a la funcion que mueve la nave
	MovPredeterminadoNave(DeltaTime)
}

void UComp_MovimientoNaves::MovPredeterminadoNave(float DeltaTime)
{
	float velocidad = 100.0f;
	float tamañofigura = 500.0f;//El tamaño de la figura que hara la nave

	float tiempoMundo = GetWorld()->GetTimeSeconds();
	FVector nuevaPosicion;
	nuevaPosicion.X = tamañofigura * FMath::Sin(velocidad * tiempoMundo);
	nuevaPosicion.Y = tamañofigura * FMath::Sin(2 * velocidad * tiempoMundo) / 2;
	nuevaPosicion.Z = GetOwner()->GetActorLocation().Z;

	//Movemos la nave en la nueva posicion
	GetOwner()->SetActorLocation(nuevaPosicion);
}
