// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFXGameMode.h"
#include "Galaga_USFXPawn.h"
#include "EscuadronDeAtaqueEA1.h"
#include "CapitanGEscuadra.h"
#include "Escuadron.h"
#include "NaveEnemiga.h"
//#include "NaveEnemigaCaza.h"
//#include "NaveTransporte.h"
//#include "NaveCazaComun.h"
//#include "NaveCazaMini.h"
//#include "NaveColmena.h"
//#include "Proyectiles.h"
//#include "NaveMedico.h"

AGalaga_USFXGameMode::AGalaga_USFXGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFXPawn::StaticClass();
}

void AGalaga_USFXGameMode::BeginPlay() 
{
	Super::BeginPlay();

	
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		//spawn EA1 y Capitan
		EA1 = World->SpawnActor<AEscuadronDeAtaqueEA1>(AEscuadronDeAtaqueEA1::StaticClass());
		Capitan = World->SpawnActor<ACapitanGEscuadra>(ACapitanGEscuadra::StaticClass());

		Capitan->SetBuilderEscuadrones(EA1);
		Capitan->FormarEscuadron();

		AEscuadron* escuadron = Capitan->GetEscuadron();
		escuadron->DatosEscuadron();
	}

}
