#pragma once
#include <SFML/Graphics.hpp>
class Settings
{
private:
	sf::RenderWindow* window;
public:
	Settings(sf::RenderWindow* window);
	static int WINSCORE;
};

