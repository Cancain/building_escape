#include "Grabber.h"

UGrabber::UGrabber() {
	PrimaryComponentTick.bCanEverTick = true;

}

void UGrabber::BeginPlay() {
	Super::BeginPlay();

}

void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
