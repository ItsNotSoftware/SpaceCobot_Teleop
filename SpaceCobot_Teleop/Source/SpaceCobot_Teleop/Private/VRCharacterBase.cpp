#include "VRCharacterBase.h"
#include "CineCameraComponent.h"
#include "Components/CapsuleComponent.h"

AVRCharacterBase::AVRCharacterBase() {
	PrimaryActorTick.bCanEverTick = true;

	VROffset = CreateDefaultSubobject<USceneComponent>(TEXT("VROffset"));
	VROffset->SetupAttachment(GetCapsuleComponent());

	VRCamera = CreateDefaultSubobject<UCineCameraComponent>(TEXT("VRCamera"));
	VRCamera->SetupAttachment(VROffset);
	VRCamera->SetRelativeLocation(FVector(0, 0, GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
}

void AVRCharacterBase::BeginPlay() { Super::BeginPlay(); }

void AVRCharacterBase::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void AVRCharacterBase::SetupPlayerInputComponent(
	UInputComponent* PlayerInputComponent) { Super::SetupPlayerInputComponent(PlayerInputComponent); }

void AVRCharacterBase::CharacterMoveForward(const float Ratio) {
	const auto CameraProjectedForward = FVector(VRCamera->GetForwardVector().X, VRCamera->GetForwardVector().Y, 0).
		GetSafeNormal();
	AddActorWorldOffset(CameraProjectedForward * Ratio * MaxSpeed);
}

void AVRCharacterBase::FindFocusDistance() {
	const FVector Start = VRCamera->GetComponentLocation();
	const FVector End = Start + VRCamera->GetForwardVector() * MaxFocusTrackingDistance;
	FHitResult HitResult;
	FCameraFocusSettings FocusSettings;
	FocusSettings.ManualFocusDistance = MaxFocusTrackingDistance;

	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility)) {
		FocusSettings.ManualFocusDistance = HitResult.Distance;
		VRCamera->SetFocusSettings(FocusSettings);
	}
}
