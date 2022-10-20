#include "Game.h"
#include "MainMenu.h"
#include "GameState.h"
#include "Settings.h"
#include "Winner.h"

bool Game::open = true;
int Game::States = 0;
int Game::winner = 0;

float Game::sWidth = sf::VideoMode::getDesktopMode().width;
float Game::sHeight = sf::VideoMode::getDesktopMode().height;

Game::Game()
{
	this->window = new sf::RenderWindow(sf::VideoMode(sWidth,sHeight), "Ping Pong", sf::Style::Fullscreen);
	this->window->setFramerateLimit(60);
	this->window->setMouseCursorVisible(false);
}

void Game::update()
{
	if (States==0)
	{
		MainMenu* menu = new MainMenu(this->window);
		delete menu;
	}
	if (States==1)
	{
		GameState* gState = new GameState(this->window);
		delete gState;
	}
	if (States==2)
	{
		Settings* setting = new Settings(this->window);
		delete setting;
	}
	if (States == 3)
	{
		open = false;
	}
	if (States == 4)
	{
		Winner* winState = new Winner(this->window);
		delete winState;
	}

}
