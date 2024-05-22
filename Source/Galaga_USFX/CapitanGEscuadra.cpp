// Fill out your copyright notice in the Description page of Project Settings.


#include "CapitanGEscuadra.h"
#include "Escuadron.h"

// Sets default values
ACapitanGEscuadra::ACapitanGEscuadra()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACapitanGEscuadra::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACapitanGEscuadra::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACapitanGEscuadra::SetBuilderEscuadrones(AActor* builder)
{
	BuilderEscuadrones = Cast<IBuilderEscuadronesDeAtaque>(builder);
	if (!BuilderEscuadrones)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red,
			TEXT("Invalid Cast! See Output log for more details"));
		UE_LOG(LogTemp, Error, TEXT("SetLodgingBuilder(): The Actor is not a LodgingBuilder! Are you sure that the Actor implements that interface ? "));
	}
}

AEscuadron* ACapitanGEscuadra::GetEscuadron()
{
	if (!BuilderEscuadrones)
	{
		UE_LOG(LogTemp, Error, TEXT("GetLodging(): Return nullptr"));
		return nullptr;
	}
	
	return BuilderEscuadrones->getEscuadron();
}

void ACapitanGEscuadra::ConstruirEscuadron(AActor* builder)
{
	SetBuilderEscuadrones(builder);
	FormarEscuadron();

	AEscuadron* escuadron = GetEscuadron();
	escuadron->DatosEscuadron();
}

void ACapitanGEscuadra::FormarEscuadron()
{
	if (!BuilderEscuadrones) { UE_LOG(LogTemp, Error, TEXT("ConstructLodging(): LodgingBuilder is NULL, make sure it's initialized.")); return; }
	BuilderEscuadrones->buildCantEnemigos();
	BuilderEscuadrones->buildFormacionEscuadron();
	BuilderEscuadrones->buildNivelEscuadron();
	BuilderEscuadrones->buildVelocidadEscuadron();
}


