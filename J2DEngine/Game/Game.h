#pragma once
#include "Graphics/Sprite.h"
#include "Engine/Shader.h"

class CGame
{
public:
	CGame() = default;
	~CGame() = default;

	void Init();
	void Update(float aDT);
	void Render();

private:

	CSprite mySprite;
	CShader myShader;
};

