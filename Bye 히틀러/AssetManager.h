#pragma once

class CAssetManager
{
public:
	map<string, CSound*> sounds;

	CSoundManager* soundManager;
	void LoadAsset_Sound(string key, LPWSTR filename, int maxBuffer);

	CSound* GetSoundAsset(string key)
	{
		map<string, CSound*>::iterator it = sounds.find(key);
		if (it != sounds.end())
			return it->second;
		else
			return NULL;
	}

	CTexture*playerTexture;
	CTexture*playerDieTexture;

	CTexture*player1BulletTexture;
	CTexture*player2BulletTexture;
	CTexture*player3BulletTexture;

	CTexture*addonBulletTexture;
	CTexture*enemyBulletTexture;

	CTexture*clearAttackTexture;
	CTexture*clearAttackeffectTexture;
	CTexture*clearAttackcountTexture;

	CTexture*enemy1Texture;
	CTexture*enemy2Texture;
	CTexture*enemy3Texture;
	CTexture*enemy4Texture;

	CTexture*enemy1DieTexture;
	CTexture*enemy2DieTexture;
	CTexture*enemy3DieTexture;

	CTexture*item1Texture;
	CTexture*item2Texture;

	CTexture*explodeTexture;

	CTexture*bossTexture;
	CTexture*smallBossTexture;

	CTexture*bossHp;
	CTexture*bossHpBG;

	CTexture*titleBGTexture;
	CTexture*titleBG1Texture;
	CTexture*titleBG2Texture;
	CTexture*titleTexture;
	CTexture*howtoTexture;
	CTexture*rankingTexture;

	CTexture* land1Texture;
	CTexture* land2Texture;
	CTexture* cloud1Texture;
	CTexture* cloud2Texture;

	CTexture*victoryTexture;
	CTexture*gameoverTexture;
	CTexture*gameoverBGTexture;

	CTexture* loadingTexture;

	CTexture*numberTexture;

	void InitAssets();
	void TermAssets();
};

extern CAssetManager*gAssetManager;