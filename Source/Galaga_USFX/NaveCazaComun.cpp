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
//    // Obtiene la posici�n actual del actor
//    FVector PosicionActual = GetActorLocation();
//
//    // Define la velocidad de movimiento en las direcciones X e Y
//    float velocidadX = 300.0f;
//    float velocidadY = 150.0f;
//
//    // Calcula la nueva posici�n
//    float NuevaX = velocidadX * DeltaTime;
//    float NuevaY = velocidadY * DeltaTime;
//
//  
//    // Crea un nuevo vector de posici�n con las coordenadas
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
    // Obtiene la posici�n actual del actor
    FVector PosicionActual = GetActorLocation();

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
    if (NuevaPosicion.X >= limiteMapa.Max.X) { NuevaPosicion.X = limiteMapa.Min.X; }
    else if (NuevaPosicion.X <= limiteMapa.Min.X) { NuevaPosicion.X = limiteMapa.Max.X; }

    if (NuevaPosicion.Y >= limiteMapa.Max.Y) { NuevaPosicion.Y = limiteMapa.Min.Y; }
    else if (NuevaPosicion.Y <= limiteMapa.Min.Y) { NuevaPosicion.Y = limiteMapa.Max.Y; }

    // Actualiza la posici�n del actor
    SetActorLocation(NuevaPosicion);
};

void ANaveCazaComun::CreacionMalla() 
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);
}