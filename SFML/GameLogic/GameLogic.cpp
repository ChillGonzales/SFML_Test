#include "GameLogic.h"

void UpdateLogic(Entity* gameObject, int size, float deltaTime) 
{
	float totalForce = 0.f;
	float distanceScaleFactor = gameObject->fallTime * 10;

	if (gameObject->sprite.getPosition().y <= (SCREEN_HEIGHT - PLAYER_HEIGHT + GROUND_HEIGHT)) 
	{
		gameObject->flags |= FALLING;
		totalForce = GRAVITY_FORCE;
	}
	else 
	{
		gameObject->flags &= ~FALLING;
		gameObject->fallTime = 0.f;
	}
	if (gameObject->flags & JUMPING)
	{
		totalForce = JUMP_FORCE * (JUMP_AIR_TIME - gameObject->jumpTime);
	}

	// Apply forces to player
	gameObject->sprite.move(0.f, totalForce * PLAYER_WEIGHT * distanceScaleFactor * deltaTime);
}
void InitGameObjects(Entity* objectArray, int size) 
{
}
void DrawRoutine(sf::RenderWindow* window, Entity* drawableObject, int size)
{
	window->clear();
	for (int i = 0; i < size; i++) {
		window->draw(drawableObject->sprite);
	}
	window->display();
}
void ApplyGravity(sf::Vector2f * position)
{

}