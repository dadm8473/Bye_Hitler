#pragma once

class CGameScene;
class CPlayer : public CMatrix
{
public:
	CEnemy* target;
	CBoss* target1;
	CsBoss* target2;
	CGameScene* parentScene;

	void SetEnemyPos(CEnemy* enemy) { target = enemy; }
	void SetBossPos(CBoss* boss) { target1 = boss; }
	void SetsBossPos(CsBoss* sboss) { target2 = sboss; }


	CPlayer(D3DXVECTOR2 pos);
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);

	float attackTimer;
	float attackTime;

	int attackCounter;
	int attackCount;

	bool isDie;
	RECT rect;

	bool isInvincible;
	bool invincible;
	float invincibleTimer;
	float invincibleTime;

	bool isAddon;

	bool isAttacking;

	void Attack();
};