#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceCobotAvatar.generated.h"

// Forward declarations
class USpringArmComponent;
class UCameraComponent;

/**
 * SpaceCobot's Avatar for user to control.
 * The idea is to control a simple "ghost" avatar in real time while behind the scenes the real
 * robot will try to follow the avatar's path.
 */
UCLASS()
class SPACECOBOT_TELEOP_API ASpaceCobotAvatar : public ACharacter {
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    class UCameraComponent* CameraComp;

    ASpaceCobotAvatar();

    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    class USpringArmComponent* SpringArmComp;

    virtual void BeginPlay() override;
};