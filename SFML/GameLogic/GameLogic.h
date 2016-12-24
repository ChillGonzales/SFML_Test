#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

const float GRAVITY_FORCE = 0.3f;
const float JUMP_AIR_TIME = 0.5f;
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;
const float FRAME_RATE = 1 / 60.f;
enum MoveDirections{Up=0, Left=1, Right=2, Down=3};