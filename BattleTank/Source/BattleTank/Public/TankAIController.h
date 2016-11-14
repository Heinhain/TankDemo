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
	
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UTankAimingComponent* AimingComponent;

	UPROPERTY(EditAnywhere)
		float AcceptanceRadius = 3000.0f;

};
