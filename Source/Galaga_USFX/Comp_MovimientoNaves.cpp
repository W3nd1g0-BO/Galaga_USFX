// Fill out your copyright notice in the Description page of Project Settings.


#include "Comp_MovimientoNaves.h"
#include "math.h"

// Sets default values for this component's properties
UComp_MovimientoNaves::UComp_MovimientoNaves()
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
			

// Called when the game starts
void UComp_MovimientoNaves::BeginPlay()
{
	Super::BeginPlay();
	// ...
}

 void UComp_MovimientoNaves::SetTipoMovimiento(int tipo)
 {
	 tipoMovimiento = tipo;
 }

// Called every frame
void UComp_MovimientoNaves::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    switch(tipoMovimiento)
    {
		case 1:
            Mov_FormInfinito(DeltaTime);
			break;
		case 2:
			Mov_FormZigZag(DeltaTime);
			break;
	 }
}

void UComp_MovimientoNaves::Mov_FormZigZag(float DeltaTime)
{
    // Obtiene la posici�n actual del actor
    FVector PosicionActual = GetOwner()->GetActorLocation();

    // Define la velocidad de movimiento
    velocidad = 100.0f;

    // Define un vector de direcci�n. Este puede ser un vector aleatorio o un vector espec�fico dependiendo de tus necesidades.
    trayectoria = FVector(FMath::RandRange(-1, 1), FMath::RandRange(-1, 1), 0);

    // Normaliza el vector de direcci�n
    trayectoria.Normalize();

    // Calcula el desplazamiento
    FVector Desplazamiento = velocidad * trayectoria * DeltaTime;

    // Calcula la nueva posici�n
    FVector NuevaPosicion = PosicionActual + Desplazamiento;

    // Verifica si la nueva posici�n est� fuera de los l�mites del mapa y ajusta la posici�n si es necesario
    if (NuevaPosicion.X >= limitedeMapa.Max.X) { NuevaPosicion.X = limitedeMapa.Min.X; }
    else if (NuevaPosicion.X <= limitedeMapa.Min.X) { NuevaPosicion.X = limitedeMapa.Max.X; }

    if (NuevaPosicion.Y >= limitedeMapa.Max.Y) { NuevaPosicion.Y = limitedeMapa.Min.Y; }
    else if (NuevaPosicion.Y <= limitedeMapa.Min.Y) { NuevaPosicion.Y = limitedeMapa.Max.Y; }

    // Actualiza la posici�n del actor
    GetOwner()->SetActorLocation(NuevaPosicion);
};

void UComp_MovimientoNaves::Mov_FormInfinito(float DeltaTime)
{
    velocidad = 10.0f;
    float rangoMov = 500.0f; // El tama�o de la figura que har� la nave


    FVector nuevaPosicion;
    nuevaPosicion.X = rangoMov * FMath::Sin(velocidad * DeltaTime);
    nuevaPosicion.Y = rangoMov * FMath::Sin(2 * velocidad * DeltaTime) / 2;
    nuevaPosicion.Z = GetOwner()->GetActorLocation().Z;

    // Movemos la nave en la nueva posici�n relativa a su posici�n inicial
    FVector posicionInicial = GetOwner()->GetActorLocation();
    nuevaPosicion += posicionInicial;

    // Movemos la nave en la nueva posici�n
    GetOwner()->SetActorLocation(nuevaPosicion);
};
