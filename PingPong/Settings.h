#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> 
#include <SFML/Audio.hpp>

class Settings
{
private:

	sf::RenderWindow* window;

	sf::Music oMusic;

	sf::Font font;

	sf::Text setting, volume, controls, p1, p1up, p1dwn, p2, p2up, p2dwn, winscore;

	sf::Text vc, p1uc, p1dc, p2uc, p2dc, wc;

	sf::Text vv, p1uv, p1dv, p2uv, p2dv, wv;

	sf::Clock clock;

	float dE;

	bool keyChange;

	void update();
	
	void keyUpdate();

	void render();

	void getInput();

	int sOption = 0;

public:


	Settings(sf::RenderWindow* window);



};

