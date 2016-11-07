/*
=================
cSprite.cpp
- Header file for class definition - IMPLEMENTATION
=================
*/
#include "cSprite.h"
/*
=================
- Data constructor initializes the cSprite to the data passed to
- the constructor from the paramater sPosition.
- Is always called, thus ensures all sprite objects are in a consistent state.
=================
*/
cSprite::cSprite() 			// Default constructor
{

	this->spritePos_2D = { 0, 0, 0, 0 };
	this->spriteTexture = NULL;
	this->spriteCentre = {0, 0};
	this->spriteScale = { 1, 1 };
	this->spriteRotationAngle = 0;
	this->boundingRect = { 0, 0, 0, 0 };
	this->mActive = true;
}

cSprite::cSprite(cTexture* theSpriteTexture) 			// Default constructor
{
	this->spriteTexture = theSpriteTexture;
	this->setSpriteDimensions(this->spriteTexture->getTWidth(), this->spriteTexture->getTHeight());
	this->spritePos_2D = { 0, 0, this->spriteTexture->getTWidth(), this->spriteTexture->getTHeight() };
	this->spriteCentre = { this->spritePos_2D.w / 2, this->spritePos_2D.h / 2};
	this->spriteScale = { 1, 1 };
	this->spriteRotationAngle = 0;
	this->boundingRect = { 0, 0, 0, 0 };
	this->mActive = true;
}

/*
=================
- Destructor
=================
*/
cSprite::~cSprite()			// Destructor
{
}
/*
=================
- Return the sprites current position.
=================
*/

SDL_Rect cSprite::getSpritePos()  // Return the sprites current position
{
	return this->spritePos_2D;
}

/*
=================
- set the position of the sprite.
=================
*/

void cSprite::setSpritePos(SDL_Point sPosition)  // set the position of the sprite
{
	this->spritePos_2D.x = sPosition.x;
	this->spritePos_2D.y = sPosition.y;
}

/*
=================
- Return the sprites current image.
=================
*/

cTexture* cSprite::getTexture()  // Return the sprites current image
{
	return this->spriteTexture;
}

/*
=================
- set the image of the sprite.
=================
*/

void cSprite::setTexture(cTexture* theSpriteTexture)  // set the image of the sprite
{
	this->spriteTexture = theSpriteTexture;
	this->setSpriteDimensions(spriteTexture->getTWidth(), spriteTexture->getTHeight());
	this->spritePos_2D.w = textureWidth;
	this->spritePos_2D.h = textureHeight;
	this->spriteCentre = { this->spritePos_2D.w / 2, this->spritePos_2D.h / 2 };
}


void cSprite::render(SDL_Renderer* theRenderer, SDL_Rect* theSourceRect, SDL_Rect* theDestRect, FPoint theScaling)
{
	this->spriteTexture->renderTexture(theRenderer, this->spriteTexture->getTexture(), theSourceRect, theDestRect, theScaling);
}

void cSprite::render(SDL_Renderer* theRenderer, SDL_Rect* theSourceRect, SDL_Rect* theDestRect, double rotAngle, SDL_Point* spriteCentre, FPoint theScaling)
{
	this->spriteTexture->renderTexture(theRenderer, this->spriteTexture->getTexture(), theSourceRect, theDestRect, rotAngle, spriteCentre, theScaling);
}
/*
=================
- Set the sprite dimensions.
=================
*/
void cSprite::setSpriteDimensions(int texWidth, int textHeight)
{
	this->textureWidth = texWidth;
	this->textureHeight = textHeight;
	this->spriteDimensions = { 0, 0, texWidth, textHeight };
}

/*
=================
- Get the sprite dimensions.
=================
*/
SDL_Rect cSprite::getSpriteDimensions()
{
	return this->spriteDimensions;
}
/*
=================
- Return the sprite centre.
=================
*/

SDL_Point cSprite::getSpriteCentre()  // Return the sprites current position
{
	return this->spriteCentre;
}

/*
=================
- set the the sprite centre.
=================
*/

