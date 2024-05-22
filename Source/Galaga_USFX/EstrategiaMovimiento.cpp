// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaMovimiento.h"

UEstrategiaMovimiento::UEstrategiaMovimiento()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UEstrategiaMovimiento::BeginPlay()
{
    nave = GetOwner();
    Super::BeginPlay();
}

void UEstrategiaMovimiento::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    UEstrategiaMovimiento::FuncElegirMovimiento(ElegirMovimiento, DeltaTime);
};

UComp_MovimientoNaves* UEstrategiaMovimiento::FuncElegirMovimiento(FString _tipoMovimiento,float DeltaTime)
{
    //mensaje en log indicando que se ha seleccionado un tipo de movimiento y el tipo seleccionado
    UE_LOG(LogTemp, Warning, TEXT("Se ha seleccionado un tipo de movimiento: %s"), *_tipoMovimiento);
    if (_tipoMovimiento.IsEmpty())
    {
        UE_LOG(LogTemp, Error, TEXT("No se ha seleccionado un tipo de movimiento"));
        return nullptr;
    }
    if (_tipoMovimiento.Equals("infinito"))
    {
        Mov_FormInfinito(DeltaTime);
    }
    else if (_tipoMovimiento.Equals("horizontal"))
    {
        Mov_Horizontal(DeltaTime);
    }
    else if (_tipoMovimiento.Equals("aleatorio"))
	{
        Mov_Aleatoriamente(DeltaTime);
	}
    else if (_tipoMovimiento.Equals("lineal"))
    {
		Mov_lineal(DeltaTime);
	}
    else if (_tipoMovimiento.Equals("pendulo"))
    {
        Mov_pendulo(DeltaTime);
    }
        return nullptr;
}

void UEstrategiaMovimiento::ComprobarLimites(FVector& _nuevaPosicion)
{
    NuevaPosicion = _nuevaPosicion;
    if (NuevaPosicion.X >= limitedeMapa.Max.X || NuevaPosicion.Y >= limitedeMapa.Max.Y)
    {
        if (NuevaPosicion.X >= limitedeMapa.Max.X) { NuevaPosicion.X = limitedeMapa.Min.X; };
        if (NuevaPosicion.Y >= limitedeMapa.Max.Y) { NuevaPosicion.Y = limitedeMapa.Min.Y; };
    }
    else if (NuevaPosicion.X <= limitedeMapa.Min.X || NuevaPosicion.Y <= limitedeMapa.Min.Y)
    {
        if (NuevaPosicion.X <= limitedeMapa.Min.X) { NuevaPosicion.X = limitedeMapa.Max.X; };
        if (NuevaPosicion.Y <= limitedeMapa.Min.Y) { NuevaPosicion.Y = limitedeMapa.Max.Y; };
    };
}

void UEstrategiaMovimiento::Mov_pendulo(float DeltaTime)
{
    if (bMovimientoIniciado==false) 
    {
        PuntoInicio = nave->GetActorLocation();
		PuntoFinal = PuntoInicio + FVector(0.0f, 500.0f, 0.0f);
        bMovimientoIniciado = true;
    }

    float velc = 100.0f;
    Alpha += velc * DeltaTime;
    NuevaPosicion = FMath::Lerp(PuntoInicio, PuntoFinal, Alpha / 360.0f);
    nave->SetActorLocation(NuevaPosicion);

    if (Alpha >= 360.0f)
    {
        Alpha = 0;
        FVector aux = PuntoInicio;
        PuntoInicio = PuntoFinal;
        PuntoFinal = aux;
    }
}



void UEstrategiaMovimiento::Mov_lineal(float DeltaTime)
{
    PosicionActual = nave->GetActorLocation();

     velocidad=FVector(100.0f,100.0f,0.0f);

     NuevaPosicion = PosicionActual + velocidad * DeltaTime;

     ComprobarLimites(NuevaPosicion);

    nave->SetActorLocation(NuevaPosicion);
};



