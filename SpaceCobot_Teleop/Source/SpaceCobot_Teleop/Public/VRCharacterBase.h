#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacterBase.generated.h"

class UCineCameraComponent;

UCLASS()
class SPACECOBOT_TELEOP_API AVRCharacterBase : public ACharacter {
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* VROffset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCineCameraComponent* VRCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float MaxSpeed = 3.0f;

	AVRCharacterBase();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void CharacterMoveForward(const float Ratio);
};
