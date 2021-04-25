#include "OpenDoor.h"

#include <Actor.h>

#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor() { PrimaryComponentTick.bCanEverTick = true; }

void UOpenDoor::BeginPlay()
	{
		Super::BeginPlay();

		AActor* Owner{GetOwner()};
		InitalYaw = Owner->GetActorRotation().Yaw;
		CurrentYaw = InitalYaw;
		TargetYaw += InitalYaw;

		if(!PressurePlate){
			UE_LOG(LogTemp, Error, TEXT("%s has the open door component on it, but no pressureplate set!"),
			       *Owner->GetName())
		}
	}

void UOpenDoor::TickComponent(const float DeltaTime, const ELevelTick TickType,
                              FActorComponentTickFunction* ThisTickFunction)
	{
		Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

		if(PressurePlate && PressurePlate->IsOverlappingActor(ActorThatOpens)){
			OpenDoor(DeltaTime);
		}
	}

void UOpenDoor::OpenDoor(const float DeltaTime)
	{
		CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, DeltaTime * 0.5f);
		FRotator DoorRotation = GetOwner()->GetActorRotation();
		DoorRotation.Yaw = CurrentYaw;

		if(FMath::RoundFromZero(CurrentYaw) < TargetYaw){
			UE_LOG(LogTemp, Warning, TEXT("%f"), FMath::RoundFromZero(CurrentYaw));
			GetOwner()->SetActorRotation(DoorRotation);
		}
	}
