#include "DXUT.h"
#include "Header.h"

CBullet::CBullet(D3DXVECTOR2 pos, int type, float speed, float moveAngle, int damage)
	:CMatrix(), type(type), speed(speed), moveAngle(moveAngle), damage(damage), isDestroyed(false)
{
	position = pos;

	// �÷��̾� �Ѿ� - 1
	if (type == 0)
	{
		center.x = 2;
		center.y = 16;

		scale.x = 1;
		scale.y = 2;
	}
	// �÷��̾� �Ѿ� - 2
	else if (type == 1)
	{
		center.x = 2;
		center.y = 16;

		scale.x = 1;
		scale.y = 2;
	}
	// �÷��̾� �Ѿ� - 3
	else if (type == 2)
	{
		center.x = 2;
		center.y = 16;

		scale.x = 1;
		scale.y = 2;
	}
	// �ֵ�� �Ѿ�
	else if (type == 3)
	{
		center.x = 2;
		center.y = 16;

		scale.x = 1;
		scale.y = 2;
	}
	// �� �Ѿ�
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

	// �÷��̾� �Ѿ� - 1 �浹 ����
	if (type == 0)
	{
		SetRect(&rect, position.x - 5, position.y - 32, position.x + 5, position.y + 25);
	}
	// �÷��̾� �Ѿ� - 2 �浹 ����
	else if (type == 1)
	{
		SetRect(&rect, position.x - 5, position.y - 32, position.x + 5, position.y + 25);
	}
	// �÷��̾� �Ѿ� - 3 �浹 ����
	else if (type == 2)
	{
		SetRect(&rect, position.x - 5, position.y - 32, position.x + 5, position.y + 25);
	}
	// �ֵ�� �Ѿ� �浹 ����
	else if (type == 3)
	{
		SetRect(&rect, position.x - 5, position.y - 32, position.x + 5, position.y + 25);
	}
	// �� �Ѿ� �浹 ����
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
	// �÷��̾� �Ѿ� - 1 �׸���
	if(type == 0)
		Draw(sprite, gAssetManager->player1BulletTexture);
	// �÷��̾� �Ѿ� - 2 �׸���
	if (type == 1)
		Draw(sprite, gAssetManager->player2BulletTexture);
	// �÷��̾� �Ѿ� - 3 �׸���
	if (type == 2)
		Draw(sprite, gAssetManager->player3BulletTexture); 
	// �ֵ�� �Ѿ� �׸���
	if (type == 3)
		Draw(sprite, gAssetManager->addonBulletTexture);
	// �� �Ѿ� �׸���
	if (type == 4)
		Draw(sprite, gAssetManager->enemyBulletTexture);
}