void cSprite::setSpriteCentre(SDL_Point sCentre)  // set the position of the sprite
{
	this->spriteCentre.x = sCentre.x;
	this->spriteCentre.y = sCentre.y;
}
/*
=================
- Return the sprite scaling.
=================
*/

FPoint cSprite::getSpriteScale()  // Return the sprites current scaling
{
	return this->spriteScale;
}

/*
=================
- set the the sprite scale.
=================
*/

void cSprite::setSpriteScale(FPoint sScale)  // set the sprites current scaling
{
	this->spriteScale.X += sScale.X;
	this->spriteScale.Y += sScale.Y;
}
/*
=================
- Update sprite scale.
=================
*/

void cSprite::scaleSprite()  // set the sprites current scaling
{
	// Scale sprite
	this->spritePos_2D.w = this->spriteDimensions.w * this->spriteScale.X;
	this->spritePos_2D.h = this->spriteDimensions.h * this->spriteScale.Y;
	// Scale Sprite Centre for rotation.
	this->spriteCentre.x = this->spritePos_2D.w / 2;
	this->spriteCentre.y = this->spritePos_2D.h / 2;
}
/*
=================
- Return the sprite rotation Angle.
=================
*/

float cSprite::getSpriteRotAngle()  // Return the sprites current scaling
{
	return this->spriteRotationAngle;
}

/*
=================
- set the the sprite scale.
=================
*/

void cSprite::setSpriteRotAngle(float angle)  // set the sprites current scaling
{
	this->spriteRotationAngle = angle;
}
/*
=================
- Determine the bounding rectangle for the sprite.
=================
*/

void cSprite::setBoundingRect(SDL_Rect pRect)
{
	SDL_Point sPos = { this->getSpritePos().x, this->getSpritePos().y };
	this->boundingRect = { sPos.x, sPos.y, this->getSpritePos().w, this->getSpritePos().h }; //(pRect, sPos.x - m_Radius, sPos.y - m_Radius, (textureWidth / 2 + sPos.x), (textureHeight / 2 + sPos.y));

}
/*
=================
- Return the bounding rectangle for the sprite.
=================
*/
SDL_Rect cSprite::getBoundingRect()		// Return the bounding rectangle for the sprite
{
	return cSprite::boundingRect;
}
/*
=================================================================
Sets the translation for the sprite
=================================================================
*/
void cSprite::setSpriteTranslation(SDL_Point spriteTrans)
{
	this->spriteTranslation = spriteTrans;
}
/*
=================================================================
Gets the sprite translation
=================================================================
*/
SDL_Point cSprite::getSpriteTranslation()
{
	return this->spriteTranslation;
}
/*
=================
- Set the sprite to active.
=================
*/
void cSprite::setActive(bool sActive) 			// Set the sprite to active.
{
	mActive = sActive;
}
/*
=================
- Determine if the sprite is active.
=================
*/
bool cSprite::isActive() 						// Determine if the sprite is active.
{
	return mActive;
}
/*
=================
- Check for collisions.
=================
*/

bool cSprite::collidedWith(SDL_Rect* thisSpriteRect, SDL_Rect* otherSpriteRect)
{
	// perform the intersection test
	if (SDL_HasIntersection(thisSpriteRect, otherSpriteRect))
		return true;
	else
		return false;
}

bool cSprite::SphereSphereCollision(SDL_Point spritePosition, float spriteRadius)
{
	SDL_Point theSpriteLen;
	theSpriteLen.x = this->getSpritePos().x - spritePosition.x;
	theSpriteLen.y = this->getSpritePos().y - spritePosition.y;
	const float distSq = lengthSQRD(theSpriteLen);

	const float sumRadius = (this->getSpriteCentre().x + spriteRadius);

	if (distSq < sumRadius * sumRadius)
	{
		return true; // Collision
	}
	return false; // No Collision
}

float cSprite::lengthSQRD(SDL_Point theLength)
{
	return (theLength.x * theLength.x) + (theLength.y * theLength.y);
}