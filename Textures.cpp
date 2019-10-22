#include <Windows.h>

#include <d3d9.h>
#include <d3dx9.h>

#include "Game.h"
#include "textures.h"

CTextures* CTextures::__instance = NULL;

void CTextures::Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(filePath, &info);

	LPDIRECT3DDEVICE9 d3ddv = CGame::GetInstance()->GetDirect3DDevice();
	LPDIRECT3DTEXTURE9 texture;
	
	result = D3DXCreateTextureFromFileEx(
		d3ddv,								
		filePath,							
		info.Width,							
		info.Height,						
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,
		&info,
		NULL,
		&texture);

	textures[id] = texture;
}

LPDIRECT3DTEXTURE9 CTextures::Get(unsigned int id)
{
	return textures[id];
}

CGame::CGame() {}
CGame::~CGame() {}

CTextures* CTextures::GetInstance()
{
	if (__instance == NULL) __instance = new CTextures();
	return __instance;
}
