#include <SFML/Graphics.hpp>
#include "GameLogic\Player.h"
#include "GameLogic\Bullet.h"

int main()
{
	// Attempt at preallocating all gameobjects
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML");

	// Set up player class
	sf::Texture playerTexture;
	playerTexture.loadFromFile(pathToPlayerTexture);
	sf::IntRect playerRect(WALK_FRAME_START_X, WALK_FRAME_START_Y, PLAYER_WIDTH, PLAYER_HEIGHT);
	sf::Sprite playerSprite(playerTexture, playerRect);

	Player player = Player(&playerSprite);

	// Set up bullet array
	
	Bullets* bullets = new Bullets(&playerTexture);

	// Setup time variables
	sf::Clock deltaTime;
	sf::Time elapsed;

	// Main game loop
	while(window.isOpen())
	{
		elapsed += deltaTime.restart();
		if (elapsed.asSeconds() >= FRAME_RATE)
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == sf::Event::KeyPressed) 
				{
					switch (event.key.code)
					{
						case sf::Keyboard::Space:
							player.Jump();
							break;
						case sf::Keyboard::D:
							player.Move(MoveDirections::Right);
							break;
						case sf::Keyboard::A:
							player.Move(MoveDirections::Left);
							break;
						case sf::Keyboard::F:
							bullets->Shoot(player.GetPosition());
							break;
					}
				}
				if (event.type == sf::Event::KeyReleased) 
				{
					if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A)
						player.StopMove();
				}
			}
			player.UpdatePosition(elapsed.asMilliseconds());
			bullets->UpdatePosition(elapsed.asMilliseconds());

			window.clear();
			player.Draw(&window);
			bullets->Draw(&window, elapsed.asMilliseconds());
			window.display();

			elapsed = sf::Time::Zero;
		}
	}
	return 0;
}