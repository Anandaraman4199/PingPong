#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Player.h"

int main()
{
	Game game;
	game.init();
	while(game.isRunning())
	{	
		game.update();
		game.render();
	}
	return 0;
}