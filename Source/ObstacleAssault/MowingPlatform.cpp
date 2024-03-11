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

			MovePlatform(DeltaTime);

			RotatePlatform(DeltaTime);
}

void AMowingPlatform::MovePlatform(float DeltaTime)
{
				if (ShouldPlatformReturn())
				{
					FVector MoveDirection = PlatformVelocity.GetSafeNormal();
					StartLocation = StartLocation + MoveDirection * MoveDistance;
					SetActorLocation(StartLocation);
					PlatformVelocity = -PlatformVelocity;

				}
				else
				{
					FVector CurrentLocation = GetActorLocation();
					CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
					SetActorLocation(CurrentLocation);

				}
}

void AMowingPlatform::RotatePlatform(float DT)
{
		UE_LOG(LogTemp, Display, TEXT("%s Rotating..."), *GetName());
}

bool AMowingPlatform::ShouldPlatformReturn()
{
	return GetDistanceMoved() > MoveDistance;
}

float AMowingPlatform::GetDistanceMoved()
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
