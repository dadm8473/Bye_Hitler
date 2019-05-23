#pragma once

class CsBoss : public CMatrix
{
public:
	CGameScene *parentScene;

	int hp;
	int maxHp;
	bool isDie;
	RECT rect;

	bool isEnter;

	bool isPatternOn;

	int patternNum;

	float patternTimer;
	float patternTime;

	float attackTimer;
	float attackTime; 
	
	float timer;
	float time;

	int moveDir;
	int pAngle;

	int sum;

	int maxBullet;

	int speed;
	int bulletSpeed;

	int bulletCount;

	CsBoss(D3DXVECTOR2 pos);
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);
};