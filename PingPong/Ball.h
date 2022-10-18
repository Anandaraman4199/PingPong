#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
class Ball
{
private:

	sf::CircleShape ballShape;
	float slope;
	int speed;

	Player* p1;
	Player* p2;

	void findSloap();
	void topCollision();
	void bottomCollision();

	void playerCollision();

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

