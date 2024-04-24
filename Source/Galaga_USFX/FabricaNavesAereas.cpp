// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "FabricaNavesAereas.h"
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
//#include "NaveEnemigaCaza.h"
#include "NaveEscudo.h"
//#include "NaveJefe.h"
#include "NaveMedico.h"
#include "NaveNodriza.h"
#include "NaveTitan.h"
//#include "NaveTransporte.h"


ANaveEnemiga* AFabricaNavesAereas::fabricarNave(FString fabNave)
{
    if (fabNave.Equals("bombardera"))
        return GetWorld()->SpawnActor<ANaveBombardera>();
    if (fabNave.Equals("bonus"))
        return GetWorld()->SpawnActor<ANaveBonus>();
    if (fabNave.Equals("cannon"))
        return GetWorld()->SpawnActor<ANaveCannon>();
    if (fabNave.Equals("carguera"))
        return GetWorld()->SpawnActor<ANaveCarguera>();
    if (fabNave.Equals("cazaComun"))
        return GetWorld()->SpawnActor<ANaveCazaComun>();
    if (fabNave.Equals("cazaMini"))
        return GetWorld()->SpawnActor<ANaveCazaMini>();
    if (fabNave.Equals("colmena"))
        return GetWorld()->SpawnActor<ANaveColmena>();
    if (fabNave.Equals("escudo"))
        return GetWorld()->SpawnActor<ANaveEscudo>();
    if (fabNave.Equals("medico"))
        return GetWorld()->SpawnActor<ANaveMedico>();
    if (fabNave.Equals("nodriza"))
        return GetWorld()->SpawnActor<ANaveNodriza>();
    if (fabNave.Equals("titan"))
        return GetWorld()->SpawnActor<ANaveTitan>();
    else return nullptr;
};