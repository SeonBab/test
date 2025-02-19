// Fill out your copyright notice in the Description page of Project Settings.


#include "SPTPlayerAnimInstance.h"
#include "SPTPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

USPTPlayerAnimInstance::USPTPlayerAnimInstance()
{
	Character = nullptr;
	CharacterMovement = nullptr;

	Velocity = FVector::ZeroVector;
	GroundSpeed = 0.f;
	GroundDierction = 0.f;
	bShouldMove = false;
	bIsFalling = false;
}

void USPTPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (Character = Cast<ACharacter>(GetOwningActor()))
	{
		CharacterMovement = Cast<UCharacterMovementComponent>(Character->GetMovementComponent());
	}
}

void USPTPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (CharacterMovement && Character)
	{
		// ���� ĳ������ �ӵ� ����
		Velocity = CharacterMovement->GetLastUpdateVelocity();
		// ���� ĳ���Ͱ� �������� �̵����� �ӵ�
		GroundSpeed = Velocity.Size2D();
		// ���� ĳ���Ͱ� �̵����� ����
		GroundDierction = CalculateDirection(Velocity, Character->GetActorRotation());
		// ���� ĳ���Ͱ� �̵� ������ ����
		bShouldMove = !FMath::IsNearlyZero(CharacterMovement->GetCurrentAcceleration().SizeSquared()) ? true : false;
		// ���� ĳ���Ͱ� ���� ������ ����
		bIsFalling = CharacterMovement->IsFalling();
	}
}
