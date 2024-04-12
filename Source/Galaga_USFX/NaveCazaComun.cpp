// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveCazaComun.h"

ANaveCazaComun::ANaveCazaComun() : ANaveEnemigaCaza()
{
    PrimaryActorTick.bCanEverTick = true;
	CreacionMalla();
    bMovPredeterminado = true;
};

void ANaveCazaComun::BeginPlay()
{
	Super::BeginPlay();
    
    MovGeneralNaves->Deactivate();
    
    if (bMovPredeterminado) {
        MovGeneralNaves->Activate();
    }
};

void ANaveCazaComun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (!bMovPredeterminado) { Mover(DeltaTime); }
};


//void ANaveCazaComun::Mover(float DeltaTime)
//{
//    // Obtiene la posición actual del actor
//    FVector PosicionActual = GetActorLocation();
//
//    // Define la velocidad de movimiento en las direcciones X e Y
//    float velocidadX = 300.0f;
//    float velocidadY = 150.0f;
//
//    // Calcula la nueva posición
//    float NuevaX = velocidadX * DeltaTime;
//    float NuevaY = velocidadY * DeltaTime;
//
//  
//    // Crea un nuevo vector de posición con las coordenadas
//    FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);
//
//    if (NuevaPosicion.X >= limiteMapa.Max.X|| NuevaPosicion.Y>=limiteMapa.Max.Y)
//    { 
//        if (NuevaPosicion.X >= limiteMapa.Max.X) { NuevaPosicion.X = limiteMapa.Min.X; };
//        if (NuevaPosicion.Y >= limiteMapa.Max.Y) { NuevaPosicion.Y = limiteMapa.Min.Y; };
//    }
//    else if (NuevaPosicion.X <= limiteMapa.Min.X|| NuevaPosicion.Y<=limiteMapa.Min.Y)
//    {
//        if(NuevaPosicion.X <= limiteMapa.Min.X){ NuevaPosicion.X = limiteMapa.Max.X;};
//        if(NuevaPosicion.Y <= limiteMapa.Min.Y){ NuevaPosicion.Y = limiteMapa.Max.Y;};
//    };
//
//    SetActorLocation(NuevaPosicion);
//};

void ANaveCazaComun::Mover(float DeltaTime)
{
    // Obtiene la posición actual del actor
    FVector PosicionActual = GetActorLocation();

    // Define la velocidad de movimiento
    velocidad = 100.0f;

    // Define un vector de dirección. Este puede ser un vector aleatorio o un vector específico dependiendo de tus necesidades.
    trayectoria = FVector(FMath::RandRange(-1, 1), FMath::RandRange(-1, 1), 0);

    // Normaliza el vector de dirección
    trayectoria.Normalize();

    // Calcula el desplazamiento
    FVector Desplazamiento = velocidad * trayectoria * DeltaTime;

    // Calcula la nueva posición
    FVector NuevaPosicion = PosicionActual + Desplazamiento;

    // Verifica si la nueva posición está fuera de los límites del mapa y ajusta la posición si es necesario
    if (NuevaPosicion.X >= limiteMapa.Max.X) { NuevaPosicion.X = limiteMapa.Min.X; }
    else if (NuevaPosicion.X <= limiteMapa.Min.X) { NuevaPosicion.X = limiteMapa.Max.X; }

    if (NuevaPosicion.Y >= limiteMapa.Max.Y) { NuevaPosicion.Y = limiteMapa.Min.Y; }
    else if (NuevaPosicion.Y <= limiteMapa.Min.Y) { NuevaPosicion.Y = limiteMapa.Max.Y; }

    // Actualiza la posición del actor
    SetActorLocation(NuevaPosicion);
};

void ANaveCazaComun::CreacionMalla() 
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);
}