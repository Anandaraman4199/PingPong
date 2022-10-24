#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
class Ball
{
private:

	sf::CircleShape ballShape;
	float slope;
	int speed;

	sf::Music pCollision;

	Player* p1;
	Player* p2;
	
	sf::Clock clock;

	float dE;

	void findSloap();
	void topCollision();
	void bottomCollision();

	bool playerCollision();

	void randomSpeed();

	sf::Vector2f nextPosition();



public:

	
	bool alive=true;

	bool leftCollision();
	bool rightCollision();

	Ball(sf::Vector2f position, Player* p1, Player* p2);
	~Ball();
	void update();
	void drawBall(sf::RenderTarget& target);
};

