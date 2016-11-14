#include "GameLogic.h"

void UpdateLogic(sf::Sprite* gameObjectArray, int size, sf::Time deltaTime) 
{
	// F = m * a (newtons)
	// position = meters
	// acceleration = meters/second
	// F = kg * m/s^2
	// F * s^2 = kg * meters
	// F * s^2 / kg = meters

	// Add up forces on objects
	for (int i = 0; i < size; i++) {
		if (gameObjectArray[i].getPosition().y < (SCREEN_HEIGHT - PLAYER_HEIGHT)){
			gameObjectArray[i].move(0.f, GRAVITY_FORCE * deltaTime.asSeconds());
		}
	}
}
void InitGameObjects(sf::Sprite* objectArray, int size) 
{
}
void DrawRoutine(sf::RenderWindow* window, sf::Sprite* drawableObjects, int size)
{
	window->clear();
	for (int i = 0; i < size; i++) {
		window->draw(drawableObjects[i]);
	}
	window->display();
}
void ApplyGravity(sf::Vector2f * position)
{

}