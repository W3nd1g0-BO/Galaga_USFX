// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveCazaComun.h"

ANaveCazaComun::ANaveCazaComun() : ANaveEnemigaCaza()
{
    PrimaryActorTick.bCanEverTick = true;
	CreacionMalla();
	SetEnergia(100);
};

void ANaveCazaComun::BeginPlay()
{
	Super::BeginPlay();

};

void ANaveCazaComun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
};

void ANaveCazaComun::CreacionMalla() 
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);
}