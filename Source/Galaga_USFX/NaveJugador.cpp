// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveJugador.h"
#include <iostream>

void ANaveJugador::MoverNave(float _npx, float _npy, float _npz)
{
	PosicionX += _npx;
	PosicionY += _npy;
	PosicionZ += _npz;
}

void ANaveJugador::AumentarPuntaje(float _nuevoPuntaje)
{
	PuntajeAcumulado += _nuevoPuntaje;
}

void ANaveJugador::ActualizarVidasRestantes(int _ControladorDeVidas)
{
	if (_ControladorDeVidas == 1)
	{
		VidasRestantes += 1;
	}
	else
	{
		VidasRestantes -= 1;
	}
	if (VidasRestantes == 0) {
		std::cout << "Ya no tienes vidas, Game Over" << std::endl;
	}
}

// Sets default values
ANaveJugador::ANaveJugador()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANaveJugador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveJugador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANaveJugador::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

