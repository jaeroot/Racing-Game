// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiclePawn.h"

#include "ChaosWheeledVehicleMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AVehiclePawn::AVehiclePawn() {
	UChaosWheeledVehicleMovementComponent* Vehicle = CastChecked<UChaosWheeledVehicleMovementComponent>(GetVehicleMovement());
	
	Vehicle->EngineSetup.MaxRPM = 10000.0f;
	

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 400.0f;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Vehicle Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
}

void AVehiclePawn::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);


}

void AVehiclePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Throttle", this, &AVehiclePawn::SetThrottle);
	PlayerInputComponent->BindAxis("Steering", this, &AVehiclePawn::SetSteering);
	PlayerInputComponent->BindAxis("Brake", this, &AVehiclePawn::SetBrake);

	PlayerInputComponent->BindAction("Handbrake", IE_Pressed, this, &AVehiclePawn::SetHandBrakePressed);
	PlayerInputComponent->BindAction("Handbrake", IE_Released, this, &AVehiclePawn::SetHandBrakeReleased);
}

void AVehiclePawn::SetThrottle(float value) {
	GetVehicleMovementComponent()->SetThrottleInput(value);
}

void AVehiclePawn::SetSteering(float value) {
	GetVehicleMovementComponent()->SetSteeringInput(value);
}

void AVehiclePawn::SetBrake(float value) {
	GetVehicleMovementComponent()->SetBrakeInput(value);
}

void AVehiclePawn::SetHandBrakePressed() {
	GetVehicleMovementComponent()->SetHandbrakeInput(true);
}

void AVehiclePawn::SetHandBrakeReleased() {
	GetVehicleMovementComponent()->SetHandbrakeInput(false);
}
