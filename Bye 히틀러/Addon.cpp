#include "DXUT.h"
#include "Header.h"

CAddon::CAddon(D3DXVECTOR2 pos)
	: CMatrix(), attackTimer(0), attackTime(0.05f), attackCounter(0), attackCount(5), isAttacking(false)
{
	position = pos;
	center = D3DXVECTOR2(64, 64);

	scale.x = 0.4f;
	scale.y = 0.4f;

	b = 0;
	g = 0;

	SetAnimation(41, 0.01f, true);
}

void CAddon::Update(float deltaTime)
{
	CMatrix::Update(deltaTime);


	attackTimer += deltaTime;
	if (isAttacking)
	{
		if (attackTimer >= attackTime)
		{
			attackTimer = 0;
			parentScene->playerBulletList.push_back(new CBullet(position, 3, 1024, 0, 3));
			if (++attackCounter > attackCount)
				isAttacking = false;
		}
	}

}

void CAddon::Render(LPD3DXSPRITE sprite)
{
	CMatrix::Render(sprite);
	Draw(sprite, gAssetManager->playerTexture);
}

void CAddon::Attack()
{
	isAttacking = true;
	attackCounter = 0;
}