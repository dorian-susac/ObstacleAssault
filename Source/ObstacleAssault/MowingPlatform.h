// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MowingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMowingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMowingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

			UPROPERTY(EditAnywhere, Category="Mowing Platform")
			FVector PlatformVelocity = FVector (0,1000,0);

			UPROPERTY(EditAnywhere, Category="Mowing Platform")
			float MoveDistance = 1000;
			PROPERTY(EditAnywhere, Category="Rotation")
			FRotator RotationVelocity;

			FVector StartLocation;

			void MovePlatform(float DeltaTime);
			
			void RotatePlatform(float DeltaTime);
};

  bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;


