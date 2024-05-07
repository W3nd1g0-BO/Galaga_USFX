// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveTransporte.h"

void ANaveTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ANaveTransporte::ANaveTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim.Shape_Trim'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
}

