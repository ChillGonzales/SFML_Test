#include <SFML/Graphics.hpp>
#include "GameLogic\GameLogic.h"

int main()
{
	// Attempt at preallocating all gameobjects
	const int NUM_OF_OBJECTS = 15;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML");
	sf::Sprite* gameObjectArray = new sf::Sprite[NUM_OF_OBJECTS];

	sf::Texture texture;
	texture.loadFromFile("res/playerChar/spaceshipMain.png", sf::IntRect(0,0,125,110));
	sf::Sprite spaceshipSprite;
	spaceshipSprite.setTexture(texture);
	gameObjectArray[0] = spaceshipSprite;

	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		UpdateLogic(gameObjectArray, NUM_OF_OBJECTS);
		DrawRoutine(&window, gameObjectArray, NUM_OF_OBJECTS);
	}
	return 0;
}