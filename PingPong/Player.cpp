#include "Player.h"
#include <string>
#include "Game.h"



float Player::deltaTime = 0;

Player::Player(int id, sf::Vector2f position)
{
	
	this->score = 0;
	this->id = id;
	this->playerShape.setSize(sf::Vector2f(Game::sWidth/192, Game::sHeight/10.8));
	this->playerShape.setPosition(position);
	this->playerShape.setOrigin(sf::Vector2f(this->playerShape.getGlobalBounds().width/2, this->playerShape.getGlobalBounds().height / 2));
}

std::string Player::getScore()
{
	return std::to_string(this->score);

}

void Player::addScore()
{
	this->score++;
	if (this->score == Game::winscore)
	{
		Game::winner = id;
		Game::States = 4;
	}
}

bool Player::topBoundary()
{
	if (this->playerShape.getPosition().y <= this->playerShape.getGlobalBounds().height / 2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Player::bottomBoundary()
{
	if (this->playerShape.getPosition().y >=( (Game::sHeight) - (this->playerShape.getGlobalBounds().height / 2)))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Player::updateMovement()
{
	deltaTime = this->clock.restart().asSeconds();
	this->speed = deltaTime * (Game::sHeight/1.08) ;
	if ((sf::Keyboard::isKeyPressed(*Game::p1up))&&(this->id==1)&&(this->topBoundary()))
	{
		this->playerShape.move(0,-(this->speed));
	}
	if ((sf::Keyboard::isKeyPressed(*Game::p1dwn)) && (this->id == 1)&&(this->bottomBoundary()))
	{
		this->playerShape.move(0, this->speed);
	}
	if ((sf::Keyboard::isKeyPressed(*Game::p2up)) && (this->id == 2) && (this->topBoundary()))
	{
		this->playerShape.move(0, -(this->speed));
	}
	if ((sf::Keyboard::isKeyPressed(*Game::p2dwn)) && (this->id == 2) && (this->bottomBoundary()))
	{
		this->playerShape.move(0, this->speed);
	}
	
}

void Player::update()
{
	this->updateMovement();
}

void Player::drawPlayer(sf::RenderTarget& target)
{
	target.draw(this->playerShape);
}

Player::~Player()
{
	deltaTime = 0;
}
