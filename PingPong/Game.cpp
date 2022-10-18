#include "Game.h"
#include "Ball.h"

bool Game::turn = true;
bool Game::onGame = true;

void Game::init()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Ping Pong", sf::Style::Fullscreen);
	this->font.loadFromFile("gamefont.ttf");
	this->ps1.setFont(this->font);
	
	this->ps1.setCharacterSize(100);
	this->ps1.setPosition(sf::Vector2f(this->window->getSize().x/4,100));
	this->font.loadFromFile("gamefont.ttf");
	this->ps2.setFont(this->font);
	
	this->ps2.setCharacterSize(100);
	this->ps2.setPosition(sf::Vector2f(this->window->getSize().x / 4 *3, 100));
	this->p1 = new Player(1, sf::Vector2f(this->window->getSize().x/8, this->window->getSize().y / 2));
	this->p2 = new Player(2, sf::Vector2f((this->window->getSize().x /8)*7, this->window->getSize().y / 2));

	if (turn)
	{
		this->b1 = new Ball(sf::Vector2f(this->window->getSize().x / 3, 540.0f),p1,p2);
	}
	else
	{
		this->b1 = new Ball(sf::Vector2f((this->window->getSize().x / 3)*2, 540.0f),p1, p2);
	}
}

void Game::pollEvent()
{
	while (this->window->pollEvent(this->evnt))
	{
		switch (this->evnt.type)
		{
		case sf::Event::Closed: this->window->close();
			break;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			this->window->close();
		}
	}
}

bool Game::isRunning()
{
	if (this->window->isOpen())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::update()
{
	this->pollEvent();
	this->p1->update();
	this->p2->update();
	if (this->b1->leftCollision())
	{
		delete this->b1;
	}
	if (this->b1->rightCollision())
	{
		delete this->b1;
	}
	if (!onGame)
	{
		if (turn)
		{
			this->b1 = new Ball(sf::Vector2f(this->window->getSize().x / 3, 540.0f), p1, p2);
		}
		else
		{
			this->b1 = new Ball(sf::Vector2f((this->window->getSize().x / 3) * 2, 540.0f), p1, p2);
		}
		onGame = true;
	}
	this->b1->update();
	this->ps1.setString(this->p1->getScore());
	this->ps2.setString(this->p2->getScore());
}

void Game::render()
{
	this->window->clear();
	this->window->draw(this->ps1);
	this->window->draw(this->ps2);
	this->p1->drawPlayer(*(this->window));
	this->p2->drawPlayer(*(this->window));
	if ((this->b1->alive) == true)
	{
		this->b1->drawBall(*(this->window));
	}
	this->window->display();
}

