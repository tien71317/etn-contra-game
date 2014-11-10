
#define SCREEN_HEIGHT 448

#define SCREEN_WIDTH 512

#define SAFE_DELETE(p)       if(p) { delete (p);     (p)=0; }

#define SAFE_DELETE_ARRAY(p) if(p) { delete[] (p);   (p)=0; }

#define SAFE_RELEASE(p)      if(p) { (p)->Release(); (p)=0; }

#ifndef SPRITEHANDLE
#define	SPRITEHANDLE LPD3DXSPRITE
#endif
#define			GAMETITLE	"Contra"
#define	FRAME_RATE	60

#define DIRECTINPUT_HEADER_VERSION  0x0800
#ifndef DIRECTINPUT_VERSION
#define DIRECTINPUT_VERSION         DIRECTINPUT_HEADER_VERSION
#endif

//initialize value of variable in this struct in SoundManager.cpp
#ifndef __CSOUNDSWITCH__
#define __CSOUNDSWITCH__
struct CSoundSwitch
{
	static bool IsExit;
	static bool IsMute;
};
#endif