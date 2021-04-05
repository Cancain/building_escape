// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UOpenDoor::BeginPlay(){
	Super::BeginPlay();

	// const FRotator CurrentRotation{GetOwner()->GetActorRotation()};
	// FRotator OpenRotation{CurrentRotation};
	// OpenRotation.Yaw = 90;

	const FRotator OpenRotation = {0.f, 90.f, 0.f};
	GetOwner()->SetActorRotation(OpenRotation);
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
