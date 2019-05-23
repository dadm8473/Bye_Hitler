#pragma once

class CTitleScene : public CScene
{
public:
	CMatrix backGround;
	CMatrix wave1;
	CMatrix wave2;
	CMatrix scene;
	CMatrix howtoplay;
	CMatrix ranking;

	bool activeHowtoplay;
	bool activeranking;

	CTitleScene();
	virtual ~CTitleScene();
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParma);
};