#pragma once
#include "GameLogic.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#define PLAYER_LOWEST_POS SCREEN_HEIGHT - PLAYER_HEIGHT - GROUND_HEIGHT

// flags BITS
const unsigned char JUMPING = 0x01;
const unsigned char MOVE_LEFT = 0x02;
const unsigned char MOVE_RIGHT = 0x04;
const unsigned char FALLING = 0x08;
const unsigned char START_SPECIAL = 0x10;

//specialType BITS
const unsigned char LIGHTNING_ATTACK_STATE = 0x01;
const unsigned char ICE_SHIELD_STATE = 0x02;

// GRAPHICS CONSTANTS
const int PLAYER_HEIGHT = 75;
const int PLAYER_WIDTH = 68;
const int WALK_FRAME_START_X = 50;
const int WALK_FRAME_START_Y = 13;
const int LIGHTNING_ATTACK_FPS = 9;
const float LIGHTNING_ATTACK_UPDATE_TIME = (1.0 / LIGHTNING_ATTACK_FPS) * 1000;
const int LIGHT_ATK_FRAME_START_X = 550;
const int LIGHT_ATK_FRAME_START_Y = 195;
const int LIGHT_ATK_HEIGHT = 175;

// PHYSICS CONSTANTS
const float PLAYER_WEIGHT = 50.f;
const float JUMP_VELOCITY = -1.f;
const float INITIAL_JUMP_VELOCITY = -2.f;
const float MOVE_VELOCITY = 0.3f;

const std::string pathToPlayerTexture = "res/playerChar/sorlo/sorlosheet.png";
enum ActionTypes {IceShield, LightningJab, LightningAttack, StaffJab};

class Player {
private:
	sf::Sprite* sprite;
	sf::IntRect playerRect;
	unsigned char flags = 0;
	unsigned char specialType = 0;
	float accruedTime = 0.f;
	float velocityX = 0.f;
	float velocityY = 0.f;
	int GROUND_HEIGHT = 10;
public:
	Player(sf::Texture* texture);
	void UpdatePosition(float deltaTime);
	void Jump();
	void Move(MoveDirections direction);
	void StopMove();
	void SpecialAction(ActionTypes action);
	void Draw(sf::RenderWindow* window, float deltaTime);
	sf::Vector2f GetPosition();
	~Player();
};