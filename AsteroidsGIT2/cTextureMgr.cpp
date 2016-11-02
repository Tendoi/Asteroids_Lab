/*
=================
cTextureMgr.cpp
- CPP file for class definition - IMPLEMENTATION
- CPP file for the TextureMgr class
=================
*/
#include "cTextureMgr.h"
cTextureMgr* cTextureMgr::pInstance = NULL;

/*
=================================================================================
Singleton Design Pattern
=================================================================================
*/
cTextureMgr* cTextureMgr::getInstance()
{
	if (pInstance == NULL)
	{
		pInstance = new cTextureMgr();
	}
	return cTextureMgr::pInstance;
}

/*
=================
- Data constructor initializes the TextureMgr object 
- Is always called, thus ensures all TextureMgr objects are in a consistent state.
=================
*/
cTextureMgr::cTextureMgr()
{
	
}

cTextureMgr::cTextureMgr(SDL_Renderer* theRenderer)
{
	theSDLRenderer = theRenderer;
}

/*
=================
- Destructor.
=================
*/
cTextureMgr::~cTextureMgr()
{
	
}

void cTextureMgr::addTexture(LPCSTR txtName, LPCSTR theFilename)
{
	if (!getTexture(txtName))
	{
		cTexture * newTxt = new cTexture();
		newTxt->loadTexture(theFilename, theSDLRenderer);
		textureList.insert(make_pair(txtName, newTxt));
	}
}

void cTextureMgr::deleteTextures()
{
	for (map<LPCSTR, cTexture*>::iterator txt = textureList.begin(); txt != textureList.end(); ++txt)
	{
		delete txt->second;
	}
}
/*
=================
- return the texture.
=================
*/
cTexture* cTextureMgr::getTexture(LPCSTR textureName)        // return the texture.
{
	map<LPCSTR, cTexture*>::iterator txt = textureList.find(textureName);
	if (txt != textureList.end())
	{
		return txt->second;
	}
	else
	{
		return NULL;
	}
}
/*
=================
- Set the renderer.
=================
*/
void cTextureMgr::setRenderer(SDL_Renderer* ptheRenderer)
{
	this->theSDLRenderer = ptheRenderer;
}