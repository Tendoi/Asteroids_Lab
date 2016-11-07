/*
==========================================================================
cSoundMgr.h
==========================================================================
*/

#ifndef _SOUNDMGR_H
#define _SOUNDMGR_H

// OpenGL Headers
#include "GameConstants.h"
#include "cSound.h"


using namespace std;

class cSoundMgr
{
private:
	static cSoundMgr* pInstance;

protected:
	cSoundMgr();
	~cSoundMgr();
	map <LPCSTR, cSound*> gameSnds;

public:
	void add(LPCSTR sndName, LPCSTR fileName, soundType sndType);
	cSound* getSnd(LPCSTR sndName);
	void deleteSnd();
	bool initMixer();
	static cSoundMgr* getInstance();
};
#endif