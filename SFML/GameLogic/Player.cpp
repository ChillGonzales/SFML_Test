#include "Player.h"

Player::Player(sf::Sprite* sprite)
{
	this->sprite = sprite;
}
void Player::UpdatePosition(float deltaTime)
{
	float newPositionX = this->sprite->getPosition().x + (velocityX * deltaTime);
	float newPositionY = this->sprite->getPosition().y + (velocityY * deltaTime);
	if (newPositionY >= PLAYER_LOWEST_POS)
		newPositionY = PLAYER_LOWEST_POS;
	else
		velocityY += GRAVITY_FORCE;

	this->sprite->setPosition(newPositionX, newPositionY);
}
void Player::Jump()
{
	if (this->sprite->getPosition().y >= PLAYER_LOWEST_POS)
		this->velocityY = -4.f;
}
void Player::Move(MoveDirections direction)
{
	switch (direction) 
	{
		case MoveDirections::Right:
			velocityX += MOVE_VELOCITY;
			break;
		case MoveDirections::Left:
			velocityX += -MOVE_VELOCITY;
			break;
	}

}
void Player::StopMove()
{
	velocityX = 0;
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
