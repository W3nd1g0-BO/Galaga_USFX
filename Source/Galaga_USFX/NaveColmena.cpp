// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveColmena.h"

void ANaveColmena::BeginPlay()
{
    Super::BeginPlay();
};

ANaveColmena::ANaveColmena() : ANaveTransporte()
{
    CreacionMalla();
    //bMovPredeterminado = false;
    //MovGeneralNaves->SetTipoMovimiento(2);
};

void ANaveColmena::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Mover(DeltaTime);
};


void ANaveColmena::Mover(float DeltaTime)
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

void ANaveColmena::CreacionMalla()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
    mallaNaveEnemiga->SetStaticMesh(Mesh.Object);
}