#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GameState.h"

class Winner
{
private:
	sf::RenderWindow* window;

	sf::Font font;

	sf::Event evnt;

	sf::Text wAnnouce;
	sf::Text pAgain;
	sf::Text Yes;
	sf::Text No;

	int choice=1;

	void update();
	void render();

	void getInput();

public:

	Winner(sf::RenderWindow* window);

};

