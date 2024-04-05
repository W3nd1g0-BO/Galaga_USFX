// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlNaveComponent.h"
#include "Proyectiles.h"

// Sets default values for this component's properties
UControlNaveComponent::UControlNaveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//Set ActorToSpawn to Proyectiles
	ActorToSpawn = AProyectiles::StaticClass();
}


// Called when the game starts
void UControlNaveComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UControlNaveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UControlNaveComponent::Spawn()
{
    UWorld* TheWorld = GetWorld();
    if (TheWorld != nullptr)
    {
        FTransform ComponentTransform = this->GetComponentTransform();
        FVector SpawnLocation = ComponentTransform.GetLocation() - FVector(0.0f, 0.0f, 200.0f); // Update the spawn location
        FTransform SpawnTransform(SpawnLocation);
        TheWorld->SpawnActor(ActorToSpawn, &SpawnTransform);
    }
}