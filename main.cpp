#include <SFML/Graphics.hpp>
#include "scene.h"

int main(int argc, char *argv[])
{
	sf::RenderWindow window(sf::VideoMode(650, 650), "Snake");
	sf::Event event;
	Scene scene;

	window.setFramerateLimit(60);
	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			scene.event(event, window);
		}

		window.clear(sf::Color::Color(200,150,0));
		scene.dessine(window);
		window.display();
	}
	return 0;
}
