// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPickup.h"
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AMyPickup::AMyPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//sets up pickup root for scene
	PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot"));
	RootComponent = PickupRoot;

	//sets up pickup item
	PickupItem = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupItem"));
	//makes it so item is attached to root component without messing with the items scale
	PickupItem->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	//sets up pickup collider
	PickupBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PickupBox"));
	PickupBox->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	PickupBox->SetGenerateOverlapEvents(true);
	PickupBox->OnComponentBeginOverlap.AddDynamic(this, &AMyPickup::EnterPickupBox);
	PickupBox->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);


}

//function called for PickupBox trigger
void AMyPickup::EnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Destroy();
}

// Called when the game starts or when spawned
void AMyPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

