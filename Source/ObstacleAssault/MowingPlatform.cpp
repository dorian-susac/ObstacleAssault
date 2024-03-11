// Fill out your copyright notice in the Description page of Project Settings.


#include "MowingPlatform.h"

// Sets default values
AMowingPlatform::AMowingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMowingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
		StartLocation = GetActorLocation();

		FString Name = GetName();	

		UE_LOG(LogTemp, Display, TEXT("Begin play: %s"), *Name);
		
}

// Called every frame
void AMowingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	  	// Mowe platform forwards
				// Get current location

				FVector CurrentLocation = GetActorLocation();
				//add Vector to that location
	      CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
				//set the location
				SetActorLocation(CurrentLocation);
			//Send platform back if gone too far
				//Check how far we've mowed
				float DistanceMowed = FVector::Dist(StartLocation, CurrentLocation);
				//Reverse direction of motion if gone too far

				if (DistanceMowed > MoveDistance)
				{
					float OverShoot = DistanceMowed - MoveDistance;
					FString Name = GetName();	
					UE_LOG(LogTemp, Display, TEXT("%s Platform overshot by : %f"), *Name, OverShoot);
					FVector MoveDirection = PlatformVelocity.GetSafeNormal();
					StartLocation = StartLocation + MoveDirection * MoveDistance;
					SetActorLocation(StartLocation);
					PlatformVelocity = -PlatformVelocity;
				}

			
}

