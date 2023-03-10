// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLESLEARNINGPROJECT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY(EditAnywhere, Category = "Moving platform")
	FVector platformVelocity = FVector(100,0,0);
	UPROPERTY(VisibleAnywhere, Category = "Moving platform")
	float platformDistance = -1;
	UPROPERTY(EditAnywhere, Category = "Moving platform")
	float maxDistance = 100;

	UPROPERTY(EditAnywhere, Category = "Rotating platform")
		FRotator RotationVelocity;


	FVector startLocation;
	void MovePlatfrom(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	bool shouldPlatformReturn() const;
	float GetDistanceMoved() const;
};
