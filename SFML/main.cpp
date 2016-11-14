#include <SFML/Graphics.hpp>
#include "GameLogic\GameLogic.h"

int main()
{
	// Attempt at preallocating all gameobjects
	const int NUM_OF_OBJECTS = 15;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML");
	Entity gameObject;

	// Stream in spaceship texture for main player`and create sprite
	sf::Texture texture;
	texture.loadFromFile("res/playerChar/spaceshipMain.png", sf::IntRect(0,0,125,110));
	sf::Sprite spaceshipSprite;
	spaceshipSprite.setTexture(texture);
	gameObject.sprite = spaceshipSprite;

	// Setup starter level
	//int (*starterLevel)[SCREEN_WIDTH] = new int[SCREEN_HEIGHT][SCREEN_WIDTH];

	// Setup time variables
	sf::Clock deltaTime;
	sf::Time elapsed;
	float moveTime = 0.f;


	// Main game loop
	while(window.isOpen())
	{
		elapsed = deltaTime.restart();
		if (gameObject.flags & JUMPING)
		{
			moveTime += elapsed.asSeconds();
			if (moveTime >= JUMP_AIR_TIME)
				gameObject.flags &= ~JUMPING;
		}
		else if (gameObject.flags & FALLING) {
			moveTime += elapsed.asSeconds();
		}
		else
			moveTime = 0.f;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Space)
				{
					gameObject.flags |= JUMPING;
					moveTime = 0.f;
				}
		}
		UpdateLogic(&gameObject, NUM_OF_OBJECTS, moveTime);
		DrawRoutine(&window, &gameObject, NUM_OF_OBJECTS);
	}
	return 0;
}