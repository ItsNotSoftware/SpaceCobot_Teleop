#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "AvatarControllerBase.generated.h"

// Forward declarations
class ASpaceCobotAvatar;
class UEnhancedInputComponent;
class UInputMappingContext;

/**
 * @brief Base class for the SpaceCobot Avatar Controller.
 * 
 * This controller manages inputs and interactions for the SpaceCobot Avatar (located in /Core/Input). 
 * It binds input actions to gameplay logic and is extended via Blueprints (e.g., BP_AvatarController).
 * 
 * References:
 * - UE5 Enhanced Input System: https://dev.epicgames.com/documentation/en-us/unreal-engine/enhanced-input-in-unreal-engine
 * - YouTube Tutorial: https://www.youtube.com/watch?v=GyxIqgith_M
 */
UCLASS(Abstract)
class SPACECOBOT_TELEOP_API AAvatarControllerBase : public APlayerController {
    GENERATED_BODY()

public:
    // Input Actions
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Movement")
    TObjectPtr<UInputAction> ActionMoveXY = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Movement")
    TObjectPtr<UInputAction> ActionMoveZ = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Movement")
    TObjectPtr<UInputAction> ActionRotateXY = nullptr;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Movement")
    TObjectPtr<UInputAction> ActionRotateZ = nullptr;

    // Input Mapping Context
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input|Mapping")
    TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;

protected:
    /**
     * @brief Called when the controller takes possession of a Pawn.
     * @param InPawn The Pawn being possessed.
     */
    virtual void OnPossess(APawn* InPawn) override;

    /**
     * @brief Called when the controller releases possession of a Pawn.
     */
    virtual void OnUnPossess() override;

private:
    // References to controlled components
    UPROPERTY()
    TObjectPtr<UEnhancedInputComponent> EnhancedInputComponent = nullptr;

    UPROPERTY()
    TObjectPtr<ASpaceCobotAvatar> SpaceCobotAvatar = nullptr;

    // Input Handlers
    void HandleMoveXY(const FInputActionValue& InputActionValue);
    void HandleMoveZ(const FInputActionValue& InputActionValue);
    void HandleRotateXY(const FInputActionValue& InputActionValue);
    void HandleRotateZ(const FInputActionValue& InputActionValue);

    // Helper Methods
    void ConfigureInputMapping();
    void BindInputActions();

    /**
     * @brief Gets the direction vector for the specified axis.
     * 
     * @param Axis The axis to retrieve the direction vector for.
     * @return FVector The direction vector.
     */
    FVector GetDirVec(const EAxis::Type Axis) const;
};