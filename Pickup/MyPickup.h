// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPickup.generated.h"

UCLASS()
class LOST2_API AMyPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPickup();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//static mesh component for picking up the Item
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PickupItem;

	//scene component for root
	UPROPERTY(EditAnywhere)
		USceneComponent* PickupRoot;

	//shape component for invisible trigger, allowing player to pickup item
	UPROPERTY(EditAnywhere)
		UShapeComponent* PickupBox;

	//function for player entering the pickup collider
	UFUNCTION()
		void EnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
