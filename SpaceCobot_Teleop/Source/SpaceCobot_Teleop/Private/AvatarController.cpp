#include "AvatarController.h"
#include "SpaceCobotAvatar.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AAvatarController::OnPossess(APawn* InPawn) {
    Super::OnPossess(InPawn);

    // Store a reference to the avatar we are controlling
    SpaceCobotAvatar = Cast<ASpaceCobotAvatar>(InPawn);
    checkf(
        SpaceCobotAvatar, TEXT("AAvatarController::OnPossess: InPawn is not a ASpaceCobotAvatar."));

    // Get the InputComponent component from parent class and cast it to EnhancedInputController
    EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
    checkf(
        EnhancedInputComponent,
        TEXT("AAvatarController::OnPossess: InputComponent is not a UEnhancedInputComponent."));

    // Get the local player subsystem
    auto InputSubsystem =
        ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    checkf(InputSubsystem, TEXT("AAvatarController::OnPossess: InputSubsystem is nullptr."));

    // Clear all prior mappings and add the InputMappingContext
    checkf(InputMappingContext, TEXT("AAvatarController::OnPossess: InputMappingContext is nullptr."));
    InputSubsystem->ClearAllMappings();
    InputSubsystem->AddMappingContext(InputMappingContext, 0);
    
    // Bind the move action functions if set in the editor
    if (ActionMove) {
        EnhancedInputComponent->BindAction(
            ActionMove, ETriggerEvent::Triggered, this, &AAvatarController::HandleMove);
    }

    // Bind the look action functions if set in the editor
    if (ActionLook) {
        EnhancedInputComponent->BindAction(
            ActionLook, ETriggerEvent::Triggered, this, &AAvatarController::HandleLook);
    }
}

void AAvatarController::OnUnPossess() {
    EnhancedInputComponent->ClearActionBindings(); 
    Super::OnUnPossess();
}

void AAvatarController::HandleLook(const FInputActionValue& InputActionValue) {
    const FVector2D LookVector = InputActionValue.Get<FVector2D>();

    // Add yaw and pitch input to controller. 
    AddYawInput(LookVector.X);
    AddPitchInput(LookVector.Y);
}


void AAvatarController::HandleMove(const FInputActionValue& InputActionValue) {
    // Get input value.
    const FVector2d MovementVector = InputActionValue.Get<FVector2d>();

    // Add movement to SpaceCobotAvatar pawn in world frame.
    SpaceCobotAvatar->AddMovementInput(
        FVector(1.0f, 0.0f, 0.0f), MovementVector.Y);
    SpaceCobotAvatar->AddMovementInput(
        FVector(0.0f, 1.0f, 0.0f), MovementVector.X);
}