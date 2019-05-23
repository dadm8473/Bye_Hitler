#pragma once

extern void Init();
extern void Term();
extern void Reset();
extern void Lost();
extern void Update(float deltaTime);
extern void Render();
extern void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

extern float GetAngle(float x, float y);
extern void ChangeScene(string sceneName);
extern int score;
extern int playerLife;
extern bool isAddon;
extern int attackType;
extern bool addonSave;

extern float timeScale;