void UEstrategiaMovimiento::Mov_Aleatoriamente(float DeltaTime)
{
    PosicionActual = nave->GetActorLocation();

    // Genera nuevas coordenadas X e Y aleatorias
    float NuevaX = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;
    float NuevaY = FMath::RandRange(-1000.0f, 1000.0f) * DeltaTime;

    NuevaPosicion = FVector(PosicionActual.X + NuevaX, PosicionActual.Y + NuevaY, PosicionActual.Z);

    ComprobarLimites(NuevaPosicion);

    // Establece la nueva posición del actor
    nave->SetActorLocation(NuevaPosicion);
}

void UEstrategiaMovimiento::Mov_FormInfinito(float DeltaTime)
{
    PosicionActual = GetOwner()->GetActorLocation();
    float velocidad1 = 10.0f;
    float rangoMov = 500.0f; // El tamaño de la figura que hará la nave


    FVector nuevaPosicion;
    nuevaPosicion.X = rangoMov * FMath::Sin(velocidad1 * DeltaTime);
    nuevaPosicion.Y = rangoMov * FMath::Sin(2 * velocidad1 * DeltaTime) / 2;
    //nuevaPosicion.Z = PosicionActual.Z;


    PosicionActual += nuevaPosicion;

    ComprobarLimites(NuevaPosicion);

    // Movemos la nave en la nueva posición
    GetOwner()->SetActorLocation(nuevaPosicion);
};

//void UComp_MovimientoNaves::Mov_FormZigZag(float DeltaTime)
//{
//    // Obtiene la posición actual del actor
//    FVector PosicionActual = GetOwner()->GetActorLocation();
//
//    // Define la velocidad de movimiento
//    velocidad = 100.0f;
//
//    // Define un vector de dirección. Este puede ser un vector aleatorio o un vector específico dependiendo de tus necesidades.
//    trayectoria = FVector(FMath::RandRange(-1, 1), FMath::RandRange(-1, 1), 0);
//
//    // Normaliza el vector de dirección
//    trayectoria.Normalize();
//
//    // Calcula el desplazamiento
//    FVector Desplazamiento = velocidad * trayectoria * DeltaTime;
//
//    // Calcula la nueva posición
//    FVector NuevaPosicion = PosicionActual + Desplazamiento;
//
//    // Verifica si la nueva posición está fuera de los límites del mapa y ajusta la posición si es necesario
//    if (NuevaPosicion.X >= limitedeMapa.Max.X) { NuevaPosicion.X = limitedeMapa.Min.X; }
//    else if (NuevaPosicion.X <= limitedeMapa.Min.X) { NuevaPosicion.X = limitedeMapa.Max.X; }
//
//    if (NuevaPosicion.Y >= limitedeMapa.Max.Y) { NuevaPosicion.Y = limitedeMapa.Min.Y; }
//    else if (NuevaPosicion.Y <= limitedeMapa.Min.Y) { NuevaPosicion.Y = limitedeMapa.Max.Y; }
//
//    // Actualiza la posición del actor
//    GetOwner()->SetActorLocation(NuevaPosicion);
//};
//
void UEstrategiaMovimiento::Mov_Horizontal(float DeltaTime)
{
    FVector posicionInicial = GetOwner()->GetActorLocation();
    
    float velocidad1 = 10.0f;
    float rangoMov = 250.0f; // El tamaño del movimiento horizontal

    FVector nuevaPosicion = posicionInicial;
    nuevaPosicion.X += velocidad1 * DeltaTime;

    // Verifica si la nueva posición está fuera de los límites del movimiento horizontal y cambia la dirección si es necesario
    if (nuevaPosicion.X >= posicionInicial.X + rangoMov) { velocidad1 = -10.0f; }
    else if (nuevaPosicion.X <= posicionInicial.X - rangoMov) { velocidad1 = 10.0f; }

    ComprobarLimites(NuevaPosicion);

    // Movemos la nave en la nueva posición
    GetOwner()->SetActorLocation(nuevaPosicion);

};
