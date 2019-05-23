#pragma once

class CEndingScene : public CScene
{
public:

	CMatrix ending;
	CMatrix wave;

	bool isVictory;

	CEndingScene(bool isVictory);
	virtual ~CEndingScene();
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};