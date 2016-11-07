/*
==========================================================================
cFont.h
==========================================================================
*/

#ifndef _CFONT_H
#define _CFONT_H

// OpenGL Headers
#include "GameConstants.h"

using namespace std;

class cFont
{
private:
	TTF_Font* theFont;


public:
	cFont();
	~cFont();
	bool loadFont(LPCSTR fontFileName, int fontSize);
	TTF_Font* getFont();
	SDL_Texture* createTextTexture(SDL_Renderer* theRenderer, LPCSTR text, textType txtType, SDL_Color txtColour, SDL_Color txtBkgd);
};
#endif