#include "Ball.h"
#include "GameState.h"
#include "Player.h"
#include "Game.h"
#include <ctime>
#include <iostream>
#include <cstdlib>


Ball::Ball(sf::Vector2f position, Player* p1, Player* p2)
{
	if (this->pCollision.loadFromFile("playerCollision.wav"))
	{
		std::cout << "loaded";
	}
	this->ballShape.setRadius(Game::sWidth/240);
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
	this->playerCollision();
	this->ballShape.move(this->nextPosition());

}

void Ball::topCollision()
{
	if (this->ballShape.getPosition().y <= this->ballShape.getRadius())
	{
		this->slope = -(this->slope);
		

	}

}

void Ball::bottomCollision()
{
	if (this->ballShape.getPosition().y >= (Game::sHeight - this->ballShape.getRadius()))
	{
		this->slope = -(this->slope);
		
	}

}

bool Ball::leftCollision()
{
	if (this->ballShape.getPosition().x <= this->ballShape.getRadius())
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
	if (this->ballShape.getPosition().x >= (Game::sWidth - this->ballShape.getRadius()))
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

void Ball::playerCollision()
{
	if ((abs(this->ballShape.getPosition().x - this->p1->playerShape.getPosition().x) - (this->ballShape.getRadius() + (this->p1->playerShape.getSize().x / 2)))<=0)
	{
		if ((abs(this->ballShape.getPosition().y - this->p1->playerShape.getPosition().y) - (this->ballShape.getRadius() + (this->p1->playerShape.getSize().y / 2))) <= 0)
		{
			sf::Sound sound;
			sound.setBuffer(this->pCollision);
			sound.setVolume(100);
			sound.play();
			this->slope = (this->ballShape.getPosition().y-this->p1->playerShape.getPosition().y) / (this->p1->playerShape.getSize().y/4);
			GameState::turn = true;
		}
		
	}
	if ((abs(this->ballShape.getPosition().x - this->p2->playerShape.getPosition().x) - (this->ballShape.getRadius() + (this->p2->playerShape.getSize().x / 2))) - this->p2->playerShape.getSize().x <= 0)
	{
		if ((abs(this->ballShape.getPosition().y - this->p2->playerShape.getPosition().y) - (this->ballShape.getRadius() + (this->p2->playerShape.getSize().y / 2))) <= 0)
		{
			this->slope = (this->p2->playerShape.getPosition().y - this->ballShape.getPosition().y) / (this->p1->playerShape.getSize().y / 4);
			GameState::turn = false;
			sf::Sound sound;
			sound.setBuffer(this->pCollision);
			sound.setVolume(100);
			sound.play();
		}
		
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

