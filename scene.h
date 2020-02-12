#ifndef __SCENE_H__
#define __SCENE_H__

#include <SFML/Graphics.hpp>
#include "cube.h"
#include "game.h"

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
		Game m_game;
		Activity activity;
		Cube *tab[105];
		sf::Sprite m_smenutitle;
		sf::Sprite m_smenuwait;
		sf::Sprite m_sgameover;
		sf::Texture m_tmenutitle;
		sf::Texture m_tmenuwait;
		sf::Texture m_tgameover;
		sf::Clock m_timerwait;
		sf::Clock m_movegame;
		bool affichewait;
};


#endif
