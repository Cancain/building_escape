#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor() {
	PrimaryComponentTick.bCanEverTick = true;
}

void UOpenDoor::BeginPlay() {
	Super::BeginPlay();

	const AActor* Owner{GetOwner()};
	InitalYaw = Owner->GetActorRotation().Yaw;
	CurrentYaw = InitalYaw;
	OpenAngle += InitalYaw;

	if(!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("%s has the open door component on it, but no pressureplate set!"),
		       *Owner->GetName())
	}

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::TickComponent(const float DeltaTime, const ELevelTick TickType,
                              FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens)) {
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
	} else if(GetWorld()->GetTimeSeconds() > DoorLastOpened + DoorCloseDelay) {
		CloseDoor(DeltaTime);
	}
}

void UOpenDoor::OpenDoor(const float DeltaTime) {
	CurrentYaw = FMath::Lerp(CurrentYaw, OpenAngle, DeltaTime * DoorClosingVelocity);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;

	if(FMath::RoundFromZero(CurrentYaw) < OpenAngle) {
		GetOwner()->SetActorRotation(DoorRotation);
	}
}

void UOpenDoor::CloseDoor(const float DeltaTime) {
	CurrentYaw = FMath::Lerp(CurrentYaw, InitalYaw, DeltaTime * DoorOpeningVelocity);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;

	if(FMath::RoundFromZero(CurrentYaw) > InitalYaw) {
		GetOwner()->SetActorRotation(DoorRotation);
	}
}
