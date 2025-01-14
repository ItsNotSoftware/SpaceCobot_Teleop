// Fill out your copyright notice in the Description page of Project Settings.


#include "ASpaceCobotAvatar.h"

// Sets default values
ASpaceCobotAvatar::ASpaceCobotAvatar() {
    PrimaryActorTick.bCanEverTick = true;
}

void ASpaceCobotAvatar::BeginPlay() {
    Super::BeginPlay();
}

void ASpaceCobotAvatar::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
}

void ASpaceCobotAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}