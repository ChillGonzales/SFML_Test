#include "Player.h"

int WALK_FRAME_XPOSITIONS[] = { 10, 68, 124, 179, 222, 271, 325 };
int WALK_FRAME_YPOSITIONS[] = { 0, 0, 0, 0, 0, 0, 0 };

Player::Player(sf::Texture* texture)
{
	playerRect = sf::IntRect(WALK_FRAME_START_X, WALK_FRAME_START_Y, PLAYER_WIDTH, PLAYER_HEIGHT);
	this->sprite = new sf::Sprite(*texture, playerRect);
	this->animations = new Animation[ANIM_COUNT];
	this->animations[0].SetVars("Walk", WALK_FPS, WALK_FRAME_XPOSITIONS, WALK_FRAME_YPOSITIONS, PLAYER_HEIGHT);
	this->animations[1].SetVars("Lightning", LIGHTNING_ATTACK_FPS, LIGHT_ATK_FRAME_START_X, LIGHT_ATK_FRAME_START_Y, PLAYER_WIDTH, LIGHT_ATK_HEIGHT);
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
		this->velocityY = INITIAL_JUMP_VELOCITY;
}
void Player::Move(MoveDirections direction)
{
	switch (direction) 
	{
		case MoveDirections::Right:
			this->flags |= MOVE_RIGHT;
			velocityX = MOVE_VELOCITY;
			break;
		case MoveDirections::Left:
			this->flags |= MOVE_LEFT;
			velocityX = -MOVE_VELOCITY;
			break;
	}
}
void Player::StopMove()
{
	velocityX = 0;
	this->flags &= ~MOVE_LEFT;
	this->flags &= ~MOVE_RIGHT;
}
void Player::SpecialAction(ActionTypes action)
{
	switch (action) 
	{
	case ActionTypes::IceShield:
		break;
	case ActionTypes::LightningAttack:
		this->flags |= START_SPECIAL;
		this->specialType |= LIGHTNING_ATTACK_STATE;
		break;
	}
}
void Player::Draw(sf::RenderWindow * window, float deltaTime)
{
	if (this->specialType & LIGHTNING_ATTACK_STATE)
	{
		this->accruedTime += deltaTime;
		if (this->accruedTime >= LIGHTNING_ATTACK_UPDATE_TIME) 
		{
			if (flags & START_SPECIAL) 
			{
				playerRect.left = LIGHT_ATK_FRAME_START_X;
				playerRect.top = LIGHT_ATK_FRAME_START_Y;
				playerRect.height = LIGHT_ATK_HEIGHT;
				GROUND_HEIGHT += 40;
				this->flags &= ~START_SPECIAL;
			}
			else if((playerRect.left - LIGHT_ATK_FRAME_START_X) >= (PLAYER_WIDTH * (LIGHTNING_ATTACK_FPS - 1)))
			{
				this->specialType &= ~LIGHTNING_ATTACK_STATE;
				playerRect.left = WALK_FRAME_START_X;
				playerRect.top = WALK_FRAME_START_Y;
				GROUND_HEIGHT -= 40;
				playerRect.height = PLAYER_HEIGHT;
			}
			else
			{
				playerRect.left += PLAYER_WIDTH;
			}
			this->accruedTime -= LIGHTNING_ATTACK_UPDATE_TIME;
			std::cout << playerRect.left << std::endl;
		}
	}
	else if (this->flags & MOVE_RIGHT)
	{
		if (this->animations[0].MoveToNextFrame(deltaTime))
		{
			playerRect.left = this->animations[0].GetCurrentLeft();
			playerRect.top = this->animations[0].GetCurrentTop();
			playerRect.height = this->animations[0].GetHeight();
		}
	}
	else
	{
		playerRect.left = WALK_FRAME_START_X;
		playerRect.top = WALK_FRAME_START_Y;
		playerRect.height = PLAYER_HEIGHT;
	}

	this->sprite->setTextureRect(playerRect);
	window->draw(*sprite);
}
sf::Vector2f Player::GetPosition()
{
	return this->sprite->getPosition();
}
Player::~Player()
{
}
