// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "VehiclePawn.generated.h"

/**
 * 
 */
UCLASS()
class RACING_API AVehiclePawn : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:

	AVehiclePawn();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void SetThrottle(float value);
	void SetSteering(float value);
	void SetBrake(float value);
	void SetHandBrakePressed();
	void SetHandBrakeReleased();


protected:
	UPROPERTY(EditAnywhere)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
		class UCameraComponent* Camera;
		
	
};
