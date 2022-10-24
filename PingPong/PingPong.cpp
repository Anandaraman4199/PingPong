#include <SFML/Graphics.hpp>
#include <iostream>
#include <sfml/System.hpp>
#include "GameState.h"
#include "Player.h"
#include "Game.h"

int main()
{
	Game game;
	while (Game::open)
	{
		game.update();
	}
	return 0;
}