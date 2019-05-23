#include "DXUT.h"
#include "Header.h"

CEnemy::CEnemy(D3DXVECTOR2 pos, int type)
	:CMatrix(), type(type), isDestroyed(false), parentScene(NULL), hp(0), isDie(false),
	attackTime(0.3f), attackTimer(0), exitTime(5), exitTimer(0), exit(false), speed(0), count(0),
	beHit(false), hitRedTime(0.05f), hitRedTimer(0)
{
	position = pos;

	if (type == 0)
	{
		hp = 20;

		center.x = 64;
		center.y = 64;

		attackTime = 1;

		SetAnimation(39, 0.01f, true);
	}
	else if (type == 1)
	{
		hp = 20;

		center.x = 64;
		center.y = 64;

		attackTime = 0.5f;

		rotation -= 45;

		SetAnimation(39, 0.01f, true);
	}
	else if (type == 2)
	{
		hp = 20;

		center.x = 64;
		center.y = 64;

		attackTime = 0.5f;

		rotation += 45;

		SetAnimation(39, 0.01f, true);
	}
	else if (type == 3)
	{
		hp = 150;

		center.x = 64;
		center.y = 64;

		SetAnimation(41, 0.01f, true);
	}
}

void CEnemy::Update(float deltaTime)
{
	if (type == 0)
	{
		position.y += 384 * deltaTime;

		attackTimer += deltaTime;

		if (attackTimer >= attackTime)
		{
			float angle = 180;

			if (parentScene->player)
			{
				angle = GetAngle(
					parentScene->player->position.x - position.x,
					parentScene->player->position.y - position.y);
			}
			parentScene->enemyBulletList.push_back(new CBullet(position, 4, 500, angle, 10));

			attackTimer = 0;
		}

		SetRect(&rect, position.x - 40, position.y - 40, position.x + 40, position.y + 40);
	}
	else if (type == 1)
	{
		attackTimer += deltaTime;

		position.y += 350 * deltaTime;
		position.x += 200 * deltaTime;
		if (attackTimer >= attackTime)
		{
			float angle = 180;
			if (parentScene->player)
			{
				angle = GetAngle(
					parentScene->player->position.x - position.x,
					parentScene->player->position.y - position.y);
			}
			parentScene->enemyBulletList.push_back(new CBullet(position, 4, 500, angle, 10));

			attackTimer = 0;
		}

		SetRect(&rect, position.x - 40, position.y - 40, position.x + 40, position.y + 40);

	}
	else if (type == 2)
	{
		attackTimer += deltaTime;

		position.y += 350 * deltaTime;
		position.x -= 200 * deltaTime;
		if (attackTimer >= attackTime)
		{
			float angle = 180;
			if (parentScene->player)
			{
				angle = GetAngle(
					parentScene->player->position.x - position.x,
					parentScene->player->position.y - position.y);
			}
			parentScene->enemyBulletList.push_back(new CBullet(position, 4, 500, angle, 10));

			attackTimer = 0;
		}

		SetRect(&rect, position.x - 40, position.y - 40, position.x + 40, position.y + 40);
	}
	else if (type == 3)
	{
		attackTimer += deltaTime;
		
		if (attackTimer >= attackTime)
		{
			if (count == 3)
			{
				for (int i = 0; i < 7; i++)
				{
					parentScene->enemyBulletList.push_back(new CBullet(position, 4, 500, 120+(i*20), 10));
				}

				count = 0;
			}

			count++;
			attackTimer = 0;
		}

		if (!exit)
		{
			exitTimer += deltaTime;
			if (exitTimer >= exitTime)
			{
				exit = true;
			}

			speed += 256 * deltaTime;

			if (position.y >= 100)
				speed = 0;
		}
		else
		{
			speed -= 256 * deltaTime;
		}
		position.y += speed*deltaTime;

		SetRect(&rect, position.x - 40, position.y - 40, position.x + 40, position.y + 40);
	}

	if (position.x < -256 || position.x > 800 || position.y < -256 || position.y > 1080)
		isDie = true;

	CMatrix::Update(deltaTime);

	if (beHit)
	{
		g = 0;
		b = 0;

		hitRedTimer += deltaTime;

		if (hitRedTimer >= hitRedTime)
		{
			beHit = false;
			hitRedTimer = 0;
		}
	}
	else
	{
		g = 255;
		b = 255;
	}
}

void CEnemy::Render(LPD3DXSPRITE sprite)
{
	if (type == 0)
		Draw(sprite, gAssetManager->enemy1Texture);
	if (type == 1)
		Draw(sprite, gAssetManager->enemy2Texture);
	if (type == 2)
		Draw(sprite, gAssetManager->enemy3Texture);
	if (type == 3)
		Draw(sprite, gAssetManager->enemy4Texture);
}