#include "Game.h"
#include "MainMenu.h"
#include "GameState.h"
#include "Settings.h"
#include "Winner.h"
#include <string>


bool Game::open = true;
int Game::States = 0;
int Game::winner = 0;

float Game::sWidth = sf::VideoMode::getDesktopMode().width;
float Game::sHeight = sf::VideoMode::getDesktopMode().height;

mINI::INIFile* Game::file = nullptr;
mINI::INIStructure* Game::ini = nullptr;

int Game::winscore = 0;
int Game::volume = 0;

sf::Keyboard::Key* Game::p1up=nullptr;
sf::Keyboard::Key* Game::p1dwn=nullptr;
sf::Keyboard::Key* Game::p2up=nullptr;
sf::Keyboard::Key* Game::p2dwn=nullptr;


Game::Game()
{
	this->music.setVolume(volume);
	this->window = new sf::RenderWindow(sf::VideoMode(sWidth,sHeight), "Ping Pong", sf::Style::Fullscreen);
	file = new mINI::INIFile("settings.ini");
	ini = new mINI::INIStructure();
	file->read(*ini);
	winscore = std::stoi((*ini)["GENERAL"]["POINTS"],nullptr,10);
	volume = std::stoi((*ini)["GENERAL"]["VOLUME"], nullptr, 10);
	p1up = new sf::Keyboard::Key;
	p1dwn = new sf::Keyboard::Key;
	p2up = new sf::Keyboard::Key;
	p2dwn = new sf::Keyboard::Key;

	*p1up = (sf::Keyboard::Key)((std::stoi(((*ini)["KEYBINDING"]["PLAYER1UP"]), nullptr, 10)) - 65);
	*p1dwn = (sf::Keyboard::Key)((std::stoi(((*ini)["KEYBINDING"]["PLAYER1DOWN"]), nullptr, 10)) - 65);
	*p2up = (sf::Keyboard::Key)((std::stoi(((*ini)["KEYBINDING"]["PLAYER2UP"]), nullptr, 10)) - 65);
	*p2dwn = (sf::Keyboard::Key)((std::stoi(((*ini)["KEYBINDING"]["PLAYER2DOWN"]), nullptr, 10)) - 65);

	this->window->setMouseCursorVisible(false);
	this->window->setMouseCursorGrabbed(true);

}

void Game::update()
{
	if (States==0)
	{
		this->music.openFromFile("playerCollision.wav");
		this->music.play();
		MainMenu* menu = new MainMenu(this->window);
		delete menu;
	}
	if (States==1)
	{
		this->music.openFromFile("playerCollision.wav");
		this->music.play();
		GameState* gState = new GameState(this->window);
		delete gState;
	}
	if (States==2)
	{
		this->music.openFromFile("playerCollision.wav");
		this->music.play();
		Settings* setting = new Settings(this->window);
		delete setting;
	}
	if (States == 3)
	{	
		this->music.openFromFile("playerCollision.wav");
		this->music.play();
		open = false;
	}
	if (States == 4)
	{
		Winner* winState = new Winner(this->window);
		delete winState;
	}

}
