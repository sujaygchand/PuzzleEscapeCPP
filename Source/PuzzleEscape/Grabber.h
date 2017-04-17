// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PUZZLEESCAPE_API UGrabber : public UActorComponent {
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// Pushs line trace by
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	// Finds physics handle
	void FindPhysicsHandleComponent();

	// Sets up input component
	void SetupInputComponent();

	// grab while ray-casting
	void Grab();

	// Release Object
	void Release();

	// Return hit for the first physics body in reach
	FHitResult GetFirstPhysicsBodyInReach() const;
	
	// Return start of reach line
	FVector GetReachLineStart() const;

	// Return end of reach line
	FVector GetReachLineEnd() const;
};
