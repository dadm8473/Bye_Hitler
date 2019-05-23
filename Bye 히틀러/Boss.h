#pragma once

class CBoss : public CMatrix
{
public:
	CGameScene *parentScene;

	int hp;
	int maxHp;
	bool isDie;
	int speed;
	RECT rect;

	bool isEnter;

	bool isPatternOn;

	int patternNum;

	float patternTimer;
	float patternTime;

	float attackTimer;
	float attackTime;

	int moveDir;
	int pAngle;

	int re;
	
	int sum;
	int maxBullet;

	int bulletCount;

	CBoss(D3DXVECTOR2 pos);
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);
};