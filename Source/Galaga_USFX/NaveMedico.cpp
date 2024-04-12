// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveMedico.h"

//ANaveMedico::ANaveMedico()
//{
//    CreacionMalla();
//}

void ANaveMedico::BeginPlay()
{
    Super::BeginPlay();

};

void ANaveMedico::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bMovPredeterminado) {
        MovGeneralNaves->Mov_FormInfinito(DeltaTime);
    }
    else {
        Mover(DeltaTime);
    }
};


void ANaveMedico::Mover(float DeltaTime)
{
    // Obtiene la posición actual del actor
    FVector PosicionActual = GetActorLocation();

    // Define la velocidad de movimiento en las direcciones X e Y
    float velocidadX = 200.0f;
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

void ANaveMedico::CreacionMalla()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim.Shape_Trim'"));
    mallaNaveEnemiga->SetStaticMesh(Mesh.Object);
}
