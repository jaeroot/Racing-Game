// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_Main.generated.h"

/**
 * 
 */
UCLASS()
class RACING_API APC_Main : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
};
