// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleEscape.h"
#include "OpenDoor.h"

#define OUT


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Poll the trigger volume
	if (GetTotalMassOfActorsOnPlate() > OpeningMass) 
	{
		// If that actor that opens is in the volumes
		OnOpenRequest.Broadcast();
	}
	else
	{
		OnCloseRequest.Broadcast();
	}
}

float UOpenDoor::GetTotalMassOfActorsOnPlate() {

	float TotalMass = 0.f;


	if (!PressurePlate) {
		
		// Input component is found
		UE_LOG(LogTemp, Warning, TEXT("Pressure Plate missing"))
		
		return TotalMass;  }
	// Find all the overlapping actors
	TArray<AActor*>OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	// iterate through them adding their masses
	for (const auto& ActorOnPlate : OverlappingActors)
	{
		TotalMass += ActorOnPlate->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *ActorOnPlate->GetName())
	}

	return TotalMass;
}

