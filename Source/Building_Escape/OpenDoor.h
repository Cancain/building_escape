#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent {
	GENERATED_BODY()

public:
	UOpenDoor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

private:
	float CurrentYaw;
	float InitalYaw;

	void OpenDoor(const float DeltaTime);
	void CloseDoor(const float DeltaTime);

	UPROPERTY(EditAnywhere)
	float OpenAngle{90.f};

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	AActor* ActorThatOpens;

	float DoorLastOpened{0.f};

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay{.5f};

	UPROPERTY(EditAnywhere)
	float DoorClosingVelocity{1.f};

	UPROPERTY(EditAnywhere)
	float DoorOpeningVelocity{1.f};

};
