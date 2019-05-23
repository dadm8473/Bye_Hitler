#include "DXUT.h"
#include "Header.h"

CPlayer::CPlayer(D3DXVECTOR2 pos)
	:CMatrix(), attackTimer(0), attackTime(0.1f), attackCounter(0), attackCount(5),
	isAttacking(false), isDie(false), target(NULL), isAddon(false), isInvincible(true), 
	invincibleTimer(0), invincibleTime(2), invincible(false), target1(NULL),target2(NULL)
{
	position = pos;
	center = D3DXVECTOR2(64, 64);

	SetAnimation(40, 0.01f, true);
}

void CPlayer::Update(float deltaTime)
{
	CMatrix::Update(deltaTime);

	SetRect(&rect, position.x - 10, position.y - 10, position.x + 10, position.y + 10);
	// �÷��̾� ����
	attackTimer += deltaTime;
	if (isAttacking)
	{
		if (attackTimer >= attackTime)
		{
			attackTimer = 0;

			//�Ѿ� ��
			if (attackType == 0)
			{
				// Ÿ�� 0 - �� ���� �Ѿ� �߻�
				parentScene->playerBulletList.push_back(new CBullet(position - D3DXVECTOR2(30, 0) + D3DXVECTOR2(0, 30), 0, 1024, 0, 10));
				parentScene->playerBulletList.push_back(new CBullet(position + D3DXVECTOR2(30, 0) + D3DXVECTOR2(0, 30), 0, 1024, 0, 10));
			}
			else if (attackType == 1)
			{
				// Ÿ�� 1 - �� ���� �Ѿ� �߻�
				parentScene->playerBulletList.push_back(new CBullet(position - D3DXVECTOR2(40, 0) + D3DXVECTOR2(0, 30), 0, 1024, 0, 8));
				parentScene->playerBulletList.push_back(new CBullet(position + D3DXVECTOR2(40, 0) + D3DXVECTOR2(0, 30), 0, 1024, 0, 8));
				parentScene->playerBulletList.push_back(new CBullet(position, 1, 1024, 0, 10));
			}
			else if (attackType == 2)
			{
				// Ÿ�� 2 - �ټ� ���� �Ѿ� �߻� ���� �� �ΰ��� ����
				parentScene->playerBulletList.push_back(new CBullet(position - D3DXVECTOR2(30, 0) + D3DXVECTOR2(0, 30), 0, 1024, 0, 8));
				parentScene->playerBulletList.push_back(new CBullet(position + D3DXVECTOR2(30, 0) + D3DXVECTOR2(0, 30), 0, 1024, 0, 8));
				parentScene->playerBulletList.push_back(new CBullet(position, 1, 1024, 0, 10));
				// ����ź
				if (!isDie)
				{
					if (target)
					{
						parentScene->playerBulletList.push_back(new CBullet(position - D3DXVECTOR2(30, 0) + D3DXVECTOR2(0, 30), 2, 1500,
							GetAngle(target->position.x - position.x, target->position.y - position.y), 5));
						parentScene->playerBulletList.push_back(new CBullet(position + D3DXVECTOR2(30, 0) + D3DXVECTOR2(0, 30), 2, 1500,
							GetAngle(target->position.x - position.x, target->position.y - position.y), 5));
					}
					else if (target1)
					{
						parentScene->playerBulletList.push_back(new CBullet(position - D3DXVECTOR2(30, 0) + D3DXVECTOR2(0, 30), 2, 1500,
							GetAngle(target1->position.x - position.x, target1->position.y - position.y), 5));
						parentScene->playerBulletList.push_back(new CBullet(position + D3DXVECTOR2(30, 0) + D3DXVECTOR2(0, 30), 2, 1500,
							GetAngle(target1->position.x - position.x, target1->position.y - position.y), 5));
					}
					else if (target2)
					{
						parentScene->playerBulletList.push_back(new CBullet(position - D3DXVECTOR2(30, 0) + D3DXVECTOR2(0, 30), 2, 1500,
							GetAngle(target2->position.x - position.x, target2->position.y - position.y), 5));
						parentScene->playerBulletList.push_back(new CBullet(position + D3DXVECTOR2(30, 0) + D3DXVECTOR2(0, 30), 2, 1500,
							GetAngle(target2->position.x - position.x, target2->position.y - position.y), 5));
					}
					else
					{
						parentScene->playerBulletList.push_back(new CBullet(position - D3DXVECTOR2(30, 0) + D3DXVECTOR2(0, 30), 2, 1500,
							350, 5));
						parentScene->playerBulletList.push_back(new CBullet(position + D3DXVECTOR2(30, 0) + D3DXVECTOR2(0, 30), 2, 1500,
							10, 5));
					}
				}
			}

			if (++attackCounter > attackCount)
			{
				isAttacking = false;
			}
		}
	}
	// �÷��̾� ����
	if (isInvincible || invincible)
	{
		a = 150;

		invincibleTimer += deltaTime;

		if (invincibleTimer >= invincibleTime && !invincible)
		{
			invincibleTimer = 0;
			SetRect(&rect, position.x - 10, position.y - 10, position.x + 10, position.y + 10);
			isInvincible = false;
		}
	}
	else
	{
		a = 255;
	}
}

void CPlayer::Render(LPD3DXSPRITE sprite)
{
	CMatrix::Render(sprite);
	Draw(sprite, gAssetManager->playerTexture);
}

void CPlayer::Attack()
{
	isAttacking = true;
	attackCounter = 0;
}