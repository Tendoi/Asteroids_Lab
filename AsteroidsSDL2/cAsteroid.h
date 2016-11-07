/*
=================
cAsteroid.h
- Header file for class definition - SPECIFICATION
- Header file for the Rocket class which is a child of cSprite class
=================
*/
#ifndef _CASTEROID_H
#define _CASTEROID_H
#include "cSprite.h"

class cAsteroid : public cSprite
{
private:
	SDL_Point asteroidVelocity;

public:
	cAsteroid();
	void update(double deltaTime);		// Rocket update method
	void setAsteroidVelocity(SDL_Point asteroidVel);   // Sets the velocity for the asteroid
	SDL_Point getAsteroidVelocity();				 // Gets the asteroid velocity
};
#endif