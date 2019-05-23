#pragma once

class CGameScene;

class CItem : public CMatrix
{
public:
	CGameScene*parentScene;

	int type;

	RECT rect;

	int moveDir;
	int moveDir2;

	bool isDie;

	CItem(D3DXVECTOR2 pos, int type);
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);
};