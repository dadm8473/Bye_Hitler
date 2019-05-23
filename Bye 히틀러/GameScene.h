#pragma once

class EnemyEntryInfo
{
public:
	int type;
	float time;
	D3DXVECTOR2 position;

	bool summoned;

	EnemyEntryInfo(D3DXVECTOR2 position, float time, int type)
		:position(position), time(time), type(type), summoned(false)
	{

	}
};

class CGameScene : public CScene
{
public:
	float timer;

	vector<EnemyEntryInfo> enemyEntryInfo;

	list<CBullet*>playerBulletList;
	list<CBullet*>enemyBulletList;

	list<CEnemy*>enemyList;
	list<CItem*>itemList;

	int itemCount;

	list<CEffect*> effectList;

	CPlayer*player;
	int playerLife;
	CMatrix*playerDie;

	CAddon*addon[3];
	bool isAddon;

	CMap*map;


	float rebirthTimer;
	float rebirthTime;

	CBoss*boss;
	CsBoss*sboss;

	CMatrix bossHpValue;
	CMatrix bossHpBG;
	RECT bossHpRect;

	int stage;
	bool stageChange;
	float stageChangeTimer;
	float stageChangeTime;

	bool victory;
	float victoryTimer;
	float victoryTime;

	int type;

	CMatrix scoreNumUI[6];

	CMatrix playerLifeUI[5];

	CMatrix clearAttackUI[10];

	CMatrix*clearAttack;
	float clearAttackEffectTimer;
	float clearAttackEffectTime;
	float isCA;
	bool useCA;
	int clearAttackCount;
	

	CGameScene(int stage);
	virtual ~CGameScene();
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void ClearAttack();
};