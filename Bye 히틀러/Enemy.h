#pragma once

class CGameScene;
class CEnemy : public CMatrix
{
public:
	CGameScene*parentScene;

	int type;
	//Ÿ��0 : �������� ���ư��� ���� ź���� �߻��ϴ� ��
	//Ÿ��1 : �밢������ ���ư��� ���� ź���� �߻��ϴ� ��
	//Ÿ��2 : Ÿ��1 �� �ݴ�� ���ư��� ���� ź���� �߻��ϴ� ��
	//Ÿ��3 : ź���� �����ϴ� ��

	bool isDestroyed;
	
	float attackTimer;
	float attackTime;

	float exitTimer;
	float exitTime;
	bool exit;
	float speed;

	int count;

	RECT rect;

	int hp;
	bool isDie;

	bool beHit;				// �¾Ѵ°�
	float hitRedTime;		// �갡 �Ӿ����� �ð�
	float hitRedTimer;

	CEnemy(D3DXVECTOR2 pos, int type);
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprtie);
};