#include <SFML/Graphics.hpp>
#include <time.h>
#include "scene.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(650, 650), "Snake");
	sf::Event event;
	Scene scene;

	window.setFramerateLimit(120);
	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			scene.event(event, window);//on envoie les events a la scene
		}
		window.clear(sf::Color(200,150,0));
		scene.dessine(window);//la scene se dessine
		window.display();
	}
	return 0;
}
