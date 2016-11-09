#include "Graphics.h"

void Graphics:: DrawRoutine(sf::RenderWindow* window)
{
	sf::Texture texture;
	texture.loadFromFile("res/playerChar/spaceshipMain.png", sf::IntRect(0,0,125,110));
	sf::Sprite spaceshipSprite;
	spaceshipSprite.setTexture(texture);

	window->clear();
	window->draw(spaceshipSprite);
	window->display();
}
