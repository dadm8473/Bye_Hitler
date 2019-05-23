#pragma once

class CMatrix
{
public:
	D3DXMATRIX matrix;
	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	D3DXVECTOR2 center;
	float rotation;

	int a, r, g, b; // ����

					//�ִϸ��̼�
	int currentScene;							//���� ��
	int maxScene;								//�ִ� ��
	bool isAnimate;								//�ִϸ��̼� ����?
	float animationTime, animationTimer;;		//���ϸ��̼� �ӵ�
	bool isAniEnd;								//�ִϸ��̼��� �����°�
	bool isRepeatAni;							//���ϸ��̼��� �ݺ��Ǵ°�

	void SetAnimation(int maxScene, float time, bool repeat);

	CMatrix();
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);

	void Draw(LPD3DXSPRITE sprite, CTexture* texture, RECT* drawRect = NULL);
};