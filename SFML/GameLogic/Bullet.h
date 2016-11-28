#pragma once

#include "GameLogic.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

const std::string pathToBulletTexture = "res/playerChar/bulletPlayer.png";
const int NUM_OF_BULLETS = 100;
const float BULLET_VELOCITY = -1.f;
const unsigned int VISIBLE = 0x01;

class Bullets
{
private:
	sf::Sprite* sprite[NUM_OF_BULLETS];
	unsigned int flags[NUM_OF_BULLETS];
	int activeBullet = 0;
public:
	Bullets();
	void Shoot(sf::Vector2f startPosition);
	void CheckForEnemy();
	void UpdatePosition(float deltaTime);
	void Draw(sf::RenderWindow* window);
	~Bullets();
};