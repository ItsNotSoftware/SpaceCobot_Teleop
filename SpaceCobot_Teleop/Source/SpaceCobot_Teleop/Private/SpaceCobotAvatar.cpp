#include "SpaceCobotAvatar.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
ASpaceCobotAvatar::ASpaceCobotAvatar() {
    PrimaryActorTick.bCanEverTick = true;

    // Init Spring Arm Component with default vals (can be overridden in editor bp) 
    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
    SpringArmComp->SetupAttachment(RootComponent);
    SpringArmComp->TargetArmLength = 300.0f;
    SpringArmComp->bUsePawnControlRotation = false; // Arm rotates with controller

    // Initialize the Camera component and attach it to the SpringArm
    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
    CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
    CameraComp->bUsePawnControlRotation = false; // Camera does not rotate with arm
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