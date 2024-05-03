// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFXGameMode.h"
#include "Galaga_USFXPawn.h"
#include "FabricaNavesAereas.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveTransporte.h"
#include "NaveCazaComun.h"
#include "NaveCazaMini.h"
#include "NaveColmena.h"
#include "Proyectiles.h"
#include "NaveMedico.h"

AGalaga_USFXGameMode::AGalaga_USFXGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFXPawn::StaticClass();
}

void AGalaga_USFXGameMode::BeginPlay() 
{
	Super::BeginPlay();

	AFabricNaveEnemiga* FabricaNavesAereas = GetWorld()->SpawnActor<AFabricaNavesAereas>(AFabricaNavesAereas::StaticClass());

	FVector ubicacionInicialNavesEnemigas = FVector(600.0f, 0.0f, 200.0f);
	FVector ubicacionActualNaveEnemiga = ubicacionInicialNavesEnemigas;
	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		for (int i = 0; i < 5; i++)
		{
			ANaveEnemiga* naveCreada = FabricaNavesAereas->fabricarNave("cazaComun");
			
			if (naveCreada != nullptr)
			{
				naveCreada->SetActorLocation(ubicacionActualNaveEnemiga);
				naveCreada->SetActorRotation(rotacionNave);
				naveCreada->SetNombre("nave enemiga caza " + FString::FromInt(i));
				naveCreada->SetMovimiento("aleatorio");

				//TANaveCazaComun.Add(naveCreada);
				//TMPosicionesNavesEnemigas.Add(naveCreada, ubicacionActualNaveEnemiga);

				ubicacionActualNaveEnemiga.Y = ubicacionActualNaveEnemiga.Y + 200.0f;
			}
		}


		//for (int f = 0; f < 6; f++) {
		//	ANaveMedico* NaveEnemigaCazaActual = World->SpawnActor<ANaveMedico>(ubicacionActualNaveEnemiga, rotacionNave);
		//	NaveEnemigaCazaActual->SetNombre("nave enemiga caza " + FString::FromInt(f));
		//	TANavesMedico.Add(NaveEnemigaCazaActual);
		//	TMPosicionesNavesEnemigas.Add(NaveEnemigaCazaActual, ubicacionActualNaveEnemiga);

		//	ubicacionActualNaveEnemiga.Y = ubicacionActualNaveEnemiga.Y + 200.0f;
		//}

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

}
