#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
	sf::Texture texture;
	texture.loadFromFile("res/playerChar/spaceshipMain.png", sf::IntRect(0,0,125,110));
	sf::Sprite spaceshipSprite;
	spaceshipSprite.setTexture(texture);

	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(spaceshipSprite);
		window.display();
	}
	return 0;
}