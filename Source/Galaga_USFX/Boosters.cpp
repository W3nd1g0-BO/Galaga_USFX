// Fill out your copyright notice in the Description page of Project Settings.


#include "Boosters.h"

// Sets default values
ABoosters::ABoosters()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the mesh component
	mallaCapsula = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CapsuleMesh"));

	mallaCapsula->SetupAttachment(RootComponent);
	RootComponent = mallaCapsula;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	mallaCapsula->SetStaticMesh(Mesh.Object);

}

// Called when the game starts or when spawned
void ABoosters::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoosters::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

