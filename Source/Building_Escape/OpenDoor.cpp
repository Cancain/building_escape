#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor(){ PrimaryComponentTick.bCanEverTick = true; }

void UOpenDoor::BeginPlay(){
	Super::BeginPlay();

	InitalYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitalYaw;
	TargetYaw += InitalYaw;
}

void UOpenDoor::TickComponent(const float DeltaTime, const ELevelTick TickType,
                              FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, DeltaTime * 0.5f);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;

	if(FMath::RoundFromZero(CurrentYaw) < TargetYaw){
		UE_LOG(LogTemp, Warning, TEXT("%f"), FMath::RoundFromZero(CurrentYaw));
		GetOwner()->SetActorRotation(DoorRotation);
	}

}
