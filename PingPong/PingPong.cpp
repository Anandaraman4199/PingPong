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






















/*int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Ping Pong", sf::Style::Fullscreen);
	GameState game(&gameWindow);
	while (game.isRunning())
	{
		game.update();
		game.render();
	}
	return 0;

}

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
}*/