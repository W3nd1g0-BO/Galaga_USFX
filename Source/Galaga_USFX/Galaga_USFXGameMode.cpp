// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFXGameMode.h"
#include "Galaga_USFXPawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveTransporte.h"
#include "NaveCazaComun.h"
#include "NaveCazaMini.h"
#include "NaveColmena.h"
#include "Proyectiles.h"

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
	
	FTransform SpawnLocation;
	AProyectiles* SpawnedActor = GetWorld()->SpawnActor<AProyectiles>(AProyectiles::StaticClass(), SpawnLocation);

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

		//for (int j = 0; j < 3; j++) {

		//	ANaveColmena* NaveEnemigaTransporteActual = World->SpawnActor<ANaveColmena>(ubicacionActualNaveEnemiga, rotacionNave);
		//	//TANavesEnemigasTransporte.Add(NaveEnemigaTransporteActual);
		//	NaveEnemigaTransporteActual->SetNombre("nave enemiga colmena" + FString::FromInt(j));
		//	TANavesEnemigasTransporte.Add(NaveEnemigaTransporteActual);
		//	TMPosicionesNavesEnemigas.Add(NaveEnemigaTransporteActual, ubicacionActualNaveEnemiga);

		//	ubicacionActualNaveEnemiga.Y = ubicacionActualNaveEnemiga.Y + 150.0f;
		//}

			//FTimerHandle FTHVisualizacionPosicionesNavesEnemigas;

			//GetWorldTimerManager().SetTimer(FTHVisualizacionPosicionesNavesEnemigas, this, &AGalaga_USFXGameMode::MostrarPosicionesNavesEnemigas, 1.0f, true);

	}

	FTimerHandle Timer;
	GetWorldTimerManager().SetTimer(Timer, this,
		&AGalaga_USFXGameMode::DestroyProyectiles, 5.0f,true);

}

void AGalaga_USFXGameMode::DestroyProyectiles()
{
	for (AProyectiles* Proyectil : TProyectiles)
	{
		if (Proyectil != nullptr)
		{
			Proyectil->Destroy();
		}
	}

	// Clear the array
	TProyectiles.Empty();
}
