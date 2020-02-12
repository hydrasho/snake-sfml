#include "game.h"

Game::Game()
{
	Font_Answer.loadFromFile("font/Answer.ttf");
	m_scoreGraphique.setFont(Font_Answer);
	m_scoreGraphique.setString("Score: 0");
	m_scoreGraphique.setPosition(500,580);
	m_score = 0;
	m_gameover = false;
	arrow = LEFT;
	m_tailleSerpent = 5;
	//serpent
	int a = 275;
	m_tabSerpent[0] = new Cube(sf::Color::Color(0,100,0), sf::Vector2f(a, 400));
	a+=25;
	for(int i=1; i < m_tailleSerpent;i++)
	{
		m_tabSerpent[i] = new Cube(sf::Color::Color(0,255,0), sf::Vector2f(a, 400));
		a = a + 25;
	}
	//pomme
	m_pomme.getSprite()->setPosition(     (rand()%24+1)*25, (rand()%24+1)*25  );
}
void Game::restart()
{
	m_score = 0;
	m_scoreGraphique.setString("Score: 0");
	m_gameover = false;
	arrow = LEFT;
	m_tailleSerpent = 5;
	//serpent
	int a = 275;
	m_tabSerpent[0] = new Cube(sf::Color::Color(0,100,0), sf::Vector2f(a, 400));
	a+=25;
	for(int i=1; i < m_tailleSerpent;i++)
	{
		m_tabSerpent[i] = new Cube(sf::Color::Color(0,255,0), sf::Vector2f(a, 400));
		a = a + 25;
	}
	//pomme
	m_pomme.getSprite()->setPosition(     (rand()%24+1)*25, (rand()%24+1)*25  );
}
void Game::dessiner(sf::RenderWindow &window)
{
	m_pomme.dessine(window);
	for(int i=0; i < m_tailleSerpent;i++)
	{
		m_tabSerpent[i]->dessine(window);
	}
	window.draw(m_scoreGraphique);
}
int Game::isCollized()
{
	if(m_tabSerpent[0]->getSprite()->getGlobalBounds().intersects(m_pomme.getSprite()->getGlobalBounds()))
	{
		this->onEatPomme();
		return 42;//pomme manger
	}
	for(int i=1; i < m_tailleSerpent;i++)
	{
		if(m_tabSerpent[0]->getSprite()->getGlobalBounds().intersects(m_tabSerpent[i]->getSprite()->getGlobalBounds()))
		{
			this->perdu();
			return 1;//serpent manger
		}
	}
	return 0;//rien du tout
}
void Game::perdu()
{
	m_gameover = true;
}
void Game::move()
{
	if (m_gameover == true)
	{
		return;
	}
	sf::Vector2f tmp;
	sf::Vector2f tmp2;
	tmp = m_tabSerpent[0]->getSprite()->getPosition();
	if(arrow == LEFT)
		m_tabSerpent[0]->getSprite()->move(-25, 0);
	if(arrow == RIGHT)
		m_tabSerpent[0]->getSprite()->move(25, 0);
	if(arrow == UP)
		m_tabSerpent[0]->getSprite()->move(0, -25);
	if(arrow == DOWN)
		m_tabSerpent[0]->getSprite()->move(0, 25);
	for(int i=1; i < m_tailleSerpent;i++)
	{
		tmp2 = m_tabSerpent[i]->getSprite()->getPosition();
		m_tabSerpent[i]->getSprite()->setPosition(tmp);
		tmp = tmp2;
	}
}
void Game::onEatPomme()
{
	m_pomme.getSprite()->setPosition(     (rand()%24+1)*25, (rand()%24+1)*25  );
	m_score++;
	char str[] = "Score: ";
	m_scoreGraphique.setString(ft_strcat(str, ft_itoa(m_score)));
	printf("NICE\n");
	m_tailleSerpent++;
	m_tabSerpent[m_tailleSerpent-1] = new Cube(sf::Color::Color(0,255,0), m_tabSerpent[m_tailleSerpent-2]->getSprite()->getPosition());
	
}
void Game::onUp()
{
	arrow = UP;
}
void Game::onLeft()
{
	arrow = LEFT;
}
void Game::onRight()
{
	arrow = RIGHT;
}
void Game::onDown()
{
	arrow = DOWN;
}
