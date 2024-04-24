// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveCazaComun.h"

ANaveCazaComun::ANaveCazaComun() : ANaveEnemigaCaza()
{
    PrimaryActorTick.bCanEverTick = true;
	CreacionMalla();
    tipoMovimiento->ElegirMovimiento = "aleatorio";
};

void ANaveCazaComun::BeginPlay()
{
	Super::BeginPlay();

};

void ANaveCazaComun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    //Mover(DeltaTime);
};


void ANaveCazaComun::Mover(float DeltaTime)
{
    // Obtiene la posición actual del actor
    FVector PosicionActual = GetActorLocation();

    // Define la velocidad de movimiento en las direcciones X e Y
    float velocidadX = 300.0f;
    float velocidadY = 150.0f;

    // Calcula la nueva posición
    float NuevaX = velocidadX * DeltaTime;
    float NuevaY = velocidadY * DeltaTime;

  
    // Crea un nuevo vector de posición con las coordenadas
    FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

    if (NuevaPosicion.X >= limiteMapa.Max.X|| NuevaPosicion.Y>=limiteMapa.Max.Y)
    { 
        if (NuevaPosicion.X >= limiteMapa.Max.X) { NuevaPosicion.X = limiteMapa.Min.X; };
        if (NuevaPosicion.Y >= limiteMapa.Max.Y) { NuevaPosicion.Y = limiteMapa.Min.Y; };
    }
    else if (NuevaPosicion.X <= limiteMapa.Min.X|| NuevaPosicion.Y<=limiteMapa.Min.Y)
    {
        if(NuevaPosicion.X <= limiteMapa.Min.X){ NuevaPosicion.X = limiteMapa.Max.X;};
        if(NuevaPosicion.Y <= limiteMapa.Min.Y){ NuevaPosicion.Y = limiteMapa.Max.Y;};
    };

    SetActorLocation(NuevaPosicion);
};



void ANaveCazaComun::CreacionMalla() 
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);
}