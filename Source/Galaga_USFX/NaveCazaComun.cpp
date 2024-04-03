// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveCazaComun.h"

void ANaveCazaComun::BeginPlay()
{
	Super::BeginPlay();
};

ANaveCazaComun::ANaveCazaComun() : ANaveEnemigaCaza()
{
	CreacionMalla();
};

void ANaveCazaComun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
};


void ANaveCazaComun::Mover(float DeltaTime)
{
    // Obtiene la posición actual del actor
    FVector PosicionActual = GetActorLocation();

    // Define la velocidad de movimiento en las direcciones X e Y
    float velocidadX = 300.0f;
    float velocidadY = 0.0f;

    // Calcula la nueva posición
    float NuevaX = velocidadX * DeltaTime;
    float NuevaY = velocidadY * DeltaTime;

    if (PosicionActual.X > limiteMapa.Max.X) { PosicionActual.X = limiteMapa.Min.X; }
    else if (PosicionActual.X < limiteMapa.Min.X) { PosicionActual.X = limiteMapa.Max.X; };

    // Crea un nuevo vector de posición con las coordenadas
    FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

    SetActorLocation(NuevaPosicion);
};

void ANaveCazaComun::CreacionMalla() 
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);
}