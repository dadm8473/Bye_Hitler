#pragma once

class CGameScene;
class CEnemy : public CMatrix
{
public:
	CGameScene*parentScene;

	int type;
	//타입0 : 직선으로 날아가며 유도 탄알을 발사하는 적
	//타입1 : 대각선으로 날아가며 유도 탄알을 발사하는 적
	//타입2 : 타입1 과 반대로 날아가며 유도 탄알을 발사하는 적
	//타입3 : 탄알을 난사하는 적

	bool isDestroyed;
	
	float attackTimer;
	float attackTime;

	float exitTimer;
	float exitTime;
	bool exit;
	float speed;

	int count;

	RECT rect;

	int hp;
	bool isDie;

	bool beHit;				// 맞앗는가
	float hitRedTime;		// 얘가 붉어지는 시간
	float hitRedTimer;

	CEnemy(D3DXVECTOR2 pos, int type);
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprtie);
};