// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveColmena.h"

void ANaveColmena::BeginPlay()
{
    Super::BeginPlay();
};

ANaveColmena::ANaveColmena() : ANaveTransporte()
{
    CreacionMalla();
};

void ANaveColmena::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
};

void ANaveColmena::CreacionMalla()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
    mallaNaveEnemiga->SetStaticMesh(Mesh.Object);
}