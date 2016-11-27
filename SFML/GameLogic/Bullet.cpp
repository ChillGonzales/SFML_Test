#include "Bullet.h"
#include "Player.h"

Bullets::Bullets(sf::Sprite* sprite)
{
	for (int i = 0; i < NUM_OF_BULLETS; ++i) 
	{
		this->sprite[i] = *sprite;
		this->flags[i] = 0;
	}
}
Bullets::Bullets()
{
}
void Bullets::Shoot(sf::Vector2f startPosition)
{
	this->flags[activeBullet] |= VISIBLE;
	this->sprite[activeBullet].setPosition(startPosition.x + 50, startPosition.y);
	activeBullet++;
	velocityY = -3.f;
}
void Bullets::CheckForEnemy()
{

}
void Bullets::UpdatePosition(float deltaTime)
{
	for (int i = 0; i <= activeBullet; ++i) 
	{
		float newPositionY = this->sprite[i].getPosition().y + (velocityY * deltaTime);
		this->sprite[i].setPosition(this->sprite->getPosition().x, newPositionY);
	}
}
void Bullets::Draw(sf::RenderWindow* window)
{
	for (int i = 0; i <= activeBullet; ++i) {
		if (this->flags[i] & VISIBLE) 
		{ 
			window->draw(this->sprite[i]); 
		}
	}
}
Bullets::~Bullets()
{

}