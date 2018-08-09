#include "Game.h"
#include "Graphics/Colors.h"
#include "Utilities/InputManager.h"
#include "Utilities/Time.h"
#include "Utilities/DebugLog.h"

#include "../Engine/OpaqueBuffer.h"

#include "LayerSpeeds.h"

void CGame::Init()
{
	myGameState = EGameState::Menu;

	myBackgroundSprite.Load("Sprites/background.dds");
	myBackgroundSprite.SetPosition(800, 450);
	myBackgroundSprite2.Load("Sprites/background.dds");
	myBackgroundSprite2.SetPosition(1600 + 800, 450);

	myBackgroundSpeed = LAYER_BACKGROUND;

	myPlayer.Init();
	myPipeSpawner.Init();
}

void CGame::Update(float aDT)
{
	CInputManager& inputManager = CInputManager::GetInstance();

	if (inputManager.IsKeyPressed(EKeyCode::Enter))
	{
		myGameState = EGameState::InGame;
	}

	switch (myGameState)
	{
	case CGame::EGameState::Menu:
		break;
	case CGame::EGameState::InGame:
		HandleTilingBackgrounds(aDT);
		myPlayer.Update(aDT);
		myPipeSpawner.Update(aDT);
		break;
	case CGame::EGameState::Paused:
		break;
	case CGame::EGameState::GameOver:
		break;
	default:
		break;
	}
}

void CGame::Render()
{
	myBackgroundSprite.Render();
	myBackgroundSprite2.Render();

	switch (myGameState)
	{
	case CGame::EGameState::Menu:
		break;
	case CGame::EGameState::InGame:
		myPlayer.Render();
		myPipeSpawner.Render();
		break;
	case CGame::EGameState::Paused:
		myPlayer.Render();
		myPipeSpawner.Render();
		break;
	case CGame::EGameState::GameOver:
		myPipeSpawner.Render();
		break;
	default:
		break;
	}
}

void CGame::HandleTilingBackgrounds(float aDT)
{
	myBackgroundSprite.Move(myBackgroundSpeed * aDT, 0);
	myBackgroundSprite2.Move(myBackgroundSpeed * aDT, 0);

	if (myBackgroundSprite.GetPosition().x <= -myBackgroundSprite.GetDimensions().x / 2.f + 4.f)
	{
		myBackgroundSprite.SetPosition(1600 + 800, 450);
	}
	else if (myBackgroundSprite2.GetPosition().x <= -myBackgroundSprite2.GetDimensions().x / 2.f + 4.f) 
	{
		myBackgroundSprite2.SetPosition(1600 + 800, 450);
	}
}
