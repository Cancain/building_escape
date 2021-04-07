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

	// FRotator OpenRotation{CurrentRotation};
	// OpenRotation.Yaw = 90;
	{};
}

// Called every frame
void UOpenDoor::TickComponent(const float DeltaTime, const ELevelTick TickType,
                              FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	const float CurrentYaw{GetOwner()->GetActorRotation().Yaw};

	const float Rotation = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 0.4);
	const FRotator CurrentRotation{GetOwner()->GetActorRotation()};
	FRotator NewRotation{CurrentRotation};
	NewRotation.Yaw = Rotation;

	if(FMath::RoundFromZero(CurrentYaw) < TargetYaw){
		UE_LOG(LogTemp, Warning, TEXT("%f"), FMath::RoundFromZero(CurrentYaw));
		GetOwner()->SetActorRotation(NewRotation);
	}

}
