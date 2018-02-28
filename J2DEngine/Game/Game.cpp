#include "Game.h"
#include "Graphics/Colors.h"
#include "Utilities/InputManager.h"
#include "Utilities/Time.h"
#include "Utilities/DebugLog.h"

void CGame::Init()
{
	mySprite.Load("Sprites/default.dds");
	mySprite.SetPosition(400, 400);
	mySprite.SetRotation(0.5f);
	mySprite.SetScale(2.f);

	mySprite.SetShader(myShader);
}

void CGame::Update(float aDT)
{
	CInputManager& inputManager = CInputManager::GetInstance();

	mySprite.SetPosition(inputManager.GetCursorPosition());

	if (inputManager.IsKeyDown(EKeyCode::R))
	{
		mySprite.Rotate(0.4f * aDT);
	}

	mySprite.SetScale(2.f + 1.f * sin(CTime::GetInstance().GetTotalTime()));
}

void CGame::Render()
{
	mySprite.Render();
}
