#include "Animation.h"

Animation::Animation() 
{
}
Animation::Animation(char * _name, int _animFPS, int _leftFrameStart, int _topFrameStart, int _height)
{
	this->animFPS = _animFPS;
	this->leftPositions = new int[animFPS];
	this->topPositions = new int[animFPS];
	this->height = _height;
	this->name = _name;
	this->frameUpdateTime = (1.0 / animFPS) * 1000.0;
	this->ResetAnimation();
}
void Animation::SetVars(char * _name, int _animFPS, int * _xPositions, int * _yPositions, int _height)
{
	this->name = _name;
	this->animFPS = _animFPS;
	this->leftPositions = _xPositions;
	this->topPositions = _yPositions;
	this->height = _height;
	this->frameUpdateTime = (1.0 / animFPS) * 1000.0;
	this->ResetAnimation();
}
void Animation::SetVars(char * _name, int _animFPS, int xStartPosition, int yStartPosition, int _width, int _height)
{
	this->name = _name;
	this->animFPS = _animFPS;
	this->leftPositions = new int[this->animFPS];
	this->topPositions = new int[this->animFPS];
	for (int i = 0; i < animFPS; ++i)
	{
		this->leftPositions[i] = xStartPosition +  (_width * i);
		this->topPositions[i] = yStartPosition;
	}
	this->height = _height;
}
void Animation::ResetAnimation()
{
	this->currentFrame = 0;
	this->accruedTime -= this->frameUpdateTime;
}
int Animation::GetCurrentLeft()
{
	return this->leftPositions[currentFrame];
}
int Animation::GetCurrentTop()
{
	return this->topPositions[currentFrame];
}
int Animation::GetHeight()
{
	return this->height;
}
void Animation::IncrementFrameCount()
{
	currentFrame++;
	if (currentFrame > (this->animFPS - 1))
		this->ResetAnimation();
}
bool Animation::MoveToNextFrame(float deltaTime)
{
	this->accruedTime += deltaTime;
	if (this->accruedTime >= this->frameUpdateTime)
	{
		this->IncrementFrameCount();
		return true;
	}
	else
	{
		return false;
	}
}
char * Animation::GetName()
{
	return this->name;
}
