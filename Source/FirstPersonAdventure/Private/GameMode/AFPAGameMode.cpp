// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/AFPAGameMode.h"
#include "Engine/Engine.h"

void AAFPAGameMode::StartPlay()
{
    Super::StartPlay();

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("MystGameMode started!"));
    }
}
