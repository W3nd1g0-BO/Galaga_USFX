// Fill out your copyright notice in the Description page of Project Settings.


#include "Comp_MovimientoNaves.h"
#include "math.h"

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
    Mov_FormInfinito(DeltaTime);
}

void UComp_MovimientoNaves::Mov_FormInfinito(float DeltaTime)
{
    float velocidad = 10.0f;
    float rangoMov = 500.0f; // El tamaño de la figura que hará la nave

    
    FVector nuevaPosicion;
    nuevaPosicion.X = rangoMov * FMath::Sin(velocidad * DeltaTime);
    nuevaPosicion.Y = rangoMov * FMath::Sin(2 * velocidad * DeltaTime) / 2;
    nuevaPosicion.Z = GetOwner()->GetActorLocation().Z;

    // Movemos la nave en la nueva posición relativa a su posición inicial
    FVector posicionInicial = GetOwner()->GetActorLocation();
    nuevaPosicion += posicionInicial;

    // Movemos la nave en la nueva posición
    GetOwner()->SetActorLocation(nuevaPosicion);
}
