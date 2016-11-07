/*
=================
cBullet.h
- Header file for class definition - SPECIFICATION
- Header file for the Bullet class which is a child of cSprite class
=================
*/
#ifndef _CBULLET_H
#define _CBULLET_H
#include "cSprite.h"


class cBullet : public cSprite
{
private:
	SDL_Point bulletVelocity;

public:
	cBullet();
	void update(double deltaTime);		// Bullet update method
	void setBulletVelocity(SDL_Point bulletVel);   // Sets the velocity for the Bullet
	SDL_Point getBulletVelocity();				 // Gets the Bullet velocity
};
#endif