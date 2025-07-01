// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AFPACharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AAFPACharacter::AAFPACharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 0.0f; // for FPS, otherwise adjust for TPS

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void AAFPACharacter::BeginPlay()
{
	Super::BeginPlay();

    GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
	
    if (APlayerController* PC = Cast<APlayerController>(GetController()))
    {
        if (auto Sub = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
        {
            Sub->AddMappingContext(DefaultMappingContext, 0);
        }
    }
}

// Called to bind functionality to input
void AAFPACharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (auto EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAFPACharacter::Move);
        EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAFPACharacter::Look);
        //Sprint
        EIC->BindAction(SprintAction, ETriggerEvent::Triggered, this, &AAFPACharacter::Sprint);
        EIC->BindAction(SprintAction, ETriggerEvent::Completed, this, &AAFPACharacter::Sprint);
        // Interact
        EIC->BindAction(InteractAction, ETriggerEvent::Started, this, &AAFPACharacter::Interact);
    }
}
void AAFPACharacter::Move(const FInputActionValue& Value)
{
    FVector2D Input = Value.Get<FVector2D>();
    AddMovementInput(GetActorForwardVector(), Input.Y);
    AddMovementInput(GetActorRightVector(), Input.X);
}

void AAFPACharacter::Look(const FInputActionValue& Value)
{
    FVector2D Input = Value.Get<FVector2D>();
    AddControllerYawInput(Input.X);
    AddControllerPitchInput(Input.Y);
}

void AAFPACharacter::Sprint(const FInputActionValue& Value)
{
    bool bIsSprinting = Value.Get<bool>();
    GetCharacterMovement()->MaxWalkSpeed = bIsSprinting ? SprintSpeed : NormalSpeed;
}

void AAFPACharacter::Interact(const struct FInputActionValue& Value)
{
    FVector Start = Camera->GetComponentLocation();
    FVector End = Start + (Camera->GetForwardVector() * 300.0f);

    FHitResult HitResult;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params);

    if (bHit && HitResult.GetActor())
    {
        UE_LOG(LogTemp, Log, TEXT("Interacted with: %s"), *HitResult.GetActor()->GetName());
    }

    DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 2.0f, 0, 1.0f);
}

// Called every frame
void AAFPACharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


