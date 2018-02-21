#include "Scene.h"
#include "Graphics/Sprite.h"
#include "Math/CommonMath.h"

CScene::CScene()
{
}


CScene::~CScene()
{
}

bool CScene::Init()
{
	CSprite::SetScene(this);

	// Make Limits.h or something with limits
	SetSpriteBufferSize(5000);

	return true;
}

void CScene::SetSpriteBufferSize(unsigned int aSize)
{
	mySpriteBuffer.resize(aSize);
	mySpriteBuffer.clear();

	for (int i = 0; i < aSize; ++i)
	{
		mySpriteBuffer.push_back(nullptr);
	}
	myAvailableIndex = 0;
}

bool CScene::AddSprite(CSprite * aSprite)
{
	if (myAvailableIndex < mySpriteBuffer.size())
	{
		mySpriteBuffer[myAvailableIndex++] = aSprite;
	}

	return true;
}

std::vector<CSprite*>& CScene::GetSpriteBuffer()
{
	return mySpriteBuffer;
}

void CScene::Clear()
{
	for (CSprite* sprite : mySpriteBuffer)
	{
		sprite = nullptr;
	}
	myAvailableIndex = 0;
}
