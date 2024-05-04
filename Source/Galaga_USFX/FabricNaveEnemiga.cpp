// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricNaveEnemiga.h"
#include "NaveEnemiga.h"

// Sets default values
AFabricNaveEnemiga::AFabricNaveEnemiga()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void AFabricNaveEnemiga::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFabricNaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ANaveEnemiga* AFabricNaveEnemiga::tipoNave(FString tipoNave)
{
	ANaveEnemiga* nave = fabricarNave(tipoNave);
	return nave;
}