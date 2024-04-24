// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricNaveEnemiga.h"
//#include "NaveApoyo.h"
//#include "NaveArtillera.h"
#include "NaveBombardera.h"
#include "NaveBonus.h"
#include "NaveCannon.h"
#include "NaveCarguera.h"
#include "NaveCazaComun.h"
#include "NaveCazaMini.h"
#include "NaveColmena.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEscudo.h"
//#include "NaveJefe.h"
#include "NaveMedico.h"
#include "NaveNodriza.h"
#include "NaveTitan.h"
//#include "NaveTransporte.h"

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