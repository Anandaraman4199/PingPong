#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event evnt;
	sf::Font font;
	sf::Text ps1,ps2;

	

	Player* p1;
	Player* p2;

	Ball* b1;

	void pollEvent();
	int winner = 0;

	

public:

	static bool onGame, turn;
	bool isRunning();
	void init();
	void update();
	void render();
};

