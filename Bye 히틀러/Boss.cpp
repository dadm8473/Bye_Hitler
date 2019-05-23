#include "DXUT.h"
#include "Header.h"

CBoss::CBoss(D3DXVECTOR2 pos)
	: CMatrix(), hp(12000), isDie(false), isEnter(true),
	isPatternOn(false), patternNum(0), patternTimer(0), patternTime(2),
	attackTimer(0), attackTime(0), bulletCount(0), moveDir(1), pAngle(0),
	sum(0), maxHp(12000), speed(100), maxBullet(100), re(1)
{
	position = pos;

	center.x = 384;
	center.y = 256;

	SetAnimation(40, 0.03f, true);

	this->position = D3DXVECTOR2(384, -30);
}

void CBoss::Update(float deltaTime)
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
					attackTime = 0.4f;
					maxBullet = 400;
				}
				else if (patternNum == 1)
				{
					attackTime = 0.007f;
					maxBullet = 200;
				}
				else if (patternNum == 2)
				{
					attackTime = 0.02f;
					maxBullet = 200;
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

					speed = 0;

					if (sum == 0)
					{
						for (int i = 0; i < 30; i++)
						{
							parentScene->enemyBulletList.push_back(new CBullet(position, 4, 550, 180 + (i * 3), 10));
							bulletCount++;
						}

						sum = 1;
					}
					else if (sum == 1)
					{
						for (int i = 0; i < 30; i++)
						{
							parentScene->enemyBulletList.push_back(new CBullet(position, 4, 550, 180 - (i * 3), 10));
							bulletCount++;
						}
						sum = 0;
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

					for (int j = 0; j < 50; j++)
					{
						for (int i = 0; i < 5; i++)
						{
							parentScene->enemyBulletList.push_back(new CBullet(position, 4, 550, (144 + (i * 144))+(sum*60), 10));
						}
					}
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
					parentScene->enemyBulletList.push_back(
						new CBullet(position + D3DXVECTOR2(-170, 100), 4, 280, 180 + (sum * 33), 10));

					parentScene->enemyBulletList.push_back(
						new CBullet(position + D3DXVECTOR2(170, 100), 4, 280, 180 - (sum * 25), 10));

					sum++;

					bulletCount++;

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

	SetRect(&rect,	position.x - 150, 
					position.y = 160,
					position.x + 170, 
					position.y = 250);
}

void CBoss::Render(LPD3DXSPRITE sprite)
{
	Draw(sprite, gAssetManager->bossTexture);
}