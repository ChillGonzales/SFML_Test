#include <SFML/Graphics.hpp>
#include "Graphics\Graphics.h"
#include "GameLogic\GameLogic.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");

	while(window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		GameLogic::UpdateLogic();
		Graphics::DrawRoutine(&window);
	}
	return 0;
}

