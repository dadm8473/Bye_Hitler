#include "DXUT.h"
#include "Header.h"

CBullet::CBullet(D3DXVECTOR2 pos, int type, float speed, float moveAngle, int damage)
	:CMatrix(), type(type), speed(speed), moveAngle(moveAngle), damage(damage), isDestroyed(false)
{
	position = pos;

	// 플레이어 총알 - 1
	if (type == 0)
	{
		center.x = 2;
		center.y = 16;

		scale.x = 1;
		scale.y = 2;
	}
	// 플레이어 총알 - 2
	else if (type == 1)
	{
		center.x = 2;
		center.y = 16;

		scale.x = 1;
		scale.y = 2;
	}
	// 플레이어 총알 - 3
	else if (type == 2)
	{
		center.x = 2;
		center.y = 16;

		scale.x = 1;
		scale.y = 2;
	}
	// 애드온 총알
	else if (type == 3)
	{
		center.x = 2;
		center.y = 16;

		scale.x = 1;
		scale.y = 2;
	}
	// 적 총알
	else if (type == 4)
	{
		center.x = 32;
		center.y = 32;

		scale.x = 0.5;
		scale.y = 0.5;

		SetAnimation(41, 0.03f, true);
	}
}

void CBullet::Update(float deltaTime)
{
	position.x += sin(moveAngle*(D3DX_PI / 180))*speed*deltaTime;
	position.y -= cos(moveAngle*(D3DX_PI / 180))*speed*deltaTime;

	rotation = moveAngle;

	// 플레이어 총알 - 1 충돌 범위
	if (type == 0)
	{
		SetRect(&rect, position.x - 5, position.y - 32, position.x + 5, position.y + 25);
	}
	// 플레이어 총알 - 2 충돌 범위
	else if (type == 1)
	{
		SetRect(&rect, position.x - 5, position.y - 32, position.x + 5, position.y + 25);
	}
	// 플레이어 총알 - 3 충돌 범위
	else if (type == 2)
	{
		SetRect(&rect, position.x - 5, position.y - 32, position.x + 5, position.y + 25);
	}
	// 애드온 총알 충돌 범위
	else if (type == 3)
	{
		SetRect(&rect, position.x - 5, position.y - 32, position.x + 5, position.y + 25);
	}
	// 적 총알 충돌 범위
	else if (type == 4)
	{
		SetRect(&rect, position.x - 15, position.y - 15, position.x + 15, position.y + 15);
	}

	if (position.x < -128 || position.x > 800 || position.y < -128 || position.y > 1100)
		isDestroyed = true;

	CMatrix::Update(deltaTime);
}

void CBullet::Render(LPD3DXSPRITE sprite)
{
	// 플레이어 총알 - 1 그리기
	if(type == 0)
		Draw(sprite, gAssetManager->player1BulletTexture);
	// 플레이어 총알 - 2 그리기
	if (type == 1)
		Draw(sprite, gAssetManager->player2BulletTexture);
	// 플레이어 총알 - 3 그리기
	if (type == 2)
		Draw(sprite, gAssetManager->player3BulletTexture); 
	// 애드온 총알 그리기
	if (type == 3)
		Draw(sprite, gAssetManager->addonBulletTexture);
	// 적 총알 그리기
	if (type == 4)
		Draw(sprite, gAssetManager->enemyBulletTexture);
}