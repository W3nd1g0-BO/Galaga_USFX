// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFXGameMode.h"
#include "Galaga_USFXPawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveTransporte.h"
#include "NaveCazaComun.h"
#include "NaveCazaMini.h"

AGalaga_USFXGameMode::AGalaga_USFXGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFXPawn::StaticClass();
}

void AGalaga_USFXGameMode::BeginPlay() 
{
	Super::BeginPlay();

	FVector ubicacionInicialNavesEnemigas = FVector(600.0f, 0.0f, 300.0f);
	FVector ubicacionActualNaveEnemiga = ubicacionInicialNavesEnemigas;
	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{

		for (int i = 0; i < 5; i++) {
			ANaveCazaComun* NaveEnemigaCazaActual = World->SpawnActor<ANaveCazaComun>(ubicacionActualNaveEnemiga, rotacionNave);
			//TANavesEnemigasCaza.Add(NaveEnemigaCazaActual);
			NaveEnemigaCazaActual->SetNombre("nave enemiga caza " + FString::FromInt(i));
			TANavesEnemigasCaza.Add(NaveEnemigaCazaActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaCazaActual, ubicacionActualNaveEnemiga);

			ubicacionActualNaveEnemiga.Y = ubicacionActualNaveEnemiga.Y + 150.0f;
		}

		ubicacionActualNaveEnemiga.X = ubicacionActualNaveEnemiga.X - 150.0f;
		ubicacionActualNaveEnemiga.Y = ubicacionInicialNavesEnemigas.Y;
		for (int j = 0; j < 3; j++) {

			ANaveTransporte* NaveEnemigaTransporteActual = World->SpawnActor<ANaveTransporte>(ubicacionActualNaveEnemiga, rotacionNave);
			//TANavesEnemigasTransporte.Add(NaveEnemigaTransporteActual);
			NaveEnemigaTransporteActual->SetNombre("nave enemiga transporte" + FString::FromInt(j));
			TANavesEnemigasTransporte.Add(NaveEnemigaTransporteActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaTransporteActual, ubicacionActualNaveEnemiga);

			ubicacionActualNaveEnemiga.Y = ubicacionActualNaveEnemiga.Y + 150.0f;
		}

			//FTimerHandle FTHVisualizacionPosicionesNavesEnemigas;

			//GetWorldTimerManager().SetTimer(FTHVisualizacionPosicionesNavesEnemigas, this, &AGalaga_USFXGameMode::MostrarPosicionesNavesEnemigas, 1.0f, true);

	}

		
		
		//FVector SpawnLocation = FVector(0.0f, 0.0f, 0.0f); // Define la posición de spawn
	//FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f); // Define la rotación de spawn

	//NaveEnemigaCaza01 = GetWorld()->SpawnActor<ANaveEnemigaCaza>(ANaveEnemigaCaza::StaticClass());
	//NaveEnemigaCaza02 = GetWorld()->SpawnActor<ANaveEnemigaCaza>(ANaveEnemigaCaza::StaticClass());

	// Displays a red message on the screen for 10 seconds
	
	
	
	//FVector ubicacionNaveCaza01 = FVector(-900.f, 500.0f, 250.0f);
	
}

