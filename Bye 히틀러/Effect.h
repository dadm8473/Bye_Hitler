#pragma once

class CEffect : public CMatrix
{
public:
	CTexture*effectTexture;
	float scale_x;
	float scale_y;

	CEffect(D3DXVECTOR2 pos, CTexture*tex, int maxScene, float animationTime, float scale_x, float scale_y);

	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);
};