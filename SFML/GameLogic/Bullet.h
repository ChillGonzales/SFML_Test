#pragma once

#include "GameLogic.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

const std::string pathToBulletTexture = "res/playerChar/bulletPlayer.png";
const int NUM_OF_BULLETS = 60;
const unsigned int VISIBLE = 0x01;

class Bullets
{
private:
	sf::Sprite sprite[NUM_OF_BULLETS];
	unsigned int flags[NUM_OF_BULLETS];
	float velocityX;
	float velocityY;
	int activeBullet=0;
public:
	Bullets(sf::Sprite* sprite);
	Bullets();
	void Shoot(sf::Vector2f startPosition);
	void CheckForEnemy();
	void UpdatePosition(float deltaTime);
	void Draw(sf::RenderWindow* window);
	~Bullets();
};