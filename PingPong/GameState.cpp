#include "GameState.h"
#include "Ball.h"
#include <iostream>
#include "Game.h"

bool GameState::turn = true;
bool GameState::onGame = false;
float GameState::time = 0;

GameState::GameState(sf::RenderWindow* window)
{
	this->window = window;
	this->font.loadFromFile("gamefont.ttf");
	this->ps1.setFont(this->font);

	this->ps1.setCharacterSize(100);
	this->ps1.setPosition(sf::Vector2f(this->window->getSize().x / 4, this->window->getSize().y/10.8));
	this->font.loadFromFile("gamefont.ttf");
	this->ps2.setFont(this->font);

	this->ps2.setCharacterSize(100);
	this->ps2.setPosition(sf::Vector2f(this->window->getSize().x / 4 * 3, this->window->getSize().y / 10.8));
	this->p1 = new Player(1, sf::Vector2f(this->window->getSize().x / 8, this->window->getSize().y / 2));
	this->p2 = new Player(2, sf::Vector2f((this->window->getSize().x / 8) * 7, this->window->getSize().y / 2));
	this->lines.setPrimitiveType(sf::Lines);
	this->lines.resize(33);
	for (int i = 0; i < 33; i++)
	{
		this->lines[i].position = sf::Vector2f(Game::sWidth / 2, Game::sHeight * (i+1) / 32);
	}
	while (Game::States == 1)
	{

		this->update();
		this->render();
	}
}

/*void Game::init()
{
	this->window = new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Ping Pong", sf::Style::Fullscreen);
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
}*/

void GameState::pollEvent()
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
			Game::States = 0;
		}
	}
}

void GameState::update()
{
	this->pollEvent();
	this->p1->update();
	this->p2->update();
	if (time > 2)
	{
		if (!onGame)
		{
			if (turn)
			{
				this->b1 = new Ball(sf::Vector2f(this->window->getSize().x / 3, this->window->getSize().y/2), p1, p2);
				onGame = true;
			}
			else
			{
				this->b1 = new Ball(sf::Vector2f((this->window->getSize().x / 3) * 2, this->window->getSize().y / 2), p1, p2);
				onGame = true;
			}
			onGame = true;
		}
		else
		{
			if (this->b1->leftCollision())
			{
				time = 0;
					delete this->b1;
					this->clock.restart();
					
			}
			else if (this->b1->rightCollision())
			{
				time = 0;
					delete this->b1;
					this->clock.restart();
	
			}
		}
		if (onGame)
		{
			this->b1->update();
		}
	}
	else if (time < 2)
	{
		time = time + this->clock.restart().asSeconds();
	}
	
	this->ps1.setString(this->p1->getScore());
	this->ps2.setString(this->p2->getScore());
}

void GameState::render()
{
	this->window->clear();
	this->window->draw(this->ps1);
	this->window->draw(this->ps2);
	this->p1->drawPlayer(*(this->window));
	this->p2->drawPlayer(*(this->window));
	if (onGame)
	{
		this->b1->drawBall(*(this->window));
	}
	this->window->draw(this->lines);
	this->window->display();
}

GameState::~GameState()
{
	delete this->p1;
	delete this->p2;
	if (onGame)
	{
		delete this->b1;
	}
	turn = true;
	onGame = false;
	time = 0;
}
