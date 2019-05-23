#include "DXUT.h"
#include "Header.h"

LPD3DXSPRITE gSprite = NULL;
CScene*gScene = NULL;

bool isStartLoading;
bool isFadingOut;
float fadeIntimer = 0;
float fadeIntime = 1.5f;
CMatrix* gLoadingScreen;
string loadingSceenName;

extern int score = 0;
extern int playerLife = 5;
extern int attackType = 0;
extern bool addonSave = false;

void ChangeScene(string sceneName)
{
	loadingSceenName = sceneName;

	isStartLoading = true;
	isFadingOut = true;
}

void Init()
{
	D3DXCreateSprite(DXUTGetD3D9Device(), &gSprite);

	gLoadingScreen = new CMatrix();
	gLoadingScreen->a = 0;

	gAssetManager = new CAssetManager();
	gAssetManager->InitAssets();

	gScene = new CTitleScene();

	isStartLoading = false;
	isFadingOut = false;
	fadeIntimer = 0;
	fadeIntime = 1.5f;
}

void Term()
{
	gAssetManager->TermAssets();

	if (gSprite)
		gSprite->Release();

	if (gLoadingScreen)
		delete gLoadingScreen;

	if (gScene)
		delete gScene;
}

void Reset()
{
	if (gSprite)
		gSprite->OnResetDevice();
}

void Lost()
{
	if (gSprite)
		gSprite->OnLostDevice();
}

void Update(float deltaTime)
{
	if (gScene)
		gScene->Update(deltaTime);

	if (isStartLoading)
	{
		if (isFadingOut)
		{
			gLoadingScreen->a += (int)(255 * deltaTime);
			if (gLoadingScreen->a >= 255)
			{
				gLoadingScreen->a = 255;

				fadeIntimer += deltaTime;
				if (fadeIntimer > fadeIntime)
				{
					fadeIntimer = 0;
					isFadingOut = false;

					// 화면 전환 동작

					if (gScene)
					{
						delete gScene;
						gScene = NULL;
					}

					if (loadingSceenName == "Title")
					{
						gScene = new CTitleScene();
					}
					else if (loadingSceenName == "Stage1")
					{
						gScene = new CGameScene(0);
					}
					else if (loadingSceenName == "Stage2")
					{
						gScene = new CGameScene(1);
					}
					else if (loadingSceenName == "Ending_Victory")
					{
						gScene = new CEndingScene(true);
					}
					else if (loadingSceenName == "Ending_GameOver")
					{
						gScene = new CEndingScene(false);
					}

					// 예) scene = new CGameScene();
				}
			}
		}
		else
		{
			gLoadingScreen->a -= (int)(255 * deltaTime);
			if (gLoadingScreen->a <= 0)
			{
				gLoadingScreen->a = 0;
				isStartLoading = false;
			}
		}
	}

	gLoadingScreen->Update(deltaTime);
}

void Render()
{
	gSprite->Begin(D3DXSPRITE_ALPHABLEND);

	if (gScene)
		gScene->Render(gSprite);

	gLoadingScreen->Draw(gSprite, gAssetManager->loadingTexture);

	gSprite->End();
}

void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (gScene)
		gScene->MsgProc(uMsg, wParam, lParam);
}

float GetAngle(float x, float y)
{
	return D3DXToDegree(atan2(y, x)) + 90;
}