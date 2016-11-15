// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly)
		float AcceptanceRadius = 8000.0f;

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UTankAimingComponent* AimingComponent;
};
