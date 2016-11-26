#pragma once

#include "GameLogic.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

const std::string pathToBulletTexture = "res/playerChar/bulletPlayer.png";

class Bullet
{
private:
	sf::Sprite* sprite;
	unsigned int flags = 0x00000000;
	float velocityX;
	float velocityY;
public:
	Bullet(sf::Sprite* sprite);
	Bullet();
	void Shoot();
	void CheckForEnemy();
	void UpdatePosition();
	void Draw(sf::RenderWindow* window);
	~Bullet();
};