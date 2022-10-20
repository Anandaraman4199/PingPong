#include "MainMenu.h"
#include <iostream>
#include "Game.h"

MainMenu::MainMenu(sf::RenderWindow* window)
{
	this->window = window;
	this->font.loadFromFile("gamefont.ttf");
	this->Gamename.setFont(this->font);
	this->Play.setFont(this->font);
	this->Settings.setFont(this->font);
	this->Quit.setFont(this->font);
	this->Gamename.setCharacterSize(Game::sWidth/19.2);
	this->Play.setCharacterSize(Game::sWidth / 38.4);
	this->Settings.setCharacterSize(Game::sWidth / 38.4);
	this->Quit.setCharacterSize(Game::sWidth / 38.4);
	this->Gamename.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight / 4));
	this->Play.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight / 2));
	this->Settings.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight * 5 / 8));
	this->Quit.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight * 6 / 8));
	this->Gamename.setString("Ping Pong");
	this->Play.setString("Play");
	this->Settings.setString("Settings");
	this->Quit.setString("Quit");
	this->Gamename.setOrigin(sf::Vector2f(this->Gamename.getGlobalBounds().width/2, this->Gamename.getGlobalBounds().height / 2));
	this->Play.setOrigin(sf::Vector2f(this->Play.getGlobalBounds().width / 2, this->Play.getGlobalBounds().height / 2));
	this->Settings.setOrigin(sf::Vector2f(this->Settings.getGlobalBounds().width / 2, this->Settings.getGlobalBounds().height / 2));
	this->Quit.setOrigin(sf::Vector2f(this->Quit.getGlobalBounds().width / 2, this->Quit.getGlobalBounds().height / 2));
	while (Game::States==0)
	{
		this->Mupdate();
		this->Mrender();
	}

}

void MainMenu::getInput()
{
	while (this->window->pollEvent(this->evnt))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			this->mOption--;
			if (mOption < 1)
			{
				this->mOption = 3;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			this->mOption++;
			if (mOption > 3)
			{
				this->mOption = 1;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
		{
			Game::States = mOption;
		}
	}
}

void MainMenu::Mupdate()
{
	this ->Gamename.setFillColor(sf::Color::White);
	this->Play.setFillColor(sf::Color::White);
	this->Settings.setFillColor(sf::Color::White);
	this->Quit.setFillColor(sf::Color::White);
	this->getInput();
	switch (this->mOption)
	{
	case 1: this->Play.setFillColor(sf::Color::Red);
		break;
	case 2: this->Settings.setFillColor(sf::Color::Red);
		break;

	case 3: this->Quit.setFillColor(sf::Color::Red);
		break;

	default:break;
	}
}

void MainMenu::Mrender()
{
	
	this->window->clear();
	this->window->draw(this->Gamename);
	this->window->draw(this->Play);
	this->window->draw(this->Settings);
	this->window->draw(this->Quit);
	this->window->display();
}
