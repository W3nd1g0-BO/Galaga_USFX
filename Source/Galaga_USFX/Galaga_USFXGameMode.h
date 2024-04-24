// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFXGameMode.generated.h"

class FabricaNavesAereas;
class ANaveEnemiga;

UCLASS(MinimalAPI)
class AGalaga_USFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFXGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	//ANaveEnemiga* NaveEnemiga01;
	//ANaveEnemigaCaza* NaveEnemigaCaza01;
	//ANaveEnemigaCaza* NaveEnemigaCaza02;
	//ANaveTransporte* NaveTransporte01;
	//ANaveTransporte* NaveTransporte02;
public:
	//TArray<ANaveEnemiga*> TANavesEnemigas;
	//TArray<ANaveEnemigaCaza*> TANavesEnemigasCaza;
	//TArray<ANaveTransporte*> TANavesEnemigasTransporte;
	//TArray<ANaveEnemiga*> TANaveCazaComun;
	//TArray<ANaveMedico*> TANavesMedico;
};



