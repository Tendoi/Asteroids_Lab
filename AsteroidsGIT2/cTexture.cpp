/*
=================
cTexture.cpp
- CPP file for class definition - IMPLEMENTATION
- CPP file for the cTexture class
=================
*/
#include "cTexture.h"
using namespace std;
/*
=================
- Data constructor initializes the OpenGL Texture ID object
- Is always called, thus ensures all OpenGL Texture ID objects are in a consistent state.
=================
*/
cTexture::cTexture()
{
	cTexture::sdlTextureID = NULL;
}
/*
=================
- Data constructor initializes the OpenGL Texture ID object
- Is always called, thus ensures all OpenGL Texture ID objects are in a consistent state.
* @param theFilename The image file to load
=================
*/
cTexture::cTexture(LPCSTR theFilename, SDL_Renderer *theRenderer)
{
	cTexture::loadTexture(theFilename, theRenderer);
}

/*
=================
- Destructor.
=================
*/
cTexture::~cTexture()
{
	delete this;
}

/*
=================
- create the texture for use.
=================
*/
bool cTexture::loadTexture(LPCSTR theFilename, SDL_Renderer *theRenderer) 	// create the texture for use.
{

	// Call SDL_Image IMG_LoadTexture to create the desired texture
	sdlTextureID = IMG_LoadTexture(theRenderer, theFilename);

	// Check the Texture has been created from the surface
	if (sdlTextureID != 0)
	{
		cout << "Texture '" << theFilename << "' successfully loaded." << endl;
		SDL_QueryTexture(sdlTextureID, NULL, NULL, &textureWidth, &textureHeight); // determine the width an height of the texture
		return true;
	}
	else
	{
		cout << "Texture '" << theFilename << "' could not be loaded!!" << endl;
		cout << SDL_GetError() << endl;
	}

	return false;
}
/*
=================
- return the texture.
=================
*/
SDL_Texture* cTexture::getTexture()        // return the texture.
{
	return cTexture::sdlTextureID;
}

/*
=================
- Return width of texture.
=================
*/
int cTexture::getTWidth() 						// Return width of texture;
{
	return textureWidth;
}
/*
=================
- Return height of texture.
=================
*/
int cTexture::getTHeight() 						// Return height of texture;
{
	return textureHeight;
}
/*
=================
- Render the texture.
=================
*/
void cTexture::renderTexture(SDL_Renderer* theRenderer, SDL_Texture* ptheTexture, SDL_Rect* theSourceRect, SDL_Rect* theDestRect, FPoint theScaling)
{
	//SDL_RenderSetScale(theRenderer, theScaling.X, theScaling.Y);
	SDL_RenderCopy(theRenderer, ptheTexture, theSourceRect, theDestRect);
}

void cTexture::renderTexture(SDL_Renderer* theRenderer, SDL_Texture* ptheTexture, SDL_Rect* theSourceRect, SDL_Rect* theDestRect, double rotAngle, SDL_Point* spriteCentre, FPoint theScaling)
{
	//SDL_RenderSetScale(theRenderer, theScaling.X, theScaling.Y);
	SDL_RenderCopyEx(theRenderer, ptheTexture, theSourceRect, theDestRect, rotAngle, spriteCentre, SDL_FLIP_NONE);
}


