#include "GameLogic.h"

void UpdateLogic(Entity* gameObjectArray, int size, sf::Time deltaTime) 
{
	// F = m * a (newtons)
	// position = meters
	// acceleration = meters/second
	// F = kg * m/s^2
	// F * s^2 = kg * meters
	// F * s^2 / kg = meters

	// Add up forces on objects
	for (int i = 0; i < size; i++) {
		if (gameObjectArray[i].sprite.getPosition().y < (SCREEN_HEIGHT - PLAYER_HEIGHT)){
			gameObjectArray[i].sprite.move(0.f, GRAVITY_FORCE * deltaTime.asSeconds());
		}
	}
}
void InitGameObjects(Entity* objectArray, int size) 
{
}
void DrawRoutine(sf::RenderWindow* window, Entity* drawableObjects, int size)
{
	window->clear();
	for (int i = 0; i < size; i++) {
		window->draw(drawableObjects[i].sprite);
	}
	window->display();
}
void ApplyGravity(sf::Vector2f * position)
{

}