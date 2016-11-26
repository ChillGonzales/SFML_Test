#include "Bullet.h"

Bullets::Bullets(sf::Sprite* sprite, int count)
{
	this->sprite = sprite;
	this->count = count;
	this->positionY[count];
}
Bullets::Bullets()
{
}
void Bullets::Shoot()
{
	this->flags |= VISIBLE;
	velocityY = -3.f;
}
void Bullets::CheckForEnemy()
{

}
void Bullets::UpdatePosition(float deltaTime)
{
	float newPositionY = this->sprite->getPosition().y + (velocityY * deltaTime);
	this->sprite->setPosition(this->sprite->getPosition().x, newPositionY);
}
void Bullets::Draw(sf::RenderWindow* window)
{
	if (this->flags & VISIBLE) { window->draw(*sprite); }
}
Bullets::~Bullets()
{

}