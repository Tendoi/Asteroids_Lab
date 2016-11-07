/*
==========================================================================
cSound.h
==========================================================================
*/

#ifndef _SOUND_H
#define _SOUND_H

// OpenGL Headers
#include "GameConstants.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class cSound
{
private:

	Mix_Chunk * SoundFX = NULL;
	Mix_Music * sMusic = NULL;
	soundType theSoundType;

public:
	cSound();
	cSound(soundType sndType);
	~cSound();

	bool load(LPCSTR filename);
	void setSoundTYpe(soundType sndType);
	soundType getSoundType();
	void play(int loop);  // use -1 for indifinate loop 
};
#endif