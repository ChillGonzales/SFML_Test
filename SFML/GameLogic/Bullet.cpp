#include "Bullet.h"
#include "Player.h"

Bullets::Bullets()
{
	sf::Texture* bulletTexture = new sf::Texture;
	bulletTexture->loadFromFile(pathToBulletTexture);
	for (int i = 0; i < NUM_OF_BULLETS; ++i)
	{
		this->sprite[i] = new sf::Sprite(*bulletTexture);
		this->flags[i] = 0;
	}
}
void Bullets::Shoot(sf::Vector2f startPosition)
{
	this->flags[activeBullet] |= VISIBLE;
	this->sprite[activeBullet]->setPosition(startPosition.x + 50, startPosition.y);
	if (activeBullet = NUM_OF_BULLETS - 1) { activeBullet = 0; }
	else { activeBullet++; }
}
void Bullets::CheckForEnemy()
{

}
void Bullets::UpdatePosition(float deltaTime)
{
	for (int i = 0; i <= activeBullet; ++i) 
	{
		float newPositionY = this->sprite[i]->getPosition().y + (BULLET_VELOCITY * deltaTime);
		this->sprite[i]->setPosition(this->sprite[i]->getPosition().x, newPositionY);
		if (newPositionY < 0)
			this->flags[i] &= ~VISIBLE;
	}
}
void Bullets::Draw(sf::RenderWindow* window)
{
	for (int i = 0; i <= activeBullet; ++i) {
		if (this->flags[i] & VISIBLE) 
		{ 
			window->draw(*sprite[i]); 
		}
	}
}
Bullets::~Bullets()
{
}