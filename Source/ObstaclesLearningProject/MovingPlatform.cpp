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
	
	UE_LOG(LogTemp, Display, TEXT("Configured Moved Distance: %f"), maxDistance);
	//UE_LOG(LogTemp, Warning, TEXT("DUPA"));
	//UE_LOG(LogTemp, Error, TEXT("DUPA"));
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//MovePlatform forwards
		//Get current location
	FVector currentLocation = GetActorLocation();
	
		//Add vector to that loction
	currentLocation = currentLocation + (platformVelocity * DeltaTime);
		//Set the location
	SetActorLocation(currentLocation);
	//Send back platform
		//check location
	platformDistance = FVector::Dist(startLocation, currentLocation);
		//reverse direction
	if (platformDistance >= maxDistance) {
		
		float overShoot = platformDistance - maxDistance;
		FVector moveDirection = platformVelocity.GetSafeNormal();
		startLocation = startLocation + moveDirection * maxDistance;
		SetActorLocation(startLocation);
		platformVelocity = -platformVelocity;	

		if (overShoot < 1)
		{
			UE_LOG(LogTemp, Warning, TEXT("overshooted: %f"), overShoot);
		}
	}
	
		



}

