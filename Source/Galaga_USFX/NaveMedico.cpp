// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveMedico.h"

ANaveMedico::ANaveMedico()
{
    CreacionMalla();
}

void ANaveMedico::BeginPlay()
{
    Super::BeginPlay();

};

void ANaveMedico::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
};


void ANaveMedico::CreacionMalla()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim.Shape_Trim'"));
    mallaNaveEnemiga->SetStaticMesh(Mesh.Object);
}
