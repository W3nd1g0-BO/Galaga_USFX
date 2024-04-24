// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "FabricNaveEnemiga.generated.h"


UCLASS()
class GALAGA_USFX_API AFabricNaveEnemiga : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricNaveEnemiga();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	ANaveEnemiga* tipoNave(FString tipoNave);

	virtual ANaveEnemiga* fabricarNave(FString fabNave) 
		PURE_VIRTUAL(AFabricNaveEnemiga::fabricarNave, return nullptr;);
	
};
