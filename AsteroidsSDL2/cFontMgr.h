/*
== == == == == == == == =
cFontMgr.h
- Header file for class definition - SPECIFICATION
- Header file for the InputMgr class
== == == == == == == == =
*/
#ifndef _CFONTMGR_H
#define _CFONTMGR_H
#include "GameConstants.h"
#include "cFont.h"

class cFontMgr
{
private:

	static cFontMgr* pInstance;
	map<LPCSTR, cFont*> fontList;

public:
	static cFontMgr* getInstance();

	cFontMgr();								// Constructor
	~cFontMgr();							// Destructor.
	bool initFontLib();						// Initialise the SDL ttf library
	void addFont(LPCSTR fontName, LPCSTR fileName, int fontSize);  // add font to the Font collection
	cFont* getFont(LPCSTR fontName);				// return the font for use
	void deleteFont();								// delete font.

};

#endif