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
		//debug if over shoot is more than 5 
		float overShoot = platformDistance - maxDistance;
		if (overShoot > 5) {
			FString NameString = GetName();
			UE_LOG(LogTemp, Warning, TEXT("overshooted: %f of %s"), overShoot, *NameString);
		}
		FVector moveDirection = platformVelocity.GetSafeNormal();
		startLocation = startLocation + moveDirection * maxDistance;
		SetActorLocation(startLocation);
		platformVelocity = -platformVelocity;	

	}
	
		



}

