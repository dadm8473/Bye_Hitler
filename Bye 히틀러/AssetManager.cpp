#include "DXUT.h"
#include "Header.h"

CAssetManager*gAssetManager;

void CAssetManager::InitAssets()
{
	playerTexture = new CTexture(L"images/Player/Player00", L"png", 40);
	playerDieTexture = new CTexture(L"images/PlayerisDie/die00", L"png", 40);

	player1BulletTexture = new CTexture(L"images/Bullet/PlayerBullet/playerBullet01", L"png", 1);
	player2BulletTexture = new CTexture(L"images/Bullet/PlayerBullet/playerBullet02", L"png", 1);
	player3BulletTexture = new CTexture(L"images/Bullet/PlayerBullet/playerBullet03", L"png", 1);
	addonBulletTexture = new CTexture(L"images/Bullet/PlayerBullet/playerBullet04", L"png", 1);
	enemyBulletTexture = new CTexture(L"images/Bullet/EnemyBullet/적총알00", L"png", 41);

	clearAttackTexture = new CTexture(L"images/ClearAttack/boom00", L"png", 31);
	clearAttackeffectTexture = new CTexture(L"images/ClearAttackEffect/boom effect00", L"png", 40);
	clearAttackcountTexture = new CTexture(L"images/Bullet/boomicon00", L"png", 1);

	enemy1Texture = new CTexture(L"images/Enemy/2/enemy00", L"png", 41);
	enemy2Texture = new CTexture(L"images/Enemy/1/enemy00", L"png", 39);
	enemy3Texture = new CTexture(L"images/Enemy/1/enemy00", L"png", 39);
	enemy4Texture = new CTexture(L"images/Enemy/3/enemy00", L"png", 41);

	enemy1DieTexture = new CTexture(L"images/Enemy/2Die/enemydie00", L"png", 40);
	enemy2DieTexture = new CTexture(L"images/Enemy/1Die/enemydie00", L"png", 40);
	enemy3DieTexture = new CTexture(L"images/Enemy/3Die/enemydie00", L"png", 40);

	item1Texture = new CTexture(L"images/item/PowerUpItem00", L"png", 1);
	item2Texture = new CTexture(L"images/item/BoomUPItem00", L"png", 1);

	explodeTexture = new CTexture(L"images/Effect/effect00", L"png", 40);

	bossTexture = new CTexture(L"images/Boss2/boss00", L"png", 40);
	smallBossTexture = new CTexture(L"images/Boss1/boss00", L"png", 75);
	
	bossHp = new CTexture(L"Images/BossHp/bosshp00", L"png", 1);
	bossHpBG = new CTexture(L"Images/BossHp/bosshpBG00", L"png", 1);

	titleBG1Texture = new CTexture(L"images/Main/waveTexture1/flag00", L"png", 40);
	titleBG2Texture = new CTexture(L"images/Main/waveTexture2/flag00",L"png",40);
	titleTexture = new CTexture(L"images/Main/main00", L"png", 4);
	howtoTexture = new CTexture(L"images/Main/howto00", L"png", 1);
	rankingTexture = new CTexture(L"images/Main/ranking00", L"png", 1);

	land1Texture = new CTexture(L"images/map/map00", L"png", 1);
	land2Texture = new CTexture(L"images/map/city00", L"png", 1);
	cloud1Texture = new CTexture(L"images/map/cloud00", L"png", 1);
	cloud2Texture = new CTexture(L"images/map/cloud01", L"png", 1);
	
	victoryTexture = new CTexture(L"images/Main/victory00", L"png", 1);
	gameoverTexture = new CTexture(L"images/Main/gameover00", L"png", 1);
	gameoverBGTexture = new CTexture(L"images/Main/loseFlag/flag00", L"png", 40);
	
	loadingTexture = new CTexture(L"Images/Main/loading00", L"png", 1);

	numberTexture = new CTexture(L"Images/Num/Num", L"png", 10);

	soundManager = new CSoundManager();
	soundManager->Initialize(DXUTGetHWND(), DSSCL_PRIORITY);
	soundManager->SetPrimaryBufferFormat(2, 22050, 16);

	LoadAsset_Sound("isDie", L"Sound/Example.wav", 10);
	LoadAsset_Sound("BGM_Win", L"Sound/승리.wav", 1);
	LoadAsset_Sound("BGM_Lose", L"Sound/패배.wav", 1);
	LoadAsset_Sound("BGM_Stage1", L"Sound/스테이지1.wav", 1);
	LoadAsset_Sound("BGM_Stage2", L"Sound/스테이지2.wav", 1);
	LoadAsset_Sound("BGM_Boss", L"Sound/보스.wav", 1);
	LoadAsset_Sound("BGM_Title", L"Sound/타이틀.wav", 1);
}

void CAssetManager::TermAssets()
{
	delete playerTexture;
	delete playerDieTexture;

	delete player1BulletTexture;
	delete player2BulletTexture;
	delete player3BulletTexture;
	delete addonBulletTexture;
	delete enemyBulletTexture;

	delete clearAttackTexture;
	delete clearAttackeffectTexture;
	delete clearAttackcountTexture;

	delete enemy1Texture;
	delete enemy2Texture;
	delete enemy3Texture;
	delete enemy4Texture;

	delete enemy1DieTexture;
	delete	enemy2DieTexture;
	delete	enemy3DieTexture;

	delete item1Texture;
	delete item2Texture;

	delete explodeTexture;

	delete bossTexture;
	delete smallBossTexture;

	delete bossHp;
	delete bossHpBG;

	delete titleTexture;
	delete titleBGTexture;
	delete titleBG1Texture;
	delete titleBG2Texture;
	delete howtoTexture;
	delete rankingTexture;

	delete land1Texture;
	delete land2Texture;
	delete cloud1Texture;
	delete cloud2Texture;

	delete victoryTexture;
	delete gameoverTexture;
	delete gameoverBGTexture;
	
	delete loadingTexture;

	delete numberTexture;

	for (map<string, CSound*>::iterator it = sounds.begin(); it != sounds.end(); ++it)
	{
		if (it->second)
			delete it->second;
	}

	delete soundManager;
}

void CAssetManager::LoadAsset_Sound(string key, LPWSTR filename, int maxBuffer)
{
	soundManager->Create(&sounds[key], filename, 0, GUID_NULL, maxBuffer);
}