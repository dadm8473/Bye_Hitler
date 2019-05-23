#include "DXUT.h"
#include "Header.h"

CsBoss::CsBoss(D3DXVECTOR2 pos)
	: CMatrix(), hp(10000), isDie(false), isEnter(true),
	isPatternOn(false), patternNum(0), patternTimer(0), patternTime(2),
	attackTimer(0), attackTime(0), bulletCount(0), moveDir(1), pAngle(0),
	sum(0), maxHp(10000), speed(100), maxBullet(100), time(0.02f), timer(0), bulletSpeed(0)
{
	position = pos;

	center.x = 384;
	center.y = 256;

	SetAnimation(75, 0.03f, true);

	this->position = D3DXVECTOR2(384, -30);
}

void CsBoss::Update(float deltaTime)
{
	if (isEnter)
	{
		// 보스 등장
		position.y += 256 * deltaTime;

		if (position.y >= 100)
		{
			position.y = 100;
			isEnter = false;
		}
	}
	else
	{
		position.x += moveDir * speed * deltaTime;
		if (position.x >= 550) moveDir = -moveDir;
		if (position.x <= 250) moveDir = -moveDir;

		// 보스 등장이 끝난 후, 전투 개시
		if (!isPatternOn)
		{
			patternTimer += deltaTime;
			if (patternTimer >= patternTime)
			{
				isPatternOn = true;
				patternTimer = 0;
				bulletCount = 0;
				sum = 0;
				speed = 100;

				if (patternNum == 0)
				{
					attackTime = 0.05f;
					maxBullet = 250;
				}
				else if (patternNum == 1)
				{
					attackTime = 0.007f;
					maxBullet = 300;
				}
				else if (patternNum == 2)
				{
					attackTime = 0.01f;
					maxBullet = 400;
				}
			}
		}
		else
		{
			attackTimer += deltaTime;
			if (attackTimer >= attackTime)
			{
				attackTimer = 0;
				if (patternNum == 0)
				{
					// 패턴 1

					if (sum == 1)
					{
						parentScene->enemyBulletList.push_back(new CBullet(position, 4, 550, 150, 10));
						parentScene->enemyBulletList.push_back(new CBullet(position, 4, 550, 180, 10));
						parentScene->enemyBulletList.push_back(new CBullet(position, 4, 550, 210, 10));
						bulletCount = bulletCount + 3;

						sum = 0;

					}
					else if (sum == 0)
					{
						parentScene->enemyBulletList.push_back(new CBullet(position, 4, 550, 142.5f, 10));
						parentScene->enemyBulletList.push_back(new CBullet(position, 4, 550, 157.5f, 10));
						parentScene->enemyBulletList.push_back(new CBullet(position, 4, 550, 172.5f, 10));
						parentScene->enemyBulletList.push_back(new CBullet(position, 4, 550, 187.5f, 10));
						parentScene->enemyBulletList.push_back(new CBullet(position, 4, 550, 202.5f, 10));
						parentScene->enemyBulletList.push_back(new CBullet(position, 4, 550, 217.5f, 10));
						bulletCount = bulletCount + 5;


						sum = 1;
					}

					if (bulletCount > maxBullet)
					{
						isPatternOn = false;
						patternNum = 1;
					}
					else
						patternNum = 0;

				}
				else if (patternNum == 1)
				{
					// 패턴 2

					parentScene->enemyBulletList.push_back(new CBullet(position, 4, 500, 180 + (sum * 25), 10));

					bulletCount++;
					sum++;
					if (bulletCount > maxBullet)
					{
						isPatternOn = false;
						patternNum = 2;
					}
					else
						patternNum = 1;
				}
				else if (patternNum == 2)
				{
					for (int i = 0; i < 30; i++)
					{
						parentScene->enemyBulletList.push_back(new CBullet(position + D3DXVECTOR2(0, 200), 4, 600, 140+(sum*40), 10));
						parentScene->enemyBulletList.push_back(new CBullet(position + D3DXVECTOR2(0, 200), 4, 600, 160+(sum*40), 10));
						parentScene->enemyBulletList.push_back(new CBullet(position + D3DXVECTOR2(0, 200), 4, 600, 180+(sum*40), 10));
						parentScene->enemyBulletList.push_back(new CBullet(position + D3DXVECTOR2(0, 200), 4, 600, 200+(sum*40), 10));
						parentScene->enemyBulletList.push_back(new CBullet(position + D3DXVECTOR2(0, 200), 4, 600, 220+(sum*40), 10));
					}
					bulletCount += 5;
					sum++;

					if (bulletCount > maxBullet)
					{
						isPatternOn = false;
						patternNum = 0;
					}
					else
						patternNum = 2;
				}
			}
		}
	}

	CMatrix::Update(deltaTime);

	SetRect(&rect, position.x - 150,
		position.y = 160,
		position.x + 160,
		position.y = 250);
}

void CsBoss::Render(LPD3DXSPRITE sprite)
{
	Draw(sprite, gAssetManager->smallBossTexture);
}