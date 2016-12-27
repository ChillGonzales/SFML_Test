#pragma once

class Animation
{
public:
	Animation();
	Animation(char * name, int _animFPS, int _leftFrameStart, int _topFrameStart, int _height);
	void SetVars(char * _name, int _animFPS, int * _xPositions, int * _yPositions, int _height);
	void SetVars(char * _name, int _animFPS, int xStartPosition, int yStartPosition, int _width, int _height);
	void ResetAnimation();
	int GetCurrentLeft();
	int GetCurrentTop();
	int GetHeight();
	bool MoveToNextFrame(float deltaTime);
	char * GetName();

private:
	void IncrementFrameCount();
	int animFPS;
	int currentFrame;
	float accruedTime = 0.f;
	float frameUpdateTime = 1.f;
	int * leftPositions;
	int * topPositions;
	int height;
	char * name;
};
