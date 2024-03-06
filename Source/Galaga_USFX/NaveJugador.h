// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NaveJugador.generated.h"

UCLASS()
class GALAGA_USFX_API ANaveJugador : public APawn
{
	GENERATED_BODY()

private:
	
	float PosicionX;
	float PosicionY;
	float PosicionZ;
	float PuntajeAcumulado;
	int VidasRestantes;
public:

	// Getters para las posiciones
	FORCEINLINE float GetPosicionX() const { return PosicionX; }
	FORCEINLINE float GetPosicionY() const { return PosicionY; }
	FORCEINLINE float GetPosicionZ() const { return PosicionZ; }

	// Getter para el puntaje acumulado
	FORCEINLINE float GetPuntajeAcumulado() const { return PuntajeAcumulado; }

	// Getter para las vidas restantes
	FORCEINLINE int GetVidasRestantes() const { return VidasRestantes; }

	// Setters para las posiciones
	FORCEINLINE void SetPosicionX(float _npx) { PosicionX = _npx; }
	FORCEINLINE void SetPosicionY(float _npy) { PosicionY = _npy; }
	FORCEINLINE void SetPosicionZ(float _npz) { PosicionZ = _npz; }

	// Setter para el puntaje acumulado
	FORCEINLINE void SetPuntajeAcumulado(float _nuevoPuntaje) { PuntajeAcumulado = _nuevoPuntaje; }

	// Setter para las vidas restantes
	FORCEINLINE void SetVidasRestantes(int _ControladorDeVidas) { VidasRestantes = _ControladorDeVidas; }

private:

	void MoverNave(float _npx, float _npy, float _npz);
	void AumentarPuntaje(float _nuevoPuntaje);
	void ActualizarVidasRestantes(int _ControladorDeVidas);

public:
	// Sets default values for this pawn's properties
	ANaveJugador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
