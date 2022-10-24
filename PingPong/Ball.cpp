#include "Ball.h"
#include "GameState.h"
#include "Player.h"
#include "Game.h"
#include <ctime>
#include <iostream>
#include <cstdlib>


Ball::Ball(sf::Vector2f position, Player* p1, Player* p2)
{
	
	this->ballShape.setRadius(Game::sWidth/240);
	this->ballShape.setPointCount(10);
	this->ballShape.setPosition(position);
	this->findSloap();
	this->p1 = p1;
	this->p2 = p2;
	this->pCollision.setVolume(Game::volume);
}

void Ball::findSloap()
{
	srand(static_cast<unsigned int>(time(0)));
	float random = rand() % 2001;
	this->slope = (random - 1000) / 1000;
	this->speed = Game::sWidth/4.32;

}

void Ball::randomSpeed()
{
	srand(static_cast<unsigned int>(time(0)));
	float random = rand() % 300;
	this->speed = Game::sWidth / 4.32 + random;

}

sf::Vector2f Ball::nextPosition()
{
	this->randomSpeed();
	sf::Vector2f next;
	if (GameState::turn)
	{
		next.y = ((this->slope) * (Player::deltaTime* this->speed));
	}
	else
	{
		next.y = ((this->slope) * (Player::deltaTime * -(this->speed)));
	}
	next.x = (next.y) / (this->slope);
	//std::cout << "\t X: " << next.x << "\t Y: "<<next.y << "\n";
	return next;

}

void Ball::update()
{
	
	this->topCollision();
	this->bottomCollision();
	if (this->playerCollision())
	{
		this->pCollision.openFromFile("playerCollision.wav");
		this->pCollision.play();
	}
	this->ballShape.move(this->nextPosition());

}

void Ball::topCollision()
{
	this->dE = this->dE + this->clock.restart().asSeconds();

	if (((abs((Game::sHeight-Game::sHeight)-this->ballShape.getPosition().y))-this->ballShape.getRadius())<1)
	{
		if (this->dE > 0.1)
		{
			this->slope = -(this->slope);
			this->pCollision.openFromFile("playerCollision.wav");
			this->pCollision.play();
			this->dE = 0;
		}
	}

}

void Ball::bottomCollision()
{

	this->dE = this->dE + this->clock.restart().asSeconds();

	if (((abs(Game::sHeight - this->ballShape.getPosition().y)) - this->ballShape.getRadius()) < 1)
	{
		if (this->dE > 0.1)
		{
			this->slope = -(this->slope);
			this->pCollision.openFromFile("playerCollision.wav");
			this->pCollision.play();
			this->dE = 0;
		}

	}

}

bool Ball::leftCollision()
{
	if (((abs((Game::sWidth - Game::sWidth) - this->ballShape.getPosition().x)) - this->ballShape.getRadius()) < 1)
	{
		GameState::turn = false;
		this->p2->addScore();
		
		return true;
	}
	else
	{
		return false;
	}
}

bool Ball::rightCollision()
{
	if (((abs(Game::sWidth - this->ballShape.getPosition().x)) - this->ballShape.getRadius()) < 1)
	{	
		GameState::turn = true;
		this->p1->addScore();
		
		return true;
	}
	else
	{
		return false;
	}

}

bool Ball::playerCollision()
{
	if ((abs(this->ballShape.getPosition().x - this->p1->playerShape.getPosition().x) - (this->ballShape.getRadius() + (this->p1->playerShape.getSize().x / 2)))<=-5)
	{
		if ((abs(this->ballShape.getPosition().y - this->p1->playerShape.getPosition().y) - (this->ballShape.getRadius() + (this->p1->playerShape.getSize().y / 2))) <= 0)
		{
			
			this->slope = (this->ballShape.getPosition().y-this->p1->playerShape.getPosition().y) / (this->p1->playerShape.getSize().y/4);
			GameState::turn = true;
			return true;
		}
		else
		{
			return false;
		}
		
	}
	else if ((abs(this->ballShape.getPosition().x - this->p2->playerShape.getPosition().x) - (this->ballShape.getRadius() + (this->p2->playerShape.getSize().x / 2))) - this->p2->playerShape.getSize().x <= 0)
	{
		if ((abs(this->ballShape.getPosition().y - this->p2->playerShape.getPosition().y) - (this->ballShape.getRadius() + (this->p2->playerShape.getSize().y / 2))) <= 0)
		{
			this->slope = (this->p2->playerShape.getPosition().y - this->ballShape.getPosition().y) / (this->p1->playerShape.getSize().y / 4);
			GameState::turn = false;
			return true;
		}
		else
		{
			return false;
		}
		
	}
	else
	{
		return false;
	}
}

void Ball::drawBall(sf::RenderTarget& target)
{	
	
	target.draw(this->ballShape);
}

Ball::~Ball ()
{
	GameState::onGame = false;
}

