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
	
	

}

// Called every frame
void AMowingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

		FVector LocalVector = MyVector;

		LocalVector.Z = LocalVector.Z + 100;

		MyVector.Y = MyVector.Y + 1;
		
		SetActorLocation(LocalVector);

	  	// Mowe platform forwards
				// Get current location
				//set the location
			//Send platform back if gone too far
				//Check how far we've mowed
				//Reverse direction of motion if gone too far

}

