#ifndef __SCENE_H__
#define __SCENE_H__

#include <SFML/Graphics.hpp>
#include "cube.h"

typedef enum Activity
{
	MENU,
	GAME,
	PAUSE
} Activity;

class Scene
{
	public:
		Scene();
		void dessine(sf::RenderWindow &window);
		void event(sf::Event event, sf::RenderWindow &window);
	private:
		Activity activity;
		Cube *tab[80];
};


#endif
