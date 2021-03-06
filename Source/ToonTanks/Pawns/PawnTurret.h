// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/EngineTypes.h"
#include "CoreMinimal.h"
#include "Pawns/PawnBase.h"
#include "PawnTurret.generated.h"

class APawnTank;

UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()
	
private:

	void CheckFireCondition();
	FTimerHandle FireRateTimerHandel;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Combat", meta = (AllowPrivateAccess = "true"))
	float FireRate = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRange = 500.0f;
	
	APawnTank* PlayerPawn;

	float ReturnDistanceToPlayer();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void HandleDestruction() override;
};