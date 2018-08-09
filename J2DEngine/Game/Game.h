#pragma once
#include "Graphics/Sprite.h"
#include "Player.h"
#include "PipeSpawner.h"

class CGame
{
public:
	CGame() = default;
	~CGame() = default;

	void Init();
	void Update(float aDT);
	void Render();

private:

	enum class EGameState
	{
		Menu,
		InGame,
		Paused,
		GameOver
	} myGameState;

	CSprite myBackgroundSprite;
	CSprite myBackgroundSprite2;
	float myBackgroundSpeed;

	CPlayer myPlayer;
	CPipeSpawner myPipeSpawner;

	void HandleTilingBackgrounds(float aDT);
};

