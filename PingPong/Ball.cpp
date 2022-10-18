#include "Ball.h"
#include "Game.h"
#include "Player.h"
#include <ctime>
#include <iostream>
#include <cstdlib>

Ball::Ball(sf::Vector2f position, Player* p1, Player* p2)
{
	this->ballShape.setRadius(8);
	this->ballShape.setPointCount(10);
	this->ballShape.setPosition(position);
	this->findSloap();
	this->p1 = p1;
	this->p2 = p2;
}

void Ball::findSloap()
{
	srand(static_cast<unsigned int>(time(0)));
	float random = rand() % 2001;
	this->slope = (random - 1000) / 1000;
	this->speed = 500;

}

void Ball::randomSpeed()
{
	srand(static_cast<unsigned int>(time(0)));
	float random = rand() % 300;
	this->speed = 500 + random;

}

sf::Vector2f Ball::nextPosition()
{
	this->randomSpeed();
	sf::Vector2f next;
	if (Game::turn)
	{
		next.y = ((this->slope) * (Player::deltaTime*speed));
	}
	else
	{
		next.y = ((this->slope) * (Player::deltaTime * -speed));
	}
	next.x = (next.y) / (this->slope);
	//std::cout << "\t X: " << next.x << "\t Y: "<<next.y << "\n";
	return next;

}

void Ball::update()
{
	
	this->topCollision();
	this->bottomCollision();
	this->playerCollision();
	this->ballShape.move(this->nextPosition());

}

void Ball::topCollision()
{
	if (this->ballShape.getPosition().y <= 8)
	{
		this->slope = -(this->slope);
		

	}

}

void Ball::bottomCollision()
{
	if (this->ballShape.getPosition().y >= 1072)
	{
		this->slope = -(this->slope);
		
	}

}

bool Ball::leftCollision()
{
	if (this->ballShape.getPosition().x <= 8)
	{
		Game::turn = false;
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
	if (this->ballShape.getPosition().x >= 1912)
	{	
		Game::turn = true;
		this->p1->addScore();
		return true;
	}
	else
	{
		return false;
	}

}

void Ball::playerCollision()
{
	if ((abs(this->ballShape.getPosition().x - this->p1->playerShape.getPosition().x) - (this->ballShape.getRadius() + (this->p1->playerShape.getSize().x / 2)))<=-10)
	{
		if ((abs(this->ballShape.getPosition().y - this->p1->playerShape.getPosition().y) - (this->ballShape.getRadius() + (this->p1->playerShape.getSize().y / 2))) <= 0)
		{
			this->slope = (this->ballShape.getPosition().y-this->p1->playerShape.getPosition().y) / 25;
			Game::turn = true;
		}
		
	}
	if ((abs(this->ballShape.getPosition().x - this->p2->playerShape.getPosition().x) - (this->ballShape.getRadius() + (this->p2->playerShape.getSize().x / 2))) <= -5)
	{
		if ((abs(this->ballShape.getPosition().y - this->p2->playerShape.getPosition().y) - (this->ballShape.getRadius() + (this->p2->playerShape.getSize().y / 2))) <= 0)
		{
			this->slope = (this->p2->playerShape.getPosition().y - this->ballShape.getPosition().y) / 25;
			Game::turn = false;
		}
		
	}
}

void Ball::drawBall(sf::RenderTarget& target)
{	
	
	target.draw(this->ballShape);
}

Ball::~Ball ()
{
	Game::onGame = false;
}

