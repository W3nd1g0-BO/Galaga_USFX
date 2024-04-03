// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveCazaMini.h"

// Called when the game starts or when spawned
void ANaveCazaMini::BeginPlay()
{
	Super::BeginPlay();
};

ANaveCazaMini::ANaveCazaMini()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);
};

// Called every frame
void ANaveCazaMini::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);

};

void ANaveCazaMini::Mover(float DeltaTime)
{
	FVector PosicionActual = GetActorLocation();

	/// Define la velocidad de movimiento en las direcciones X e Y
	const float velocidadX = 500.0f;
	const float velocidadY = 0.0f;

	// Calcula la nueva posición
	float NuevaX = velocidadX * DeltaTime;
	float NuevaY = velocidadY * DeltaTime;

	// Crea un nuevo vector de posición con las coordenadas
	FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

	// Mueve el objeto a la nueva posición
	SetActorLocation(NuevaPosicion);
};