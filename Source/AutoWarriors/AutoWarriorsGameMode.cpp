// Copyright Epic Games, Inc. All Rights Reserved.

#include "AutoWarriorsGameMode.h"
#include "AutoWarriorsPlayerController.h"
#include "AutoWarriorsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAutoWarriorsGameMode::AAutoWarriorsGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AAutoWarriorsPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}