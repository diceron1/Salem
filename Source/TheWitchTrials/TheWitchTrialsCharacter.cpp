// Copyright Epic Games, Inc. All Rights Reserved.

#include "TheWitchTrialsCharacter.h"
#include "TheWitchTrialsProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"


//////////////////////////////////////////////////////////////////////////
// ATheWitchTrialsCharacter

ATheWitchTrialsCharacter::ATheWitchTrialsCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	//Set up jump count for double Jump
	JumpMaxCount = 2;

	// set our turn rates for input
	TurnRateGamepad = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

}

void ATheWitchTrialsCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

}

//////////////////////////////////////////////////////////////////////////// Input

void ATheWitchTrialsCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Bind fire events
	PlayerInputComponent->BindAction("PrimaryAction", IE_Pressed, this, &ATheWitchTrialsCharacter::OnPrimaryAction);
	PlayerInputComponent->BindAction("SecondaryAction", IE_Pressed, this, &ATheWitchTrialsCharacter::OnSecondaryAction);

	// Bind movement events
	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &ATheWitchTrialsCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &ATheWitchTrialsCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Sprint", this, &ATheWitchTrialsCharacter::Sprint);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "Mouse" versions handle devices that provide an absolute delta, such as a mouse.
	// "Gamepad" versions are for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn Right / Left Gamepad", this, &ATheWitchTrialsCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("Look Up / Down Gamepad", this, &ATheWitchTrialsCharacter::LookUpAtRate);
}

void ATheWitchTrialsCharacter::OnPrimaryAction()
{
	//Trigger the OnItemUsed Event
	//Get Forward Vector
	//Spawn Jay's Fire VFX
	//Line Trace camera forward vector, get item hit
	//Apply damage if it is an enemy
}

void ATheWitchTrialsCharacter::OnSecondaryAction()
{
	//Pull Up rock defense VFX
	//Get player forward vector
	//Calculate how far ahead of the player the wall should be
	//Use Collision from Jay's vfx to deflect enemy projectiles and disrupt thier path. 
}

void ATheWitchTrialsCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ATheWitchTrialsCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ATheWitchTrialsCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

void ATheWitchTrialsCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

void ATheWitchTrialsCharacter::Sprint(float Rate)
{
	if(Rate >= 1.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("SPRINT"));
		GetCharacterMovement()->MaxWalkSpeed = 1200.f;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = 600.f;
	}
	
}


