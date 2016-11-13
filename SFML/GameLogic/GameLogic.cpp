#include "GameLogic.h"

void UpdateLogic(sf::Sprite* gameObjectArray, int size) 
{
	for (int i = 0; i < size; i++) {
		if (gameObjectArray[i].getPosition().x > GRAVITY_FORCE) {
			gameObjectArray[i].move(-GRAVITY_FORCE, 0.f);
			std::cout << gameObjectArray[i].getPosition().x << std::endl;
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