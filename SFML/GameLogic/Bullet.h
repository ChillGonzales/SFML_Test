#pragma once

#include "GameLogic.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

const std::string pathToBulletTexture = "res/playerChar/bulletPlayer.png";
const unsigned int VISIBLE = 0x01;

class Bullets
{
private:
	sf::Sprite* sprite;
	unsigned int flags = 0x00000000;
	float velocityX;
	float velocityY;
	int count;
	float positionY[];
public:
	Bullets(sf::Sprite* sprite, int count);
	Bullets();
	void Shoot();
	void CheckForEnemy();
	void UpdatePosition(float deltaTime);
	void Draw(sf::RenderWindow* window);
	~Bullets();
};