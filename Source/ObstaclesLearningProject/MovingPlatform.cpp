// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	startLocation = GetActorLocation();
	

	FString MyString = GetName();
	UE_LOG(LogTemp, Display, TEXT("Begin play: %s"), *MyString);
	//UE_LOG(LogTemp, Warning, TEXT("DUPA"));
	//UE_LOG(LogTemp, Error, TEXT("DUPA"));
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

	MovePlatfrom(DeltaTime);
	RotatePlatform(DeltaTime);

}

void AMovingPlatform::MovePlatfrom(float DeltaTime)
{	
	if (shouldPlatformReturn()) {
		
		FVector moveDirection = platformVelocity.GetSafeNormal();
		startLocation = startLocation + moveDirection * maxDistance;
		SetActorLocation(startLocation);
		platformVelocity = -platformVelocity;
	}
	else {
		FVector currentLocation = GetActorLocation();

		//Add vector to that loction
		currentLocation = currentLocation + (platformVelocity * DeltaTime);
		SetActorLocation(currentLocation);
	}

}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{

	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::shouldPlatformReturn() const
{
	return GetDistanceMoved() >= maxDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(startLocation, GetActorLocation());
}


	
	

