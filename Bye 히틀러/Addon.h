#pragma once

class CGameScene;
class CAddon : public CMatrix
{
public:
	CGameScene* parentScene;

	CAddon(D3DXVECTOR2 pos);
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);

	float attackTimer;
	float attackTime;

	int attackCounter;
	int attackCount;

	bool isAttacking;

	void Attack();
};