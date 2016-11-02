/*
=================
cTexture.h
- Header file for class definition - SPECIFICATION
- Header file for the cD3DXTexture class
=================
*/
#ifndef _CTEXTURE_H
#define _CTEXTURE_H
#include "GameConstants.h"

class cTexture
{
private:
	SDL_Texture* sdlTextureID;
	int textureWidth;
	int textureHeight;


public:
	cTexture();
	cTexture(LPCSTR theFilename, SDL_Renderer *theRenderer);
	~cTexture();
	bool loadTexture(LPCSTR theFilename, SDL_Renderer *theRenderer);		// create the texture for use.
	void renderTexture(SDL_Renderer* theRenderer, SDL_Texture* ptheTexture, SDL_Rect* theSourceRect, SDL_Rect* theDestRect, FPoint theScaling);
	void renderTexture(SDL_Renderer* theRenderer, SDL_Texture* ptheTexture, SDL_Rect* theSourceRect, SDL_Rect* theDestRect, double rotAngle, SDL_Point* spriteCentre, FPoint theScaling);
	SDL_Texture* getTexture();						// return the texture.
	int getTWidth();						// Return width of texture;
	int getTHeight();						// Return height of texture;
};
#endif