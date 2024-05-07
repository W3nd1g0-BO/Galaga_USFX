// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Comp_MovimientoNaves.h"
#include "EstrategiaMovimiento.h"
#include "NaveEnemiga.generated.h"


class UStaticMeshComponent;
class UComp_MovimientoNaves;
class UEstrategiaMovimiento;

UCLASS(abstract)
class GALAGA_USFX_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* mallaNaveEnemiga;
		UComp_MovimientoNaves* compNave;
		UEstrategiaMovimiento* estrategiaMovimiento;

protected:
	float velocidad;
	float velocidadDisparo;
	float resistencia;
	float valorDestruccion;
	float tiempoDisparo;
	float energia;
	FVector posicion;
	FString nombre;
	FString movimiento;
public:
	//Metodos Acesores                                                                                
	FORCEINLINE float GetVelocidad() const { return velocidad; }
	FORCEINLINE float GetVelocidadDisparo() const {return velocidadDisparo;}
	FORCEINLINE float GetResistencia() const { return resistencia; }
	FORCEINLINE float GetValorDestruccion() const {return valorDestruccion;}
	FORCEINLINE float GetTiempoDisparo() const { return tiempoDisparo; }
	FORCEINLINE float GetEnergia() const { return energia; }
	FORCEINLINE FVector GetPosicion() const { return posicion; }
	FORCEINLINE FString GetNombre() const { return nombre; }
	FORCEINLINE	FString GetMovimiento() const { return movimiento; }
	//FORCEINLINE FVector GetTrayectoria() const { return trayectoria; }

	FORCEINLINE void SetVelocidad(float _velocidad) { velocidad = _velocidad; }
	FORCEINLINE void SetVelocidadDisparo(float _velocidadDisparo) { velocidadDisparo = _velocidadDisparo;}
	FORCEINLINE void SetResistencia(float _resistencia) {resistencia = _resistencia; }
	FORCEINLINE void SetValorDestruccion(float _valorDestrucion){ valorDestruccion = _valorDestrucion; }
	FORCEINLINE void SetTiempoDisparo(float _tiempoDisparo) { tiempoDisparo = _tiempoDisparo; }
	FORCEINLINE void SetEnergia(float _energia)  {energia = _energia ; }
	FORCEINLINE void SetPosicion(FVector _posicion) { posicion = _posicion; }
	FORCEINLINE void SetNombre(FString _nombre)  {nombre=_nombre; }
	FORCEINLINE void SetMovimiento(FString _movimiento) {movimiento = _movimiento; }
	//FORCEINLINE void SetTrayectoria(FVector _trayectoria) { trayectoria = _trayectoria; }

public:	
	// Sets default values for this actor's properties
	ANaveEnemiga();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
