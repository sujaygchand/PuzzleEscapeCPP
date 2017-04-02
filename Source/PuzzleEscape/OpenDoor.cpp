// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleEscape.h"
#include "OpenDoor.h"


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

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}

void UOpenDoor::OpenDoor() {

	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));

}

void UOpenDoor::CloseDoor() {

	// Set the door rotation
	Owner->SetActorRotation(FRotator(0.f, 0, 0.f));

}

// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Poll the trigger volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) 
	{
		// If that actor that opens is in the volumes
		OpenDoor();

		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	if (!(PressurePlate->IsOverlappingActor(ActorThatOpens)) && GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) 
	{
		CloseDoor();
	}

}

