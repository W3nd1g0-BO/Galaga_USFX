// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectiles.h"

// Sets default values
AProyectiles::AProyectiles()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    mallaProyectil = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
    //mallaNaveEnemiga->SetStaticMesh(malla.Object);
    mallaProyectil->SetupAttachment(RootComponent);
    RootComponent = mallaProyectil;

    static ConstructorHelpers::FObjectFinder<UStaticMesh>Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
    mallaProyectil->SetStaticMesh(Mesh.Object);

    //Cambia la escala del proyectil
    mallaProyectil->SetWorldScale3D(FVector(0.6f, 0.6f, 0.6f));

    //Añade fisicas al proyectil
    mallaProyectil->SetSimulatePhysics(true);
    
}

// Called when the game starts or when spawned
void AProyectiles::BeginPlay()
{
    Super::BeginPlay();
    // Crear una instancia del componente de control de nave
    ControlNaveComponent = NewObject<UControlNaveComponent>(this);

    // Adjuntar el componente al actor
    ControlNaveComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

   SetLifeSpan(3.0f);
   
}

void AProyectiles::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
