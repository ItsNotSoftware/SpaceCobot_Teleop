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
    // Log to screen the value of the input action
    GEngine->AddOnScreenDebugMessage(
        -1, 1.f, FColor::Green, FString::Printf(TEXT("MoveXY: %s"), *InputActionValue.ToString()));

    const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
    SpaceCobotAvatar->AddMovementInput(GetDirVec(EAxis::X), MovementVector.Y);
    SpaceCobotAvatar->AddMovementInput(GetDirVec(EAxis::Y), MovementVector.X);
}

void AAvatarControllerBase::HandleMoveZ(const FInputActionValue& InputActionValue) {
    const float MovementValue = InputActionValue.Get<float>();
    SpaceCobotAvatar->AddMovementInput(GetDirVec(EAxis::Z), MovementValue);
}

void AAvatarControllerBase::HandleRotateXY(const FInputActionValue& InputActionValue) {
    const FVector2D RotationVector = InputActionValue.Get<FVector2D>();
    const FRotator CameraYawRotation(0.0f, SpaceCobotAvatar->CameraComp->GetComponentRotation().Yaw, 0.0f);
    const FRotationMatrix YawMatrix(CameraYawRotation);

    const FVector ForwardDirection = YawMatrix.GetUnitAxis(EAxis::X);
    const FVector RightDirection = YawMatrix.GetUnitAxis(EAxis::Y);

    SpaceCobotAvatar->AddControllerRollInput(RotationVector.X);
    SpaceCobotAvatar->AddControllerPitchInput(RotationVector.Y);
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
    switch (Axis) {
        case EAxis::X:
            return SpaceCobotAvatar->GetActorForwardVector();
        case EAxis::Y:
            return SpaceCobotAvatar->GetActorRightVector();
        case EAxis::Z:
            return SpaceCobotAvatar->GetActorUpVector();
        default:
            return FVector::ZeroVector;
    }
}