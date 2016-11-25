#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

const float GRAVITY_FORCE = 1.f;
const float JUMP_AIR_TIME = 0.5f;
const float MOVE_FORCE = 500.f;
const int SCREEN_HEIGHT = 1080;
const int SCREEN_WIDTH = 1920;
enum MoveDirections{Up=0, Left=1, Right=2, Down=3};