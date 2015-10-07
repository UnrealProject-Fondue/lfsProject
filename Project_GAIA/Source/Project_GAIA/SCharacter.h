// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

UCLASS()
class PROJECT_GAIA_API ASCharacter : public ACharacter
{
	GENERATED_BODY()
		//Constructor
		ASCharacter();

		//Constructor Overloaded
		//ASCharacter(const FObjectInitializer& ObjectInitializer);
	
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

		// Called every frame
		virtual void Tick(float DeltaSeconds) override;


public:
	/****************************************************/  
	/* Variables										*/
	/****************************************************/ 

	/****************************************************/
	/* Movement & Jumping								*/
	/****************************************************/ 

	virtual void MoveForward(float Val);

	virtual void MoveRight(float Val);

};
