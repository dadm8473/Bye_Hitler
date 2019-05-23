#include "DXUT.h"
#include "Header.h"

CTitleScene::CTitleScene()
	:CScene(), backGround(), wave1(), wave2(), scene(), howtoplay(), activeHowtoplay(false), activeranking(false)
{
	wave1.SetAnimation(40, 0.03f, true);
	wave2.SetAnimation(40, 0.03f, true);
	scene.a = 200;

	gAssetManager->GetSoundAsset("BGM_Title")->Play();
	gAssetManager->GetSoundAsset("BGM_Lose")->Stop();
	gAssetManager->GetSoundAsset("BGM_Win")->Stop();
	gAssetManager->GetSoundAsset("BGM_Stage1")->Stop();
	gAssetManager->GetSoundAsset("BGM_Stage2")->Stop();
	gAssetManager->GetSoundAsset("BGM_Boss")->Stop();
}

CTitleScene::~CTitleScene()
{

}

void CTitleScene::Update(float deltaTime)
{
	CScene::Update(deltaTime);

	backGround.Update(deltaTime);
	wave1.Update(deltaTime);
	wave2.Update(deltaTime);
	scene.Update(deltaTime);
	howtoplay.Update(deltaTime);
	ranking.Update(deltaTime);
}

void CTitleScene::Render(LPD3DXSPRITE sprite)
{
	CScene::Render(sprite);

	backGround.Draw(sprite, gAssetManager->titleBG1Texture);
	wave1.Draw(sprite, gAssetManager->titleBG1Texture);
	wave2.Draw(sprite, gAssetManager->titleBG2Texture);
	scene.Draw(sprite, gAssetManager->titleTexture);

	if (activeHowtoplay)
		howtoplay.Draw(sprite, gAssetManager->howtoTexture);
	if (activeranking)
		ranking.Draw(sprite, gAssetManager->rankingTexture);
}

void CTitleScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	CScene::MsgProc(uMsg, wParam, lParam);

	switch (uMsg)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_UP:
			if (!activeHowtoplay)
			{
				scene.currentScene--;
				if (scene.currentScene < 0)
					scene.currentScene = 0;
			}
			break;
		case VK_DOWN:
			if (!activeHowtoplay)
			{
				scene.currentScene++;
				if (scene.currentScene > 3)
					scene.currentScene = 3;
			}
			break;
		case VK_RETURN:
			if (scene.currentScene == 0)				// 메인화면 -> 게임화면으로 이동
			{
				gAssetManager->GetSoundAsset("BGM_Title")->Stop();
				ChangeScene("Stage1");
			}
			else if (scene.currentScene == 1)			// 메인화면 -> 게임조작법 보기
			{
				activeHowtoplay = !activeHowtoplay;
			}
			else if (scene.currentScene == 2)			// 메인화면 -> 랭킹
			{
				activeranking = !activeranking;
			}
			else if (scene.currentScene == 3)			// 메인화면 -> 게임종료
			{
				gAssetManager->GetSoundAsset("BGM_Title")->Stop();
				PostQuitMessage(0);
			}
			break;
		}
		break;
	}
}