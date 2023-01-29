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
		//reverse direction
		



}

