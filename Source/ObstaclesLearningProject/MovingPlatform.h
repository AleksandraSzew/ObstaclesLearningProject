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
	
	UPROPERTY(EditAnywhere)
		FVector TestVector = FVector(1,2,3); 
	UPROPERTY(EditAnywhere)
		float X = 0;
	UPROPERTY(EditAnywhere)
		float Y = 10;
	UPROPERTY(EditAnywhere)
		float Z = 0;

};
