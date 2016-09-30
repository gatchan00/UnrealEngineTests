// Fill out your copyright notice in the Description page of Project Settings.

#include "udemy_01.h"
#include "Grabber.h"


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;


	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	//get player view point this tick
	FVector viewPlayerLocator;
	FRotator viewPlayerRotator;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(viewPlayerLocator, viewPlayerRotator);
	UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation %s"), *viewPlayerLocator.ToString(), *viewPlayerRotator.ToString()
	)

	//debug line
	//FVector LineTraceEnd = viewPlayerLocator + FVector(100.0f, 0.0f, 0.0f);
	FVector LineTraceEnd = viewPlayerLocator + viewPlayerRotator.Vector()*Reach;
	DrawDebugLine(
		GetWorld(),
		viewPlayerLocator,//desde donde se pinta la línea
		LineTraceEnd,//hasta donde se pinta la línea
		FColor(255, 0, 0),//el color
		false,//solo se pinta ese frame
		0.0f,//nada de life time
		0.0f,//nada de deep prioridad
		10.0f //10 cm de grosor
	);
	//ray-cast out to reach distance (line trace)
	FHitResult TheHit;//el parámetro de salida
	GetWorld()->LineTraceSingleByObjectType(TheHit,//lo que golpea
		viewPlayerLocator,//desde donde
		LineTraceEnd,//hasta donde miro
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),//esto es el FCollisionoObjectQueryParams, hay 7 constructores
						//nosotros le metemos el canal de PhysicBody
		FCollisionQueryParams(FName(TEXT("")), false, GetOwner())
		//nombre, false para tracecomplex, e ignore hit con el actor-dueño
	);
	AActor* ActorHit = TheHit.GetActor();
	if (ActorHit) {
		UE_LOG(LogTemp,Warning,TEXT("Line trace hit: %s"),*(ActorHit->GetName()))
	}
	//see what we hit
}

