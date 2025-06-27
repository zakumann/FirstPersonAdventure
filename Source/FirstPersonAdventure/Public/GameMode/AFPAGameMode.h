// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AFPAGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSONADVENTURE_API AAFPAGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void StartPlay() override;
};
