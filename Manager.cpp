// Copyright Mateusz Makles, 2021 All Rights Reserved.


#include "Manager.h"
#include "Island.h"

// Sets default values
AManager::AManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	for (int i = 0; i < 3; ++i)
	{
		Islands.Add(CreateDefaultSubobject<UIsland>(FName("Island", i+1)));
	}
}

// Called when the game starts or when spawned
void AManager::BeginPlay()
{
	Super::BeginPlay();
	
	// Testing
	Islands[0]->AddFaction(Faction::Traders);
	Islands[0]->AddFaction(Faction::Army, 10.f);
	Islands[0]->AddFaction(Faction::Pirates, 40.f);
	Islands[0]->RemoveFaction(Faction::Pirates);

	GEngine->AddOnScreenDebugMessage(-1, 600.0f, FColor::Orange, FString::Printf(TEXT("Army %f"), Islands[0]->GetFactionByName(Faction::Army)->Influence));
	GEngine->AddOnScreenDebugMessage(-1, 600.0f, FColor::Yellow, FString::Printf(TEXT("Traders %f"), Islands[0]->GetFactionByName(Faction::Traders)->Influence));
	//GEngine->AddOnScreenDebugMessage(-1, 600.0f, FColor::Cyan, FString::Printf(TEXT("Gov %f"), Islands[0]->GetFactionByName(Faction::Government)->Influence));
	//GEngine->AddOnScreenDebugMessage(-1, 600.0f, FColor::Emerald, FString::Printf(TEXT("Pirates %f"), Islands[0]->GetFactionByName(Faction::Pirates)->Influence));

}

// Called every frame
void AManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

