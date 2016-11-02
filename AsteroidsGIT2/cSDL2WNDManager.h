#ifndef _SDL2WNDMANAGER_H
#define _SDL2WNDMANAGER_H

/*
==================================================================================
cSDL2WNDManager.h
==================================================================================
*/
#include <SDL.h>
#include <string>
#include <iostream>

using namespace std;

class cSDL2WNDManager
{
public:
	cSDL2WNDManager();

	bool initWND(string strWNDTitle, int iWidth, int iHeight);
	void CheckSDLError(int line);
	SDL_Window* getSDLWindow();
	SDL_GLContext getSDL_GLContext();
	SDL_Renderer* getSDLRenderer();

	static cSDL2WNDManager* getInstance();

private:

	static cSDL2WNDManager* pInstance;
	SDL_Window *mainWindow;
	SDL_GLContext mainContext;
	SDL_Renderer* theRenderer;

};

#endif

