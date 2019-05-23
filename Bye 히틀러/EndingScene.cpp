#include "DXUT.h"
#include "Header.h"

CEndingScene::CEndingScene(bool isVictory)
	:CScene(), isVictory(isVictory), ending(), wave()
{
	wave.SetAnimation(40, 0.03f, true);
	wave.scale.x = 2;
	wave.scale.y = 2;
	wave.position.y = -180;
}

CEndingScene::~CEndingScene()
{

}

void CEndingScene::Update(float deltaTime)
{
	CScene::Update(deltaTime);
	wave.Update(deltaTime);
	ending.Update(deltaTime);
}

void CEndingScene::Render(LPD3DXSPRITE sprite)
{
	CScene::Render(sprite);
	if (isVictory)
	{
		ending.Draw(sprite, gAssetManager->victoryTexture);
		gAssetManager->GetSoundAsset("BGM_Win")->Play();
	}
	else
	{
		ending.Draw(sprite, gAssetManager->gameoverTexture);
		wave.Draw(sprite, gAssetManager->gameoverBGTexture);
		gAssetManager->GetSoundAsset("BGM_Lose")->Play();
	}
}

void CEndingScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	CScene::MsgProc(uMsg, wParam, lParam);

	switch (uMsg)
	{
	case WM_KEYDOWN:
		if (wParam == VK_RETURN)
		{
			attackType = 0;
			addonSave = false;
			ChangeScene("Title");
		}

		break;
	}
}