// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveCazaMini.h"

// Called when the game starts or when spawned
void ANaveCazaMini::BeginPlay()
{
	Super::BeginPlay();
};

ANaveCazaMini::ANaveCazaMini() : ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	mallaNaveEnemiga->SetStaticMesh(Mesh.Object);
};

// Called every frame
void ANaveCazaMini::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

};