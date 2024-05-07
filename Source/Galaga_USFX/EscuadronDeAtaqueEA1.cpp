// Fill out your copyright notice in the Description page of Project Settings.


#include "EscuadronDeAtaqueEA1.h"
#include "Escuadron.h"
#include "NaveEnemiga.h"
#include "FabricNaveEnemiga.h"
#include "FabricaNavesAereas.h"

// Sets default values
AEscuadronDeAtaqueEA1::AEscuadronDeAtaqueEA1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEscuadronDeAtaqueEA1::BeginPlay()
{
	Super::BeginPlay();
	
	//Spawn the Lodging Actors
	escuadron=GetWorld()->SpawnActor<AEscuadron>
		(AEscuadron::StaticClass());
	//Attach it to the Builder (this)
	escuadron->AttachToActor(this,
		FAttachmentTransformRules::KeepRelativeTransform);

	FabricaNavesAereas = GetWorld()->SpawnActor<AFabricaNavesAereas>(AFabricaNavesAereas::StaticClass());

}

// Called every frame
void AEscuadronDeAtaqueEA1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEscuadronDeAtaqueEA1::buildFormacionEscuadron()
{
	if (!escuadron)
	{
		UE_LOG(LogTemp, Error, TEXT("buildFormacionEscuadron(): escuadron is NULL, make sure it's initialized.")); return; 
	}
	escuadron->setFormacionEscuadron("Forma Cuadrada");
	FVector posicionInicial = FVector(0.0f,0.0f, 300.0f);

	if (TNavesEnemigas.Num() != 0)
	{
		//recorrer el arreglo de naves enemigas y asignarles una posicion en la formacion
		for (int i = 0; i < TNavesEnemigas.Num(); i++)
		{
			TNavesEnemigas[i]->SetActorLocation(posicionInicial);
			TNavesEnemigas[i]->SetMovimiento("lineal");
			posicionInicial.X += 200.0f;
			if (posicionInicial.X >= 1000.0f) 
			{
				posicionInicial.X = 0.0f;
				posicionInicial.Y += 200.0f;
			};
		}
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("buildFormacionEscuadron(): TNavesEnemigas is empty, make sure it's initialized.")); return;
	}
}

void AEscuadronDeAtaqueEA1::buildVelocidadEscuadron()
{
	if (!escuadron)
	{
		UE_LOG(LogTemp, Error, TEXT("buildFormacionEscuadron(): escuadron is NULL, make sure it's initialized.")); return;
	}
}

void AEscuadronDeAtaqueEA1::buildCantEnemigos()
{
	if (!escuadron)
	{
		UE_LOG(LogTemp, Error, TEXT("buildFormacionEscuadron(): escuadron is NULL, make sure it's initialized.")); return;
	}

	escuadron ->setCantEnemigos(20);

	for (int i = 0; i <= 34; i++)
	{
		NaveEnemiga = FabricaNavesAereas->fabricarNave("cazaComun");
		NaveEnemiga->SetNombre("Caza Comun" + FString::FromInt(i));
		TNavesEnemigas.Add(NaveEnemiga);
	}
}

void AEscuadronDeAtaqueEA1::buildNivelEscuadron()
{
	if (!escuadron)
	{
		UE_LOG(LogTemp, Error, TEXT("buildFormacionEscuadron(): escuadron is NULL, make sure it's initialized.")); return;
	}
}

AEscuadron* AEscuadronDeAtaqueEA1::getEscuadron()
{
	return escuadron;
}

