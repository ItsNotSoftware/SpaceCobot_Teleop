#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceCobotAvatar.generated.h"

/**
 * SpaceCobot's Avatar for user to control.
 * The idea is to control a simple "ghost" avatar in real time while behind the scenes the real
 * robot will try to follow the avatar's path.
 */
UCLASS()
class SPACECOBOT_TELEOP_API ASpaceCobotAvatar : public ACharacter {
    GENERATED_BODY()

public:
    ASpaceCobotAvatar();

    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    virtual void BeginPlay() override;
};