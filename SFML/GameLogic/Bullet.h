#pragma once

#include "GameLogic.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

const std::string pathToBulletTexture = "res/playerChar/bulletPlayer.png";
const int NUM_OF_BULLETS = 100;
const int BULLET_FRAME_START_X = 450;
const int BULLET_FRAME_START_Y = 580;
const int BULLET_WIDTH = 32;
const int BULLET_HEIGHT = 32;
const int FPS = 4;
const float updateFPSTime = (1.0 / FPS) * 1000.0;
const float BULLET_VELOCITY = 0.25f;
const unsigned char VISIBLE = 0x01;

class Bullets
{
private:
	sf::Sprite* sprite[NUM_OF_BULLETS];
	sf::IntRect bulletRect;
	unsigned char flags[NUM_OF_BULLETS];
	int activeBullet = 0;
	float accruedTime[NUM_OF_BULLETS];
public:
	Bullets(sf::Texture* texture);
	void Shoot(sf::Vector2f startPosition);
	void CheckForEnemy();
	void UpdatePosition(float deltaTime);
	void Draw(sf::RenderWindow* window, float deltaTime);
	~Bullets();
};