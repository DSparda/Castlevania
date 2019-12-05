#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>

#include "Sprites.h"

using namespace std;

class CGameObject
{
	float x;
	float y;

	float vx;
	float vy;

	int currentState;

	vector <LPANIMATION> animations;

public:
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	void SetState(int state) { this->currentState = state; }
	void SetSpeed(float vx, float vy) { this->vx = vx, this->y = vy; }

	void AddAnimation(int aniId);

	CGameObject(int x, int y, int vx, int vy);

	void Update(DWORD dt);
	void Render();

	~CGameObject() {};
};