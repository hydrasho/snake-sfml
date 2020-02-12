#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdio.h>
#include "cube.h"

enum e_arrow{
	DOWN,
	UP,
	LEFT,
	RIGHT
};

class Game{

	public:
		Game();
		void dessiner(sf::RenderWindow &window);
		int isCollized();
		void move();
		void onUp();
		void onDown();
		void onRight();
		void onLeft();
		void restart();
	private:
		void onEatPomme();
		void perdu();
	private:
		int m_tailleSerpent;
		Cube *m_tabSerpent[150];
		Cube m_pomme;
		e_arrow arrow;
		int m_score;
		bool m_gameover;
};

#endif
