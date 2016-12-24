#pragma once
#include "GameLogic.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#define PLAYER_LOWEST_POS SCREEN_HEIGHT - PLAYER_HEIGHT

const unsigned int JUMPING = 0x01;
const unsigned int MOVE_LEFT = 0x02;
const unsigned int MOVE_RIGHT = 0x04;
const unsigned int FALLING = 0x08;
const int GROUND_HEIGHT = 10;
const int PLAYER_HEIGHT = 75;
const int PLAYER_WIDTH = 75;
const int WALK_FRAME_START_X = 50;
const int WALK_FRAME_START_Y = 13;
const float PLAYER_WEIGHT = 50.f;
const float JUMP_VELOCITY = -2.f;
const float MOVE_VELOCITY = 2.f;
const std::string pathToPlayerTexture = "res/playerChar/sorlo/sorlosheet.png";

class Player {
private:
	sf::Sprite* sprite;
	unsigned int flags = 0;
	float velocityX = 0.f;
	float velocityY = 0.f;
public:
	Player(sf::Sprite* sprite);
	void UpdatePosition(float deltaTime);
	void Jump();
	void Move(MoveDirections direction);
	void StopMove();
	void Draw(sf::RenderWindow* window);
	sf::Vector2f GetPosition();
	~Player();
};