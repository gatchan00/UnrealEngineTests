// Fill out your copyright notice in the Description page of Project Settings.

#include "udemy_01.h"
#include "PositionReport.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	FString tempString = this->GetOwner()->GetName();
	float x = this->GetOwner()->GetTransform().GetLocation().X;
	float y = this->GetOwner()->GetTransform().GetLocation().Y;
	float z = this->GetOwner()->GetTransform().GetLocation().Z;
	FString tempString2 = " pos: X= Y=";
	UE_LOG(LogTemp, Warning, TEXT("Begin play para %s con X=%3.2f Y=%3.2f Z=%3.2f"),*tempString, x,y,z);
	
}


// Called every frame
void UPositionReport::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	// ...
}

