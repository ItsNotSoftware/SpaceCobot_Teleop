// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ASpaceCobotAvatar.generated.h"

UCLASS()
class SPACECOBOT_TELEOP_API ASpaceCobotAvatar : public ACharacter {
    GENERATED_BODY()

public:
    ASpaceCobotAvatar();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};