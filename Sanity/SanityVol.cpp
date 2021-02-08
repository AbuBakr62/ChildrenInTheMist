// Fill out your copyright notice in the Description page of Project Settings.


#include "SanityVol.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "CharacterController.h"


// Sets default values
ASanityVol::ASanityVol()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("BaseBoxComponent"));
	CapsuleComponent->InitCapsuleSize(75, 75);
	CapsuleComponent->SetCollisionProfileName("Trigger");
	RootComponent = CapsuleComponent;

	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ASanityVol::OnOverlapBegin);
	CapsuleComponent->OnComponentEndOverlap.AddDynamic(this, &ASanityVol::OnOverlapEnd);


	SanityMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SanityMesh"));
	SanityMesh->SetSimulatePhysics(false);

	SanityMesh->AttachTo(RootComponent);

}

void ASanityVol::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor == nullptr) || (OtherActor == this) || OtherComp == nullptr)
	{
		return;
	}

	auto myChar = Cast<ACharacterController>(OtherActor);

	myChar->SanityVolumes.AddUnique(this);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
	}

}

void ASanityVol::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	auto myChar = Cast<ACharacterController>(OtherActor);

	myChar->SanityVolumes.Remove(this);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end"));
	}
}
