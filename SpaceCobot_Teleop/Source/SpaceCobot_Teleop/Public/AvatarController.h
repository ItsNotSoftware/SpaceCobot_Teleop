#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "AvatarController.generated.h"

// Forward declarations
class ASpaceCobotAvatar;
class UEnhancedInputComponent;
class UInputMappingContext;

/**
 * @brief Controller for the SpaceCobot's Avatar.
 * This class manages the input and interactions for the SpaceCobot's avatar (defined in the editor in Content/Input).
 * It builds on the PlayerController base class, adding enhanced input support for actions.
 * 
 * References:
 * - UE5 Documentation: https://dev.epicgames.com/documentation/en-us/unreal-engine/enhanced-input-in-unreal-engine
 * - YouTube Tutorial: https://www.youtube.com/watch?v=GyxIqgith_M
 */
UCLASS(Abstract)
class SPACECOBOT_TELEOP_API AAvatarController : public APlayerController {
    GENERATED_BODY()

public:
    // Bind to move action blueprint
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Movement")
    UInputAction* ActionMove = nullptr;

    // Bind to look action blueprint
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Movement")
    UInputAction* ActionLook = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Movement")
    TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;
protected:
    /**
     * Called when the controller possesses a Pawn.
     * @param InPawn The pawn being possessed.
     */
    virtual void OnPossess(APawn* InPawn) override;

    /**
     * Called when the controller un-possesses a Pawn.
     */
    virtual void OnUnPossess() override;

    /**
     * Handle the look action.
     * TODO: Change this function from avatar to camera. 
     * @param InputActionValue The input action value.
     */
    void HandleLook(const FInputActionValue& InputActionValue);

    /**
     * Handle the move action.
     * @param InputActionValue The input action value.
     */
    void HandleMove(const FInputActionValue& InputActionValue);

private:
    UPROPERTY()
    UEnhancedInputComponent* EnhancedInputComponent = nullptr; // Ref to EnhancedInputComponent to bind actions 
    
    UPROPERTY()
    ASpaceCobotAvatar* SpaceCobotAvatar = nullptr; // Ref to SpacedCobotAvatar pawn to control it
};