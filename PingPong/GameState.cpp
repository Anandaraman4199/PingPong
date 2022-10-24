#include "GameState.h"
#include "Ball.h"
#include <iostream>
#include "Game.h"
#include <string>

bool GameState::turn = true;
bool GameState::onGame = false;
float GameState::time = 0;

GameState::GameState(sf::RenderWindow* window)
{
	this->window = window;
	this->font.loadFromFile("gamefont.ttf");

	this->ptw.setFont(this->font);
	this->ptw.setCharacterSize(Game::sWidth/19.2);
	this->ptw.setString("Score "+ (* Game::ini)["GENERAL"]["POINTS"] + " Points to Win");
	this->ptw.setOrigin(sf::Vector2f(this->ptw.getGlobalBounds().width / 2, this->ptw.getGlobalBounds().height));
	this->ptw.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight / 5));

	this->pn1.setFont(this->font);
	this->pn1.setCharacterSize(Game::sWidth / 25.6);
	this->pn1.setString("Player 1");
	this->pn1.setFillColor(sf::Color::Red);
	this->pn1.setPosition(sf::Vector2f(Game::sWidth / 4, Game::sHeight * 2 / 5));
	this->pn1.setOrigin(sf::Vector2f(this->pn1.getGlobalBounds().width/2, this->pn1.getGlobalBounds().height));
	

	this->pn2.setFont(this->font);
	this->pn2.setCharacterSize(Game::sWidth / 25.6);
	this->pn2.setString("Player 2");
	this->pn2.setFillColor(sf::Color::Red);
	this->pn2.setOrigin(sf::Vector2f(this->pn2.getGlobalBounds().width / 2, this->pn2.getGlobalBounds().height));
	this->pn2.setPosition(sf::Vector2f(Game::sWidth*3 / 4, Game::sHeight*2 / 5));
	
	std::string pu1, pu2, pd1, pd2;

	if ((std::stoi(((*Game::ini)["KEYBINDING"]["PLAYER1UP"]), nullptr, 10)) < 128)
	{
		pu1 = std::string(1, (std::stoi(((*Game::ini)["KEYBINDING"]["PLAYER1UP"]), nullptr, 10)));
	}
	else
	{
		switch ((std::stoi(((*Game::ini)["KEYBINDING"]["PLAYER1UP"]), nullptr, 10)))
		{
		case 136: pu1 = "LEFT";
			break;
		case 137: pu1 = "RIGHT";
			break;
		case 138: pu1 = "UP";
			break;
		case 139: pu1 = "DOWN";
			break;
		}
	}

	if ((std::stoi(((*Game::ini)["KEYBINDING"]["PLAYER1DOWN"]), nullptr, 10)) < 128)
	{
		pd1 = std::string(1, (std::stoi(((*Game::ini)["KEYBINDING"]["PLAYER1DOWN"]), nullptr, 10)));
	}
	else
	{
		switch ((std::stoi(((*Game::ini)["KEYBINDING"]["PLAYER1DOWN"]), nullptr, 10)))
		{
		case 136: pd1 = "LEFT";
			break;
		case 137: pd1 = "RIGHT";
			break;
		case 138: pd1 = "UP";
			break;
		case 139: pd1 = "DOWN";
			break;
		}
	}

	if ((std::stoi(((*Game::ini)["KEYBINDING"]["PLAYER2UP"]), nullptr, 10)) < 128)
	{
		pu2 = std::string(1, (std::stoi(((*Game::ini)["KEYBINDING"]["PLAYER2UP"]), nullptr, 10)));
	}
	else
	{
		switch ((std::stoi(((*Game::ini)["KEYBINDING"]["PLAYER2UP"]), nullptr, 10)))
		{
		case 136: pu2 = "LEFT";
			break;
		case 137: pu2 = "RIGHT";
			break;
		case 138: pu2 = "UP";
			break;
		case 139: pu2 = "DOWN";
			break;
		}
	}

	if ((std::stoi(((*Game::ini)["KEYBINDING"]["PLAYER2DOWN"]), nullptr, 10)) < 128)
	{
		pd2 = std::string(1, (std::stoi(((*Game::ini)["KEYBINDING"]["PLAYER2DOWN"]), nullptr, 10)));
	}
	else
	{
		switch ((std::stoi(((*Game::ini)["KEYBINDING"]["PLAYER2DOWN"]), nullptr, 10)))
		{
		case 136: pd2 = "LEFT";
			break;
		case 137: pd2 = "RIGHT";
			break;
		case 138: pd2 = "UP";
			break;
		case 139: pd2 = "DOWN";
			break;
		}
	}

	this->puc1.setFont(this->font);
	this->puc1.setCharacterSize(Game::sWidth / 25.6);
	this->puc1.setString("UP : " + pu1);
	this->puc1.setOrigin(sf::Vector2f(this->puc1.getGlobalBounds().width / 2, this->puc1.getGlobalBounds().height));
	this->puc1.setPosition(sf::Vector2f(Game::sWidth / 4, Game::sHeight *3/ 5));

	this->puc2.setFont(this->font);
	this->puc2.setCharacterSize(Game::sWidth / 25.6);
	this->puc2.setString("UP : "  + pu2);
	this->puc2.setOrigin(sf::Vector2f(this->puc2.getGlobalBounds().width / 2, this->puc2.getGlobalBounds().height));
	this->puc2.setPosition(sf::Vector2f(Game::sWidth * 3 / 4, Game::sHeight*3 / 5));

	this->pd1.setFont(this->font);
	this->pd1.setCharacterSize(Game::sWidth / 25.6);
	this->pd1.setString("DOWN : " + pd1);
	this->pd1.setOrigin(sf::Vector2f(this->pd1.getGlobalBounds().width / 2, this->pd1.getGlobalBounds().height));
	this->pd1.setPosition(sf::Vector2f(Game::sWidth / 4, Game::sHeight*4 / 5));

	this->pd2.setFont(this->font);
	this->pd2.setCharacterSize(Game::sWidth / 25.6);
	this->pd2.setString("DOWN : " + pd2);
	this->pd2.setOrigin(sf::Vector2f(this->pd2.getGlobalBounds().width / 2, this->pd2.getGlobalBounds().height));
	this->pd2.setPosition(sf::Vector2f(Game::sWidth *3/ 4, Game::sHeight*4 / 5));

	do
	{
		this->dE = this->dE + this->clock.restart().asSeconds();

		this->window->clear();



		this->window->draw(this->ptw);
		this->window->draw(this->pn1);
		this->window->draw(this->pn2);
		this->window->draw(this->puc1);
		this->window->draw(this->puc2);
		this->window->draw(this->pd1);
		this->window->draw(this->pd2);
		


		this->window->display();

	} while (this->dE < 3);
	
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
	this->score.setVolume(Game::volume);
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
					this->score.openFromFile("score.wav");
					this->score.play();
					time = 0;
					delete this->b1;
					this->clock.restart();
					
			}
			else if (this->b1->rightCollision())
			{
					this->score.openFromFile("score.wav");
					this->score.play();
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
