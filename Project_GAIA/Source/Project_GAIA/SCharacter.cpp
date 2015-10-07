/**
 * Yoseph Solomon
 * June 2, 2015
 * Project_GAIA - Character Code
 */

// Fill out your copyright notice in the Description page of Project Settings.

#include "Project_GAIA.h"
#include "SCharacter.h"


// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	/* Movement */
	InputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);

	/* Looking up/down/sideways is already supported in APawn.h, so we reference the existing functions */
	InputComponent->BindAxis("Turn", this, &ASCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &ASCharacter::AddControllerPitchInput);

	/* Overloaded function only for BindAction not Axis*/
	//InputComponent->BindAction("Jump", IE_Pressed, this, &ASCharacter::OnStartJump);
	//InputComponent->BindAction("Jump", IE_Released, this, &ASCharacter::OnStopJump);
}

// Move Forward
void ASCharacter::MoveForward(float Val)
{
	if (Controller && Val != 0.f)
	{
		// Limit pitch when walking or falling
		const bool bLimitRotation = (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling());
		const FRotator Rotation = bLimitRotation ? GetActorRotation() : Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);

		AddMovementInput(Direction, Val);
	}
}

// Move Right
void ASCharacter::MoveRight(float Val)
{
	if (Val != 0.f)
	{
		const FRotator Rotation = GetActorRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Val);
	}
}
