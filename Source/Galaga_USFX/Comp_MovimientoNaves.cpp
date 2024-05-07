// Fill out your copyright notice in the Description page of Project Settings.


#include "Comp_MovimientoNaves.h"
#include "math.h"

// Sets default values for this component's properties
UComp_MovimientoNaves::UComp_MovimientoNaves()
{
	PrimaryComponentTick.bCanEverTick = true;

    limitedeMapa = FBox(FVector(-2000.0f, -2000.0f, 0.0f), FVector(2000.0f, 2000.0f, 500.0f));

}
			

// Called when the game starts
void UComp_MovimientoNaves::BeginPlay()
{
	Super::BeginPlay();
	// ...
}

// Called every frame
void UComp_MovimientoNaves::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

UComp_MovimientoNaves* UComp_MovimientoNaves::FuncElegirMovimiento(FString _tipoMovimiento, float DeltaTime)
{

	return nullptr;
}

void UComp_MovimientoNaves::SetLimitesMapa(FBox limites)
{
	limitedeMapa = limites;
}