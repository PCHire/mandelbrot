#include "pch.h"
#include <iostream>

#include <SFML/Graphics.hpp>

#include "setup.h"
#include "plotter.h"

int main()
{
	sf::RenderWindow *window = setup();
	int screenX = window->getSize().x;
	int screenY = window->getSize().y;
	Plotter *plotter = new Plotter();

	sf::Texture texture;
	texture.create(screenX, screenY);
	texture.update(plotter->plot(*window));

	sf::Sprite sprite(texture);

	while (window->isOpen())
	{
		

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		window->draw(sprite);
		window->display();
	}

	return 0;
}
