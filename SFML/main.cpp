#include <SFML/Graphics.hpp>
#include "GameLogic\Player.h"

int main()
{
	// Attempt at preallocating all gameobjects
	const int NUM_OF_OBJECTS = 15;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML");

	sf::Texture playerTexture;
	playerTexture.loadFromFile(pathToPlayerTexture, sf::IntRect(0,0,125,110));
	sf::Sprite playerSprite;
	playerSprite.setTexture(playerTexture);

	Player player = Player(&playerSprite);

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
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Space)
				{
					player.Jump();
				}
		}
		player.UpdatePosition(elapsed.asMilliseconds());
		player.Draw(&window);
	}
	return 0;
}