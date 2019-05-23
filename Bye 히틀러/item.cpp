#include "DXUT.h"
#include "Header.h"

CItem::CItem(D3DXVECTOR2 pos, int type)
	:CMatrix(), type(type), moveDir(1), moveDir2(1), isDie(false)
{
	position = pos;

	if (type == 0)
	{
		center.x = 32;
		center.y = 32;
	}
	else if (type == 1)
	{
		center.x = 32;
		center.y = 32;
	}
}

void CItem::Update(float deltaTime)
{
	if (type == 0)
	{
		position.y += moveDir2 * 200 * deltaTime;
		if (position.y >= 1024)
			moveDir2 = -moveDir2;
		if (position.y <= 0)
			moveDir2 = -moveDir2;

		position.x += moveDir * 300 * deltaTime;
		if (position.x >= 768)
			moveDir = -moveDir;
		if (position.x <= 0)
			moveDir = -moveDir;
	}
	else if (type == 1)
	{
		position.y += moveDir2 * 200 * deltaTime;
		if (position.y >= 1024)
			moveDir2 = -moveDir2;
		if (position.y <= 0)
			moveDir2 = -moveDir2;

		position.x += moveDir * 300 * deltaTime;
		if (position.x >= 768)
			moveDir = -moveDir;
		if (position.x <= 0)
			moveDir = -moveDir;
	}

	CMatrix::Update(deltaTime);

	SetRect(&rect, position.x - 32,
		position.y - 32,
		position.x + 32,
		position.y + 32);
}

void CItem::Render(LPD3DXSPRITE sprite)
{
	if (type == 0)
		Draw(sprite, gAssetManager->item1Texture);
	else if (type == 1)
		Draw(sprite, gAssetManager->item2Texture);
}