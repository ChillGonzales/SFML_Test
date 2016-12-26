#include "Animation.h"

Animation::Animation()
{
}
Animation::Animation(char * name, int _animFPS, int _leftFrameStart, int _topFrameStart, int _height)
{
	this->animFPS = _animFPS;
	this->leftPositions = new int[animFPS];
}
void Animation::SetVars(char * _name, int _animFPS, int * _xPositions, int * _yPositions, int _height)
{
	this->name = _name;
	this->animFPS = _animFPS;
	this->leftPositions = _xPositions;
	this->height = _height;
	this->ResetAnimation();
}
void Animation::SetVars(char * _name, int _animFPS, int xStartPosition, int yStartPosition, int _width, int _height)
{
	this->name = _name;
	this->animFPS = _animFPS;
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
}
int Animation::GetNextLeft()
{
	this->currentFrame++;
	if (currentFrame > (animFPS - 1))
		this->ResetAnimation();
	return this->leftPositions[currentFrame];
}
int Animation::GetHeight()
{
	return this->height;
}
char * Animation::GetName()
{
	return this->name;
}
