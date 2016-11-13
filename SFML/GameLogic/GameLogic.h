#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

const float GRAVITY_FORCE = 9.81f;
enum MoveDirections{Up=0, Left=1, Right=2, Down=3};
void UpdateLogic(sf::Sprite* gameObjectArray, int size);
void InitGameObjects(sf::Sprite* objectArray, int size);
void DrawRoutine(sf::RenderWindow* window, sf::Sprite* drawableObjects, int size);
void ApplyGravity(sf::Vector2f* position);
