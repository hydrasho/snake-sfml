#include "scene.h"

Scene::Scene()
{
	activity = MENU;
	int y = 0;
	int x = 0;
	for(int i = 0; i < 26;i++)
	{
		tab[i] = new Cube(sf::Color::Color(100,100,100), sf::Vector2f(x, y));
		x+=25;
	}
}

void Scene::dessine(sf::RenderWindow &window)
{
	for(int i = 0; i < 26;i++)
	{
		tab[i]->dessine(window);
	}

	if(activity == MENU)
	{

	}
	else if(activity == GAME)
	{

	}
	else if(activity == PAUSE)
	{

	}
}

void Scene::event(sf::Event event, sf::RenderWindow &window)
{
	if (event.type == sf::Event::Closed)
	{
		window.close();
	}
}
