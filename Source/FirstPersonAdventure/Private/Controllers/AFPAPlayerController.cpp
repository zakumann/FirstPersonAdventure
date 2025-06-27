// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/AFPAPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AAFPAPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (auto PC = Cast<APlayerController>(this))
    {
        if (auto Sub = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            // Optionally add mapping here if not in Pawn
        }
    }
}
