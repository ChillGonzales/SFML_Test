#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

const unsigned int JUMPING = 0x01;

struct Entity {
	sf::Sprite sprite;
	unsigned int flags;
};

const float GRAVITY_FORCE = 981.f;
const int SCREEN_HEIGHT = 1080;
const int SCREEN_WIDTH = 1920;
const int PLAYER_HEIGHT = 110;
const float PLAYER_WEIGHT = 10.f;
enum MoveDirections{Up=0, Left=1, Right=2, Down=3};
void UpdateLogic(sf::Sprite* gameObjectArray, int size, sf::Time deltaTime);
void InitGameObjects(sf::Sprite* objectArray, int size);
void DrawRoutine(sf::RenderWindow* window, sf::Sprite* drawableObjects, int size);
void ApplyGravity(sf::Vector2f* position);