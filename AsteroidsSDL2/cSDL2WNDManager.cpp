/*
==================================================================================
cSDL2WNDManager.cpp
==================================================================================
*/
#include "cSDL2WNDManager.h"

cSDL2WNDManager* cSDL2WNDManager::pInstance = NULL;


/*
=================================================================================
Constructor
=================================================================================
*/
cSDL2WNDManager::cSDL2WNDManager()
{

}
/*
=================================================================================
Singleton Design Pattern
=================================================================================
*/
cSDL2WNDManager* cSDL2WNDManager::getInstance()
{
	if (pInstance == NULL)
	{
		pInstance = new cSDL2WNDManager();
	}
	return cSDL2WNDManager::pInstance;
}

/*
=================================================================================
* Initialise the SDL Context with desired Window Title String, width and height
* @param strWNDTitle The Window Title String
* @param iWidth The width of the window to draw
* @param iHeight The height of the window to draw
=================================================================================
*/
bool cSDL2WNDManager::initWND(string strWNDTitle, int iWidth, int iHeight)
{
	// Initialize SDL's Video subsystem
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Failed to init SDL\n";
		return false;
	}

	mainWindow = SDL_CreateWindow(strWNDTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		iWidth, iHeight, SDL_WINDOW_OPENGL);

	// Check that everything worked out okay
	if (!mainWindow)
	{
		cout << "Unable to create window\n";
		CheckSDLError(__LINE__);
		return false;
	}
	else
	{
		// Get the renderer
		theRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

			if (theRenderer != 0)
			{
				std::cout << "Renderer creation succeeded" << std::endl;

				SDL_SetRenderDrawColor(theRenderer, 0, 0, 100, 255);
			}
			else
			{
				std::cout << "Renderer creation failed" << std::endl;
				return false;
			}
	}

	return true;
}

void cSDL2WNDManager::CheckSDLError(int line = -1)
{
	string error = SDL_GetError();

	if (error != "")
	{
		cout << "SLD Error : " << error << std::endl;

		if (line != -1)
			cout << "\nLine : " << line << std::endl;

		SDL_ClearError();
	}
}


SDL_Window* cSDL2WNDManager::getSDLWindow()
{
	return mainWindow;
}

SDL_GLContext cSDL2WNDManager::getSDL_GLContext()
{
	return mainContext;
}

SDL_Renderer* cSDL2WNDManager::getSDLRenderer()
{
	return theRenderer;
}