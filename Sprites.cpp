#include "Sprites.h"
#include "Game.h"

CSprites* CSprites::__instance = NULL;

CSprite::CSprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	this->id = id;
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->texture = tex;
}

void CSprite::Draw(float x, float y)
{
	CGame* game = CGame::GetInstance();
	game->Draw(x, y, texture, left, top, right, bottom);
}

void CSprites::Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	LPSPRITE s = new CSprite(id, left, top, right, bottom, tex);
	sprites[id] = s;
}

LPSPRITE CSprites::Get(int id)
{
	return sprites[id];
}

CSprites* CSprites::GetInstance()
{
	if (__instance == NULL) __instance = new CSprites();
	return __instance;
}

CFrame::CFrame(LPSPRITE sprite, int time)
{
	this->sprite = sprite;
	this->time = time;
}

DWORD CFrame::GetTime()
{
	return this->time;
}

LPSPRITE CFrame::GetSprite()
{
	return this->sprite;
}

CAnimation::CAnimation(int defaultTime)
{
	this->defaultTime = defaultTime;
	lastFrameTime = -1;
	currentFrame = -1;
}

void CAnimation::Add(int spriteId, DWORD time)
{
	int t = time;
	if (time == 0) t = this->defaultTime;

	LPSPRITE sprite = CSprites::GetInstance()->Get(spriteId);
	LPFRAME frame = new CFrame(sprite, t);
	frames.push_back(frame);
}

void CAnimation::Render(float x, float y)
{
	DWORD now = GetTickCount();
	if (currentFrame == -1)
	{
		currentFrame = 0;
		lastFrameTime = now;
	}
	else
	{
		DWORD t = frames[currentFrame]->GetTime();
		if (now - lastFrameTime > t)
		{
			currentFrame++;
			lastFrameTime = now;
			if (currentFrame == frames.size()) currentFrame = 0;
		}
	}
	frames[currentFrame]->GetSprite()->Draw(x, y);
}

CAnimations* CAnimation::_instance = NULL;

void CAnimations::Add(int id, LPANIMATION ani)
{
	animations[id] = ani;
}

LPANIMATION CAnimations::Get(int id)
{
	return animations[id];
}

CAnimations* CAnimation::GetInstance()
{
	if (__instance == NULL) __instance = new CAnimations();
	return __instance;
}