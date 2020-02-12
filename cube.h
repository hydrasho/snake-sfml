#ifndef __CUBE_H__
#define __CUBE_H__

#include <SFML/Graphics.hpp>

class Cube{

	public:
		Cube();
		Cube(sf::Color color);
		Cube(sf::Color color, sf::Vector2f position);
		void dessine(sf::RenderWindow &window);
		sf::RectangleShape *getSprite();
	private:
		sf::RectangleShape m_sprite;
};

#endif
