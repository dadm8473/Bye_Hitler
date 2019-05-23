#include "DXUT.h"
#include "Header.h"


CMatrix::CMatrix()
	: position(0, 0), scale(1, 1), center(0, 0), rotation(0),
	a(255), r(255), g(255), b(255),
	currentScene(0), isAnimate(false), animationTime(0), animationTimer(0),
	isAniEnd(false), isRepeatAni(false), maxScene(0)
{
	D3DXMatrixIdentity(&matrix);
}

void CMatrix::Update(float deltaTime)
{
	D3DXVECTOR2 finalPos = position - center;
	D3DXMatrixTransformation2D(
		&matrix,
		&center,
		0,
		&scale,
		&center,
		D3DXToRadian(rotation),
		&finalPos
	);

	if (isAnimate && !isAniEnd)
	{
		animationTimer += deltaTime;

		if (animationTimer >= animationTime)
		{
			animationTimer = 0;
			if (++currentScene >= maxScene)
			{
				if (isRepeatAni)
				{
					currentScene = 0;
				}
				else
				{
					currentScene--;
					isAniEnd = true;
				}
			}
		}
	}
}

void CMatrix::Render(LPD3DXSPRITE sprite)
{

}
void CMatrix::Draw(LPD3DXSPRITE sprite, CTexture* texture, RECT* drawRect)
{
	sprite->SetTransform(&matrix);
	sprite->Draw(texture->GetTexture(currentScene),
		drawRect, NULL, NULL,
		D3DCOLOR_ARGB(a, r, g, b));
}

void CMatrix::SetAnimation(int maxScene, float time, bool repeat)
{
	this->isAnimate = true;
	this->maxScene = maxScene;
	this->animationTime = time;
	this->animationTimer = 0;
	this->isAniEnd = false;
	this->isRepeatAni = repeat;
}