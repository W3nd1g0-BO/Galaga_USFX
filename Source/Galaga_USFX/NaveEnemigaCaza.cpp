// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveEnemigaCaza.h"




// Called when the game starts or when spawned
void ANaveEnemigaCaza::BeginPlay()
{
	Super::BeginPlay();

};

ANaveEnemigaCaza::ANaveEnemigaCaza():ANaveEnemiga()
{
	
};

// Called every frame
void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

};

void ANaveEnemigaCaza::Mover(float DeltaTime)
{
	
};

//Funcion que contabiliza el daño recibido por la nave, esta nave solo puede recibir un disparo
//void ANaveEnemigaCaza::Daño()
//{
//
//
//};
//
////Funcion que destruye la nave y la elimina
//void ANaveEnemigaCaza::Destruir()
//{
//
//};


//void ANaveEnemigaCaza::Atacar()
//{
//
//};
