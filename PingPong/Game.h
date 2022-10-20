#pragma once
#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::RenderWindow* window;

	

public:

	static float sWidth, sHeight;

	static bool open;
	
	static int States, winner;

	Game();
	void update();


};