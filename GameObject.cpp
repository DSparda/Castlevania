#include "GameObject.h"

CGameObject::CGameObject(int x = 0, int y = 0, int vx = 0.1, int vy = 0)
{
	this->SetPosition(x, y);
	this->SetSpeed(vx, vy);
}
void CGameObject::AddAnimation(int aniId)
{
	LPANIMATION ani = CAnimations::GetInstance()->Get(aniId);
	this->animations.push_back(ani);
}

void CGameObject::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CGameObject::Render()
{
	LPANIMATION ani;
	if (vx > 0) ani = animations[0]; else ani = animations[1];
	ani->Render(x, y);
}
