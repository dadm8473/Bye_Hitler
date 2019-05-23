#pragma once

class CBullet : public CMatrix
{
public:
	int type;

	float speed;
	float moveAngle;

	int damage;
	
	bool isDestroyed;

	RECT rect;

	CBullet(D3DXVECTOR2 pos, int type, float speed, float moveAngle, int damage);
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);
};