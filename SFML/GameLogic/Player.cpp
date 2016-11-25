#include "Player.h"

Player::Player(sf::Sprite* sprite)
{
	this->sprite = sprite;
}
void Player::UpdatePosition(float deltaTime)
{
	float newPositionX = this->sprite->getPosition().x + (velocityX * deltaTime);
	float newPositionY = this->sprite->getPosition().y + (velocityY + GRAVITY_FORCE) * deltaTime;
	if (newPositionY >= (SCREEN_HEIGHT - PLAYER_HEIGHT)) 
	{
		newPositionY = (SCREEN_HEIGHT - PLAYER_HEIGHT);
	}
	else 
	{
		velocityY += GRAVITY_FORCE;
	}
	this->sprite->setPosition(newPositionX, newPositionY);
}
void Player::Jump()
{
	this->velocityY += JUMP_VELOCITY;
}
void Player::Draw(sf::RenderWindow * window)
{
	window->clear();
	window->draw(*sprite);
	window->display();
}
Player::~Player()
{
}
