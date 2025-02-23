#include "AvatarControllerBase.h"
#include "SpaceCobotAvatar.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"

void AAvatarControllerBase::OnPossess(APawn* InPawn) {
    Super::OnPossess(InPawn);

    // Validate and store a reference to the possessed pawn as SpaceCobotAvatar
    SpaceCobotAvatar = Cast<ASpaceCobotAvatar>(InPawn);
    checkf(SpaceCobotAvatar, TEXT("InPawn is not a valid ASpaceCobotAvatar."));

    // Get and validate the Enhanced Input Component
    EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
    checkf(EnhancedInputComponent, TEXT("InputComponent is not a valid UEnhancedInputComponent."));

    ConfigureInputMapping();
    BindInputActions();
}

void AAvatarControllerBase::OnUnPossess() {
    if (EnhancedInputComponent) {
        EnhancedInputComponent->ClearActionBindings();
    }
    Super::OnUnPossess();
}

void AAvatarControllerBase::HandleMoveXY(const FInputActionValue& InputActionValue) {
    GEngine->AddOnScreenDebugMessage(
        -1, 1.f, FColor::Green, FString::Printf(TEXT("MoveXY: %s"), *InputActionValue.ToString()));

    const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
    SpaceCobotAvatar->AddMovementInput(GetDirVec(EAxis::X), MovementVector.Y);
    SpaceCobotAvatar->AddMovementInput(GetDirVec(EAxis::Y), MovementVector.X);
}

void AAvatarControllerBase::HandleMoveZ(const FInputActionValue& InputActionValue) {
    GEngine->AddOnScreenDebugMessage(
        -1, 1.f, FColor::Green, FString::Printf(TEXT("MoveZ: %s"), *InputActionValue.ToString()));

    const float MovementValue = InputActionValue.Get<float>();
    SpaceCobotAvatar->AddMovementInput(GetDirVec(EAxis::Z), MovementValue);
}

void AAvatarControllerBase::HandleRotateXY(const FInputActionValue& InputActionValue) {
    // Get current actor rotation
    FRotator ActorRotation = SpaceCobotAvatar->GetActorRotation();

    // Extract x (pitch increment) and y (roll increment) from the input value
    const auto InputValue = InputActionValue.Get<FVector2D>();
    const float DeltaPitch = InputValue.Y;
    const float DeltaRoll = InputValue.X;

    // Update the dominant rotation component (pitch or roll) to simplify the control
    (FMath::Abs(DeltaRoll) > FMath::Abs(DeltaPitch) ? ActorRotation.Roll : ActorRotation.Pitch) += 
        (FMath::Abs(DeltaRoll) > FMath::Abs(DeltaPitch) ? DeltaRoll : DeltaPitch);

    // Set the new rotation for the actor
    SpaceCobotAvatar->SetActorRotation(ActorRotation);
}


void AAvatarControllerBase::HandleRotateZ(const FInputActionValue& InputActionValue) {
    const float RotationValue = InputActionValue.Get<float>();
    SpaceCobotAvatar->AddControllerYawInput(RotationValue);
}


void AAvatarControllerBase::ConfigureInputMapping() {
    auto InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    checkf(InputSubsystem, TEXT("InputSubsystem is nullptr."));
    checkf(InputMappingContext, TEXT("InputMappingContext is nullptr."));

    InputSubsystem->ClearAllMappings();
    InputSubsystem->AddMappingContext(InputMappingContext, 0);
}

void AAvatarControllerBase::BindInputActions() {
    EnhancedInputComponent->BindAction(
        ActionMoveXY, ETriggerEvent::Triggered, this, &AAvatarControllerBase::HandleMoveXY);
    EnhancedInputComponent->BindAction(
        ActionMoveZ, ETriggerEvent::Triggered, this, &AAvatarControllerBase::HandleMoveZ);
    EnhancedInputComponent->BindAction(
        ActionRotateXY, ETriggerEvent::Triggered, this, &AAvatarControllerBase::HandleRotateXY);
    EnhancedInputComponent->BindAction(
        ActionRotateZ, ETriggerEvent::Triggered, this, &AAvatarControllerBase::HandleRotateZ);
}

FVector AAvatarControllerBase::GetDirVec(const EAxis::Type Axis) const {
    // Get the camera's rotation and only keep the yaw component 
    const FRotator CameraRotation = SpaceCobotAvatar->CameraComp->GetComponentRotation();
    const FRotator CompensatedRotation(0.0f, CameraRotation.Yaw, 0.0f);

    // Apply the compensating rotation to the vector on specified axis
    switch (Axis) {
        case EAxis::X:
            return CompensatedRotation.RotateVector(FVector(1, 0, 0));
        case EAxis::Y:
            return CompensatedRotation.RotateVector(FVector(0, 1, 0));
        case EAxis::Z:
            return CompensatedRotation.RotateVector(FVector(0, 0, 1));
        default:
            return FVector::ZeroVector;
    }
}