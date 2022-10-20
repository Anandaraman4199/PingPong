#pragma once
#include <SFML/Graphics.hpp>

class MainMenu
{
private:
	
	sf::RenderWindow* window;
	sf::Font font;
	sf::Text Gamename, Play, Settings, Quit;
	sf::Event evnt;

	int mOption = 1;

	void Mupdate();
	void Mrender();
	void getInput();

public:

	MainMenu(sf::RenderWindow* window);

};

