#include "Player.h"
#include <string>

float Player::deltaTime = 0;

Player::Player(int id, sf::Vector2f position)
{
	this->score = 0;
	this->id = id;
	this->playerShape.setSize(sf::Vector2f(15.0f, 100.0f));
	this->playerShape.setPosition(position);
	this->playerShape.setOrigin(sf::Vector2f(7.5f, 50.0f));
}

std::string Player::getScore()
{
	return std::to_string(this->score);

}

void Player::addScore()
{
	this->score++;
}

bool Player::topBoundary()
{
	if (this->playerShape.getPosition().y <= 50.0f)
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
	if (this->playerShape.getPosition().y >= 1030.0f)
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
	this->speed = deltaTime * 1000;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))&&(this->id==1)&&(this->topBoundary()))
	{
		this->playerShape.move(0,-(this->speed));
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) && (this->id == 1)&&(this->bottomBoundary()))
	{
		this->playerShape.move(0, this->speed);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) && (this->id == 2) && (this->topBoundary()))
	{
		this->playerShape.move(0, -(this->speed));
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) && (this->id == 2) && (this->bottomBoundary()))
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
