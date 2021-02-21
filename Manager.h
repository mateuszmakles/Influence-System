// Copyright Mateusz Makles, 2021 All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Manager.generated.h"

class UIsland;

UCLASS()
class INFLUENCE_API AManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AManager();

private:

	//TArray<TWeakObjectPtr<UIsland>> Islands;
	TArray<TWeakObjectPtr<UIsland>> Islands;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
