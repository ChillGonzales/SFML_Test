#include "Bullet.h"
#include "Player.h"

Bullets::Bullets(sf::Texture* texture)
{
	for (int i = 0; i < NUM_OF_BULLETS; ++i)
	{
		bulletRect = sf::IntRect(BULLET_FRAME_START_X, BULLET_FRAME_START_Y, BULLET_WIDTH, BULLET_HEIGHT);
		this->sprite[i] = new sf::Sprite(*texture, bulletRect);
		this->flags[i] = 0;
		this->accruedTime[i] = 0.0;
	}
	this->activeBullet = 0;
}
void Bullets::Shoot(sf::Vector2f startPosition)
{
	this->flags[activeBullet] |= VISIBLE;
	this->sprite[activeBullet]->setPosition(startPosition.x + 50, startPosition.y);
	if (activeBullet == NUM_OF_BULLETS - 1) 
		this->activeBullet = 0; 
	else 
		this->activeBullet++; 
	std::cout << this->activeBullet << std::endl;
}
void Bullets::CheckForEnemy()
{

}
void Bullets::UpdatePosition(float deltaTime)
{
	for (int i = 0; i <= NUM_OF_BULLETS-1; ++i) 
	{
		float newPositionY = this->sprite[i]->getPosition().y + (BULLET_VELOCITY * deltaTime);
		this->sprite[i]->setPosition(this->sprite[i]->getPosition().x, newPositionY);
		if (newPositionY < 0)
			this->flags[i] &= ~VISIBLE;
	}
}
void Bullets::Draw(sf::RenderWindow* window, float deltaTime)
{
	for (int i = 0; i <= NUM_OF_BULLETS-1; ++i) {
		if (this->flags[i] & VISIBLE)
		{
			this->accruedTime[i] += deltaTime;
			if (this->accruedTime[i] >= updateFPSTime) 
			{ 
				std::cout << this->accruedTime << std::endl;
				accruedTime[i] -= updateFPSTime;
				if ((bulletRect.left - BULLET_FRAME_START_X) > (PLAYER_WIDTH * 4))
					bulletRect.left = BULLET_FRAME_START_X;
				else
					bulletRect.left += PLAYER_WIDTH;
			}
			window->draw(*sprite[i]); 
		}
	}
}
Bullets::~Bullets()
{
}