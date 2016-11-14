#include <SFML/Graphics.hpp>
#include "GameLogic\GameLogic.h"

int main()
{
	// Attempt at preallocating all gameobjects
	const int NUM_OF_OBJECTS = 15;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML");
	Entity* gameObjectArray = new Entity[NUM_OF_OBJECTS];

	// Stream in spaceship texture for main player`and create sprite
	sf::Texture texture;
	texture.loadFromFile("res/playerChar/spaceshipMain.png", sf::IntRect(0,0,125,110));
	sf::Sprite spaceshipSprite;
	spaceshipSprite.setTexture(texture);
	gameObjectArray[0].sprite = spaceshipSprite;

	// Setup starter level
	//int (*starterLevel)[SCREEN_WIDTH] = new int[SCREEN_HEIGHT][SCREEN_WIDTH];

	// Setup time variables
	sf::Clock deltaTime;
	sf::Time elapsed;


	// Main game loop
	while(window.isOpen())
	{
		elapsed = deltaTime.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//if (event.type == sf::Event::KeyPressed)
				//if (event.key.code == sf::Keyboard::Space)

		}
		UpdateLogic(gameObjectArray, NUM_OF_OBJECTS, elapsed);
		DrawRoutine(&window, gameObjectArray, NUM_OF_OBJECTS);
	}
	return 0;
}