// Fill out your copyright notice in the Description page of Project Settings.


#include "SPTPlayerController.h"
#include "EnhancedInputSubsystems.h"

ASPTPlayerController::ASPTPlayerController()
{
	IMC = nullptr;
	MoveAction = nullptr;
	LookAction = nullptr;
	JumpAction = nullptr;
	SprintAction = nullptr;
}

void ASPTPlayerController::BeginPlay()
{
    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (IMC)
            {
                // Subsystem�� ���� �츮�� �Ҵ��� IMC�� Ȱ��ȭ
                // �켱����(Priority)�� 0�� ���� ���� �켱����
                Subsystem->AddMappingContext(IMC, 0);
            }
        }
    }
}
