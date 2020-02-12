#include "scene.h"

Scene::Scene()
{
	activity = MENU;
	m_tmenutitle.loadFromFile("img/snake.png");
	m_tmenuwait.loadFromFile("img/appuyez.png");
	m_tgameover.loadFromFile("img/gameover.png");
	m_smenuwait.setTexture(m_tmenuwait);
	m_smenutitle.setTexture(m_tmenutitle);
	m_sgameover.setTexture(m_tgameover);

	m_smenutitle.setPosition(0, 100);
	m_smenuwait.setPosition(0, 300);

	int y = 0;
	int x = 0;
	for(int i = 0; i < 26;i++)
	{
		tab[i] = new Cube(sf::Color::Color(100,100,100), sf::Vector2f(x, y));
		x+=25;
	}
	x = 0;
	for(int i = 0; i < 26;i++)
	{
		tab[i+26] = new Cube(sf::Color::Color(100,100,100), sf::Vector2f(x, y));
		y+=25;
	}
	y = y - 25;
	for(int i = 0; i < 26;i++)
	{
		tab[i+26*2] = new Cube(sf::Color::Color(100,100,100), sf::Vector2f(x, y));
		x+=25;
	}
	x-=25;
	for(int i = 0; i < 26;i++)
	{
		tab[i+26*3] = new Cube(sf::Color::Color(100,100,100), sf::Vector2f(x, y));
		y-=25;
}
}

void Scene::dessine(sf::RenderWindow &window)
{
	for(int i = 0; i < 26*4;i++)
	{
		tab[i]->dessine(window);
	}

	if(activity == MENU)
	{
		window.draw(m_smenutitle);
		if(m_timerwait.getElapsedTime().asMilliseconds() >= 350)
		{
			m_timerwait.restart();
			if(affichewait)
				affichewait = false;
			else
				affichewait = true;
		}
		if(affichewait)
			window.draw(m_smenuwait);
	}
	else if(activity == GAME)
	{
		m_game.dessiner(window);
		if(m_movegame.getElapsedTime().asMilliseconds() >=150)
		{
			m_game.move();
			m_movegame.restart();
		}
		if(m_game.isCollized() == 1)
		{
			activity = PAUSE;
		}
	}
	else if(activity == PAUSE)
	{
		m_game.dessiner(window);
		window.draw(m_sgameover);
	}
}

void Scene::event(sf::Event event, sf::RenderWindow &window)
{
	if (event.type == sf::Event::Closed)
	{
		window.close();
	}
	if(activity == MENU)
	{
		if(event.type == sf::Event::KeyPressed)
		{
			activity = GAME;
		}
	}
	else if (activity == GAME)
	{
		if(event.key.code == sf::Keyboard::Up)
		{
			m_game.onUp();
		}
		if(event.key.code == sf::Keyboard::Right)
		{
			m_game.onRight();
		}
		if(event.key.code == sf::Keyboard::Left)
		{
			m_game.onLeft();
		}
		if(event.key.code == sf::Keyboard::Down)
		{
			m_game.onDown();
		}
	}
	else if(activity == PAUSE)
	{
		if(event.key.code == sf::Keyboard::Return)
		{
			m_game.restart();
			activity = GAME;
		}	
	}
}
