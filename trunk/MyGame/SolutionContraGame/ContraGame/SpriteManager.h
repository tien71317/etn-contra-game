#ifndef __SPRITE_MANAGER__
#define __SPRITE_MANAGER__

#include "CSpriteDx9.h"
#include "CGlobal.h"
#include <map>

class CSpriteDx9;

class SpriteManager
{
	SpriteManager(void);
	static SpriteManager* s_Instance;
	map<eSpriteID, CSpriteDx9*> m_ListSprite;
	void LoadSpriteContent(LPDIRECT3DDEVICE9 _lpDirectDevice, const char* fileName, eSpriteID SpriteID, int Column, int Row, int TotalFrame);

public:
	static SpriteManager* GetInstance();
	CSpriteDx9* GetSoundBuffer(eSpriteID eID);
	void InitializeListSprite(LPDIRECT3DDEVICE9 _lpDirectDevice);
	void Release();
	~SpriteManager(void);
};

#endif