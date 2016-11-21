// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include


class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

private:
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookVectorHitLocation(FVector& WorldDirection, FVector& HitLocation) const;

	UFUNCTION()
		void OnPossesedTankDeath();

	virtual void SetPawn(APawn* InPawn) override;

	UTankAimingComponent* AimingComponent;

	UPROPERTY(EditAnywhere)
		float CrosshairX = 0.5;
	UPROPERTY(EditAnywhere)
		float CrosshairY = 0.33333;
	UPROPERTY(EditAnywhere, Category = "Firing")
		float LineTraceRange = 100000.f;


};
