// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AFPAPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSONADVENTURE_API AAFPAPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;
};
