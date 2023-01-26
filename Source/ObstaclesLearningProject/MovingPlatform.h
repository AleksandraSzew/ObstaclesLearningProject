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
		int32 inputA = 0;
	UPROPERTY(EditAnywhere)
		int32 inputB = 0;
	UPROPERTY(EditAnywhere)
		int32 inputAplusB = 0;

	//Test varaibles
	UPROPERTY(EditAnywhere)
	int32 testInt = 99;
	UPROPERTY(EditAnywhere)
	bool testBool = true;
	UPROPERTY(EditAnywhere)
	float testFloat = 5.5; 
};
