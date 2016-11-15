#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

const unsigned int JUMPING = 0x01;
const unsigned int MOVE_LEFT = 0x02;
const unsigned int MOVE_RIGHT = 0x04;
const unsigned int FALLING = 0x08;

struct Entity {
	sf::Sprite sprite;
	unsigned int flags = 0x00000000;
	float jumpTime = 0.f;
	float fallTime = 0.f;
};

const float GRAVITY_FORCE = 3.f;
const float JUMP_AIR_TIME = 0.5f;
const float JUMP_FORCE = -5.f;
const float MOVE_FORCE = 500.f;
const int SCREEN_HEIGHT = 1080;
const int SCREEN_WIDTH = 1920;
const int GROUND_HEIGHT = 10;
const int PLAYER_HEIGHT = 110;
const float PLAYER_WEIGHT = 50.f;
enum MoveDirections{Up=0, Left=1, Right=2, Down=3};
void UpdateLogic(Entity* gameObject, int size, float deltaTime);
void InitGameObjects(Entity* object, int size);
void DrawRoutine(sf::RenderWindow* window, Entity* drawableObject, int size);
void ApplyGravity(sf::Vector2f* position);