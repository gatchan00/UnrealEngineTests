// Fill out your copyright notice in the Description page of Project Settings.

#include "udemy_01.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
	//obtenemos el jugador
	QuienActivaEsto = GetWorld()->GetFirstPlayerController()->GetPawn();
	//this->OpenDoor();
	// ...
	
}

void UOpenDoor::OpenDoor() {
	AActor* owner = this->GetOwner();
	FRotator giro = FRotator(0.0f, OpenAngle, 0.0f);
	owner->SetActorRotation(giro);
	//GetOwner()->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));

}
void UOpenDoor::CloseDoor() {
	AActor* owner = this->GetOwner();
	FRotator giro = FRotator(0.0f, 0.0f, 0.0f);
	owner->SetActorRotation(giro);
}

// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	if (PlacaActivacion->IsOverlappingActor(QuienActivaEsto)) {
		this->OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	else if (GetWorld()->GetTimeSeconds() >= (LastDoorOpenTime+ DoorCloseDelay) )
	{ 
		this->CloseDoor(); 
	}
	// ...
	
}

