#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Settings.h"
#include <SFML/Audio.hpp>



class Player
{
private:
	
	int score;
	int id;

	

	sf::Clock clock;
	float speed;

	void updateMovement();
	bool topBoundary();
	bool bottomBoundary();

public:

	sf::RectangleShape playerShape;

	static float deltaTime;

	Player(int id,sf::Vector2f position);

	std::string getScore();
	void update();
	void addScore();
	void drawPlayer(sf::RenderTarget& target);

	~Player();
};

