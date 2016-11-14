// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"
#include "TankAimingComponent.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetPawn();
	AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	if (ensure(AimingComponent))
	{
		FoundAimingComponent(AimingComponent);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Aiming Component not found"));
	}
	
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ensure(GetPawn())) { return; }
	
	//Out parameter
	FVector HitLocation; 
	if (GetSightRayHitLocation(HitLocation))
	{		
		AimingComponent->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	
	int32 ViewportSizeX, ViewportSizeY;
	FVector CameraWorldLocation;
	FVector WorldDirection;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrosshairX, ViewportSizeY*CrosshairY);	
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection))
		{						
			GetLookVectorHitLocation(WorldDirection, HitLocation);
			//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *WorldDirection.ToString());
		}
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& WorldDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + WorldDirection * LineTraceRange;
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
		{
			HitLocation = HitResult.Location;
			return true;
		}
	HitLocation = FVector(0);
	return false;
}

