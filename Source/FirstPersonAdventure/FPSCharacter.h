// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "FPSCharacter.generated.h"

UCLASS()
class FIRSTPERSONADVENTURE_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

	// Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

	// Move function
	void Move(const FInputActionValue& Value);

	// Look function
	void Look(const FInputActionValue& Value);

	// Jump
	void StartJump();
	void StopJump();

	// Crouch function
	void StartCrouch();
	void StopCrouch();

	// Sprint functions
	void StartSprint();
	void StopSprint();

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* CrouchAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* SprintAction;

	// Sprint variables
	bool bIsSprinting;
	float DefaultWalkSpeed;
	float SprintSpeed;

	// Smooth crouch variables
	bool bIsCrouching;
	float DefaultCapsuleHalfHeight;
	float CrouchedCapsuleHalfHeight;
	float CrouchTransitionSpeed;

};
