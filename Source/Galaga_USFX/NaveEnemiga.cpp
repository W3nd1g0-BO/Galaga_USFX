// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"
#include "Comp_MovimientoNaves.h"
#include "EstrategiaMovimiento.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"



// Sets default values
ANaveEnemiga::ANaveEnemiga()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the mesh component
	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	//mallaNaveEnemiga->SetStaticMesh(malla.Object);
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	RootComponent = mallaNaveEnemiga;

	//Creacion del componente de movimiento de las naves
	compNave = CreateDefaultSubobject<UComp_MovimientoNaves>(TEXT("Componentes de las de Naves"));
	estrategiaMovimiento = CreateDefaultSubobject<UEstrategiaMovimiento>(TEXT("Estrategia de Movimiento"));
	
}

// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	estrategiaMovimiento->SetElegirMovimiento(movimiento);
}
