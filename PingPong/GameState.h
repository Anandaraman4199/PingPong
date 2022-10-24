#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"

class GameState
{
private:
	sf::RenderWindow* window;
	sf::Event evnt;
	sf::Font font;
	sf::Text ps1,ps2,puc1,puc2,pd1,pd2,ptw,pn1,pn2;
	sf::VertexArray lines;

	float dE;


	sf::Music score;

	sf::Clock clock;
	
	static float time;

	Player* p1;
	Player* p2;

	Ball* b1;

	void pollEvent();
	

	
	

public:

	static bool onGame, turn;
	
	GameState(sf::RenderWindow* window);

	void update();
	void render();

	~GameState();
};

