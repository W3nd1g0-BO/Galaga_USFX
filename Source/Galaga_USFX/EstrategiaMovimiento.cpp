// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaMovimiento.h"

void UEstrategiaMovimiento::FuncElegirMovimiento(FString _tipoMovimiento)
{

    if (_tipoMovimiento.Equals("infinito"))
    {
        Mov_FormInfinito();
    }
    if (_tipoMovimiento.Equals("horizontal"))
    {
        Mov_Horizontal();
    }
    if (_tipoMovimiento.Equals("aleatorio"))
	{
        Mov_Aleatoriamente();
	}
};

void UEstrategiaMovimiento::Mov_Aleatoriamente()
{
    // Obtiene la posici�n actual del actor
    FVector PosicionActual = nave->GetActorLocation();

    float Tiempo = FPlatformTime::Seconds();
    float NuevaX = FMath::RandRange(-1000.0f, 1000.0f) * Tiempo;
    float NuevaY = FMath::RandRange(-1000.0f, 1000.0f) * Tiempo;

    // Crea un nuevo vector de posici�n con las coordenadas aleatorias y la misma Z que la posici�n actual
    FVector NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

    // Establece la nueva posici�n del actor
    nave->SetActorLocation(NuevaPosicion);
}

void UEstrategiaMovimiento::Mov_FormInfinito()
{
    FVector posicionInicial = GetOwner()->GetActorLocation();
    float Tiempo = FPlatformTime::Seconds();
    float velocidad = 10.0f;
    float rangoMov = 500.0f; // El tama�o de la figura que har� la nave


    FVector nuevaPosicion;
    nuevaPosicion.X = rangoMov * FMath::Sin(velocidad * Tiempo);
    nuevaPosicion.Y = rangoMov * FMath::Sin(2 * velocidad * Tiempo) / 2;
    nuevaPosicion.Z = GetOwner()->GetActorLocation().Z;


    nuevaPosicion += posicionInicial;

    // Movemos la nave en la nueva posici�n
    GetOwner()->SetActorLocation(nuevaPosicion);
};

//void UComp_MovimientoNaves::Mov_FormZigZag(float DeltaTime)
//{
//    // Obtiene la posici�n actual del actor
//    FVector PosicionActual = GetOwner()->GetActorLocation();
//
//    // Define la velocidad de movimiento
//    velocidad = 100.0f;
//
//    // Define un vector de direcci�n. Este puede ser un vector aleatorio o un vector espec�fico dependiendo de tus necesidades.
//    trayectoria = FVector(FMath::RandRange(-1, 1), FMath::RandRange(-1, 1), 0);
//
//    // Normaliza el vector de direcci�n
//    trayectoria.Normalize();
//
//    // Calcula el desplazamiento
//    FVector Desplazamiento = velocidad * trayectoria * DeltaTime;
//
//    // Calcula la nueva posici�n
//    FVector NuevaPosicion = PosicionActual + Desplazamiento;
//
//    // Verifica si la nueva posici�n est� fuera de los l�mites del mapa y ajusta la posici�n si es necesario
//    if (NuevaPosicion.X >= limitedeMapa.Max.X) { NuevaPosicion.X = limitedeMapa.Min.X; }
//    else if (NuevaPosicion.X <= limitedeMapa.Min.X) { NuevaPosicion.X = limitedeMapa.Max.X; }
//
//    if (NuevaPosicion.Y >= limitedeMapa.Max.Y) { NuevaPosicion.Y = limitedeMapa.Min.Y; }
//    else if (NuevaPosicion.Y <= limitedeMapa.Min.Y) { NuevaPosicion.Y = limitedeMapa.Max.Y; }
//
//    // Actualiza la posici�n del actor
//    GetOwner()->SetActorLocation(NuevaPosicion);
//};
//
void UEstrategiaMovimiento::Mov_Horizontal()
{
    FVector posicionInicial = GetOwner()->GetActorLocation();
    float Tiempo = FPlatformTime::Seconds();
    float velocidad = 10.0f;
    float rangoMov = 250.0f; // El tama�o del movimiento horizontal

    FVector nuevaPosicion = posicionInicial;
    nuevaPosicion.X += velocidad * Tiempo;

    // Verifica si la nueva posici�n est� fuera de los l�mites del movimiento horizontal y cambia la direcci�n si es necesario
    if (nuevaPosicion.X >= posicionInicial.X + rangoMov) { velocidad = -10.0f; }
    else if (nuevaPosicion.X <= posicionInicial.X - rangoMov) { velocidad = 10.0f; }


    // Movemos la nave en la nueva posici�n
    GetOwner()->SetActorLocation(nuevaPosicion);

};
