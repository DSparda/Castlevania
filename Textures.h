#pragma once
#include <d3dx9.h>
#include <unordered_map>

using namespace std;

class CTextures
{
	static CTextures* __instance;

	unordered_map <int, LPDIRECT3DTEXTURE9> textures;

public:
	void Add(int id, LPCWSTR filePath, D3DCOLOR transparentColor);
	LPDIRECT3DTEXTURE9 Get(unsigned int id);

	CTextures();
	~CTextures();

	static CTextures* GetInstance();
};

