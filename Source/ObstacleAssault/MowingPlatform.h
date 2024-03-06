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

	UPROPERTY(EditAnywhere)
	int32 MyInt = 99;

  UPROPERTY(EditAnywhere)
	float MyFloat=0.6;
	
	UPROPERTY(EditAnywhere)
	bool MyBool=true;
};
