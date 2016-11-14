// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Tank.h"
#include "TankMovementComponent.h"
#include "Projectile.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}


void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool isReloaded = ((FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds);
	if (isReloaded)	
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}

