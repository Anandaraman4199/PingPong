#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "mini/ini.h"

class Game
{
private:
	sf::RenderWindow* window;

	sf::Music music;
	

public:

	static mINI::INIFile* file;
	static mINI::INIStructure* ini;

	static int winscore, volume;
	 

	static sf::Keyboard::Key* p1up;
	static sf::Keyboard::Key* p1dwn;
	static sf::Keyboard::Key* p2up;
	static sf::Keyboard::Key* p2dwn;



	static float sWidth, sHeight;

	static bool open;
	
	static int States, winner;

	Game();
	void update();


};