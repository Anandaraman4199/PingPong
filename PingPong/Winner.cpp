#include "Winner.h"

Winner::Winner(sf::RenderWindow* window)
{
	this->window = window;
	this->font.loadFromFile("gamefont.ttf");
	this->wAnnouce.setFont(this->font);
	this->pAgain.setFont(this->font);
	this->Yes.setFont(this->font);
	this->No.setFont(this->font);
	this->wAnnouce.setCharacterSize(Game::sWidth / 19.2);
	this->pAgain.setCharacterSize(Game::sWidth / 38.4);
	this->Yes.setCharacterSize(Game::sWidth / 38.4);
	this->No.setCharacterSize(Game::sWidth / 38.4);
	if (Game::winner == 1)
	{
		this->wAnnouce.setString("Player 1 won the Game");
	}
	else if (Game::winner == 2)
	{
		this->wAnnouce.setString("Player 2 won the Game");
	}
	this->pAgain.setString("Do you want to play again?");
	this->Yes.setString("Yes");
	this->No.setString("No");
	this->wAnnouce.setPosition(Game::sWidth / 2, Game::sHeight / 6);
	this->pAgain.setPosition(Game::sWidth / 2, Game::sHeight / 3);
	this->Yes.setPosition(Game::sWidth * 3 / 8, Game::sHeight*2 / 3);
	this->No.setPosition(Game::sWidth * 5 / 8, Game::sHeight*2 / 3);
	this->wAnnouce.setOrigin(sf::Vector2f(this->wAnnouce.getGlobalBounds().width / 2, this->wAnnouce.getGlobalBounds().height / 2));
	this->pAgain.setOrigin(sf::Vector2f(this->pAgain.getGlobalBounds().width / 2, this->pAgain.getGlobalBounds().height / 2));
	this->Yes.setOrigin(sf::Vector2f(this->Yes.getGlobalBounds().width / 2, this->Yes.getGlobalBounds().height / 2));
	this->No.setOrigin(sf::Vector2f(this->No.getGlobalBounds().width / 2, this->No.getGlobalBounds().height / 2));


	while (Game::States == 4)
	{
		this->update();
		this->render();
	}
}

void Winner::getInput()
{
  
	while (this->window->pollEvent(this->evnt))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			this->choice++;
			if (this->choice >= 2)
			{
				this->choice = 0;
			}
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			this->choice--;
			if (this->choice <= -1)
			{
				this->choice = 1;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
		{
			Game::winner = 0;
			Game::States = this->choice;
		}
	}
	

}

void Winner::update()
{
	this->Yes.setFillColor(sf::Color::White);
	this->No.setFillColor(sf::Color::White);
	this->getInput();
	switch (this->choice)
	{
	case 0:this->No.setFillColor(sf::Color::Red);
		break;

	case 1: 	this->Yes.setFillColor(sf::Color::Red);
		break;

	}
}

void Winner::render()
{
	this->window->clear();
	this->window->draw(this->wAnnouce);
	this->window->draw(this->pAgain);
	this->window->draw(this->Yes);
	this->window->draw(this->No);
	this->window->display();
}
