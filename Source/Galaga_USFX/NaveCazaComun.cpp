// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveCazaComun.h"

ANaveCazaComun::ANaveCazaComun() : ANaveEnemigaCaza()
{
    PrimaryActorTick.bCanEverTick = true;
	CreacionMalla();
};

void ANaveCazaComun::BeginPlay()
{
	Super::BeginPlay();

};

void ANaveCazaComun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//if (estrategiaMovimiento->ElegirMovimiento != "" || nullptr)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("NaveCazaComun ha llamado a la funcion de movimiento"));
	//	estrategiaMovimiento->FuncElegirMovimiento(movimiento, DeltaTime);		
	//}
};

void ANaveCazaComun::CreacionMalla() 
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);
}