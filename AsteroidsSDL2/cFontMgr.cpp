/*
== == == == == == == == =
cFontMgr.h
- Header file for class definition - SPECIFICATION
- Header file for the InputMgr class
== == == == == == == == =
*/

#include "cFontMgr.h"

cFontMgr* cFontMgr::pInstance = NULL;

/*
=================================================================================
Singleton Design Pattern
=================================================================================
*/
cFontMgr* cFontMgr::getInstance()
{
	if (pInstance == NULL)
	{
		pInstance = new cFontMgr();
	}
	return cFontMgr::pInstance;
}

/*
=================================================================================
Constructor
=================================================================================
*/
cFontMgr::cFontMgr()
{
}

cFontMgr::~cFontMgr()							// Destructor.
{
	deleteFont();
	TTF_Quit();
}

bool cFontMgr::initFontLib()
{
	// Initialize SDL_ttf library
	if (TTF_Init() != 0)
	{
		cout << "TTF_Init() Failed: " << SDL_GetError() << endl;
		return false;
	}
	else
	{
		return true; 
	}
}

void cFontMgr::addFont(LPCSTR fontName, LPCSTR fileName, int fontSize)  // add font to the Font collection
{
	if (!getFont(fontName))
	{
		cFont * newFont = new cFont();
		newFont->loadFont(fileName, fontSize);
		fontList.insert(make_pair(fontName, newFont));
	}
}

cFont* cFontMgr::getFont(LPCSTR fontName)				// return the font for use
{
	map<LPCSTR, cFont*>::iterator theFont = fontList.find(fontName);
	if (theFont != fontList.end())
	{
		return theFont->second;
	}
	else
	{
		return NULL;
	}
}

void cFontMgr::deleteFont()								// delete font.
{
	for (map<LPCSTR, cFont*>::const_iterator theFont = fontList.begin(); theFont != fontList.end(); theFont++)
	{
		TTF_CloseFont(theFont->second->getFont());
		delete theFont->second;
	}
}
