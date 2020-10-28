#include "cube.h"
Cube::Cube()
{
	m_sprite.setFillColor(sf::Color(255,0,0));
	m_sprite.setSize(sf::Vector2f(25, 25));
}
Cube::Cube(sf::Color color)
{
	m_sprite.setFillColor(color);
	m_sprite.setSize(sf::Vector2f(25, 25));
}
Cube::Cube(sf::Color color, sf::Vector2f position)
{
	m_sprite.setFillColor(color);
	m_sprite.setSize(sf::Vector2f(25, 25));
	m_sprite.setPosition(position);
	m_sprite.setOutlineThickness(-2.f);
	m_sprite.setOutlineColor(sf::Color(30, 30, 30));
}
void Cube::dessine(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}
sf::RectangleShape *Cube::getSprite()
{
	return &m_sprite;
}
