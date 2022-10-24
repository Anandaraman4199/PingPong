#include "Settings.h"
#include <iostream>
#include "Game.h"
#include <string.h>
#include <cctype>



Settings::Settings(sf::RenderWindow* window)
{
	this->font.loadFromFile("gamefont.ttf");


	this->setting.setFont(this->font);
	this->volume.setFont(this->font);
	this->controls.setFont(this->font);
	this->p1.setFont(this->font);
	this->p1up.setFont(this->font);
	this->p1dwn.setFont(this->font);
	this->p2up.setFont(this->font);
	this->p2dwn.setFont(this->font);
	this->winscore.setFont(this->font);
	this->vc.setFont(this->font);
	this->vv.setFont(this->font);
	this->p1uc.setFont(this->font);
	this->p1uv.setFont(this->font);
	this->p1dc.setFont(this->font);
	this->p1dv.setFont(this->font);
	this->p2uc.setFont(this->font);
	this->p2uv.setFont(this->font);
	this->p2dc.setFont(this->font);
	this->p2dv.setFont(this->font);
	this->wc.setFont(this->font);
	this->wv.setFont(this->font);
	this->p2.setFont(this->font);


	this->setting.setCharacterSize(Game::sWidth / 19.2);
	this->volume.setCharacterSize(Game::sWidth / 38.4);
	this->controls.setCharacterSize(Game::sWidth / 38.4);
	this->p1.setCharacterSize(Game::sWidth / 38.4);
	this->p1up.setCharacterSize(Game::sWidth / 38.4);
	this->p1dwn.setCharacterSize(Game::sWidth / 38.4);
	this->p2up.setCharacterSize(Game::sWidth / 38.4);
	this->p2dwn.setCharacterSize(Game::sWidth / 38.4);
	this->winscore.setCharacterSize(Game::sWidth / 38.4);
	this->vc.setCharacterSize(Game::sWidth / 38.4);
	this->vv.setCharacterSize(Game::sWidth / 38.4);
	this->p1uc.setCharacterSize(Game::sWidth / 38.4);
	this->p1uv.setCharacterSize(Game::sWidth / 38.4);
	this->p1dc.setCharacterSize(Game::sWidth / 38.4);
	this->p1dv.setCharacterSize(Game::sWidth / 38.4);
	this->p2uc.setCharacterSize(Game::sWidth / 38.4);
	this->p2uv.setCharacterSize(Game::sWidth / 38.4);
	this->p2dc.setCharacterSize(Game::sWidth / 38.4);
	this->p2dv.setCharacterSize(Game::sWidth / 38.4);
	this->wc.setCharacterSize(Game::sWidth / 38.4);
	this->wv.setCharacterSize(Game::sWidth / 38.4);
	this->p2.setCharacterSize(Game::sWidth / 38.4);

	this->setting.setPosition(sf::Vector2f(Game::sWidth/2,Game::sHeight / 14));
	this->winscore.setPosition(sf::Vector2f(Game::sWidth / 4, Game::sHeight * 3 / 14));
	this->wc.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight * 3 / 14));
	this->wv.setPosition(sf::Vector2f(Game::sWidth * 3 / 4, Game::sHeight * 3 / 14));
	this->volume.setPosition(sf::Vector2f(Game::sWidth / 4, Game::sHeight * 4 / 14));
	this->vc.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight *4/14));
	this->vv.setPosition(sf::Vector2f(Game::sWidth *3/ 4, Game::sHeight *4/ 14));
	this->controls.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight * 6 / 14));
	this->p1.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight * 7 / 14));
	this->p1up.setPosition(sf::Vector2f(Game::sWidth / 4, Game::sHeight * 8 / 14));
	this->p1uc.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight *8/14));
	this->p1uv.setPosition(sf::Vector2f(Game::sWidth*3 / 4, Game::sHeight *8/14));
	this->p1dwn.setPosition(sf::Vector2f(Game::sWidth / 4, Game::sHeight * 9 / 14));
	this->p1dc.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight *9/ 14));
	this->p1dv.setPosition(sf::Vector2f(Game::sWidth*3 / 4, Game::sHeight *9/ 14));
	this->p2.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight * 10 / 14));
	this->p2up.setPosition(sf::Vector2f(Game::sWidth / 4, Game::sHeight * 11 / 14));
	this->p2uc.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight *11/ 14));
	this->p2uv.setPosition(sf::Vector2f(Game::sWidth *3/ 4, Game::sHeight *11/ 14));
	this->p2dwn.setPosition(sf::Vector2f(Game::sWidth / 4, Game::sHeight * 12 / 14));
	this->p2dc.setPosition(sf::Vector2f(Game::sWidth / 2, Game::sHeight *12/ 14));
	this->p2dv.setPosition(sf::Vector2f(Game::sWidth *3/ 4, Game::sHeight *12/ 14));
	

	this->setting.setString("Settings");
	this->volume.setString("Volume");
	this->controls.setString("Controls");
	this->p1.setString("Player 1");
	this->p1up.setString("UP");
	this->p1dwn.setString("DOWN");
	this->p2up.setString("UP");
	this->p2dwn.setString("DOWN");
	this->winscore.setString("SCORE TO WIN");
	this->vc.setString(":");
	this->vv.setString(std::to_string(Game::volume));
	this->p1uc.setString(":");
	
	this->p1dc.setString(":");
	
	this->p2uc.setString(":");
	
	this->p2dc.setString(":");
	
	this->wc.setString(":");
	this->wv.setString(std::to_string(Game::winscore));
	this->p2.setString("Player 2");
	
	this->keyUpdate();
	


	this->setting.setOrigin(this->setting.getGlobalBounds().width/2, this->setting.getGlobalBounds().height / 2);
	this->winscore.setOrigin(this->winscore.getGlobalBounds().width / 2, this->winscore.getGlobalBounds().height / 2);
	this->wc.setOrigin(this->wc.getGlobalBounds().width / 2, this->wc.getGlobalBounds().height);
	this->wv.setOrigin(this->wv.getGlobalBounds().width / 2, this->wv.getGlobalBounds().height / 2);
	this->volume.setOrigin(this->volume.getGlobalBounds().width / 2, this->volume.getGlobalBounds().height / 2);
	this->vc.setOrigin(this->vc.getGlobalBounds().width / 2, this->vc.getGlobalBounds().height );
	this->vv.setOrigin(this->vv.getGlobalBounds().width / 2, this->vv.getGlobalBounds().height / 2);
	this->controls.setOrigin(this->controls.getGlobalBounds().width / 2, this->controls.getGlobalBounds().height / 2);
	this->p1.setOrigin(this->p1.getGlobalBounds().width / 2, this->p1.getGlobalBounds().height / 2);
	this->p1up.setOrigin(this->p1up.getGlobalBounds().width / 2, this->p1up.getGlobalBounds().height / 2);
	this->p1uc.setOrigin(this->p1uc.getGlobalBounds().width / 2, this->p1uc.getGlobalBounds().height);
	
	this->p1dwn.setOrigin(this->p1dwn.getGlobalBounds().width / 2, this->p1dwn.getGlobalBounds().height / 2);
	this->p1dc.setOrigin(this->p1dc.getGlobalBounds().width / 2, this->p1dc.getGlobalBounds().height);
	
	this->p2up.setOrigin(this->p2up.getGlobalBounds().width / 2, this->p2up.getGlobalBounds().height / 2);
	this->p2uc.setOrigin(this->p2uc.getGlobalBounds().width / 2, this->p2uc.getGlobalBounds().height);
	
	this->p2dwn.setOrigin(this->p2dwn.getGlobalBounds().width / 2, this->p2dwn.getGlobalBounds().height / 2);
	this->p2dc.setOrigin(this->p2dc.getGlobalBounds().width / 2, this->p2dc.getGlobalBounds().height);
	
	this->p2.setOrigin(this->p2.getGlobalBounds().width / 2, this->p2.getGlobalBounds().height / 2);

	this->p1uv.setOrigin(this->p1uv.getGlobalBounds().width / 2, this->p1uv.getGlobalBounds().height / 2);
	this->p1dv.setOrigin(this->p1dv.getGlobalBounds().width / 2, this->p1dv.getGlobalBounds().height / 2);
	this->p2uv.setOrigin(this->p2uv.getGlobalBounds().width / 2, this->p2uv.getGlobalBounds().height / 2);
	this->p2dv.setOrigin(this->p2dv.getGlobalBounds().width / 2, this->p2dv.getGlobalBounds().height / 2);

	
	this->oMusic.setVolume(Game::volume);

	this->window = window;
	while (Game::States == 2)
	{
		this->update();
		this->render();

	}
}

void Settings::keyUpdate()
{
	if (((int)(*Game::p1up)) + 65 < 128)
	{
		this->p1uv.setString(char(((int)(*Game::p1up)) + 65));
	}
	else
	{
		switch (((int)(*Game::p1up)) + 65)
		{
		case 136:this->p1uv.setString("LEFT");
			break;
		case 137:this->p1uv.setString("RIGHT");
			break;
		case 138:this->p1uv.setString("UP");
			break;
		case 139:this->p1uv.setString("DOWN");
			break;
		}
	}
	if (((int)(*Game::p1dwn)) + 65 < 128)
	{
		this->p1dv.setString(char(((int)(*Game::p1dwn)) + 65));
	}
	else
	{
		switch (((int)(*Game::p1dwn)) + 65)
		{
		case 136:this->p1dv.setString("LEFT");
			break;
		case 137:this->p1dv.setString("RIGHT");
			break;
		case 138:this->p1dv.setString("UP");
			break;
		case 139:this->p1dv.setString("DOWN");
			break;
		}
	}
	if (((int)(*Game::p2up)) + 65 < 128)
	{
		this->p2uv.setString(char(((int)(*Game::p2up)) + 65));
	}
	else
	{
		switch (((int)(*Game::p2up)) + 65)
		{
		case 136:this->p2uv.setString("LEFT");
			break;
		case 137:this->p2uv.setString("RIGHT");
			break;
		case 138:this->p2uv.setString("UP");
			break;
		case 139:this->p2uv.setString("DOWN");
			break;
		}
	}
	if (((int)(*Game::p2dwn)) + 65 < 128)
	{
		this->p2dv.setString(char(((int)(*Game::p2dwn)) + 65));
	}
	else
	{
		switch (((int)(*Game::p2dwn)) + 65)
		{
		case 136:this->p2dv.setString("LEFT");
			break;
		case 137:this->p2dv.setString("RIGHT");
			break;
		case 138:this->p2dv.setString("UP");
			break;
		case 139:this->p2dv.setString("DOWN");
			break;
		}
	}
	this->p1uv.setOrigin(this->p1uv.getGlobalBounds().width / 2, this->p1uv.getGlobalBounds().height / 2);
	this->p1dv.setOrigin(this->p1dv.getGlobalBounds().width / 2, this->p1dv.getGlobalBounds().height / 2);
	this->p2uv.setOrigin(this->p2uv.getGlobalBounds().width / 2, this->p2uv.getGlobalBounds().height / 2);
	this->p2dv.setOrigin(this->p2dv.getGlobalBounds().width / 2, this->p2dv.getGlobalBounds().height / 2);
}

void Settings::getInput()
{
	this->dE = dE + this->clock.restart().asSeconds();
	sf::Event evnt;
	while (this->window->pollEvent(evnt))
	{
	
		if (evnt.type == sf::Event::TextEntered)
		{
			if (this->keyChange)
			{
				if (evnt.text.unicode < 128)
				{
					char c = char(evnt.text.unicode);
					c = std::toupper(c);

					switch (this->sOption)
					{
					case 2:(*Game::ini)["KEYBINDING"]["PLAYER1UP"] = std::to_string(int(c));
						*Game::p1up = (sf::Keyboard::Key)(int(c) - 65);
						break;
					case 3:(*Game::ini)["KEYBINDING"]["PLAYER1DOWN"] = std::to_string(int(c));
						*Game::p1dwn = (sf::Keyboard::Key)(int(c) - 65);
						break;
					case 4:(*Game::ini)["KEYBINDING"]["PLAYER2UP"] = std::to_string(int(c));
						*Game::p2up = (sf::Keyboard::Key)(int(c) - 65);
						break;
					case 5:(*Game::ini)["KEYBINDING"]["PLAYER2DOWN"] = std::to_string(int(c));
						*Game::p2dwn = (sf::Keyboard::Key)(int(c) - 65);
						break;
					}
					Game::file->write(*Game::ini);
					this->keyChange = false;

				}

			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			if (this->dE > 0.1)
			{
				this->dE = 0;
				if (this->keyChange)
				{
					this->keyChange = false;
				}
				else
				{
					Game::States = 0;
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			this->oMusic.openFromFile("playerCollision.wav");
			this->oMusic.play();
			if (this->keyChange)
			{
				switch (this->sOption)
				{
				case 2:(*Game::ini)["KEYBINDING"]["PLAYER1UP"] = "138";
					*Game::p1up = sf::Keyboard::Up; 
					break;
				case 3:(*Game::ini)["KEYBINDING"]["PLAYER1DOWN"] = "138";
					*Game::p1dwn = sf::Keyboard::Up;
					break;
				case 4:(*Game::ini)["KEYBINDING"]["PLAYER2UP"] = "138";
					*Game::p2up = sf::Keyboard::Up;
					break;
				case 5:(*Game::ini)["KEYBINDING"]["PLAYER2DOWN"] = "138";
					*Game::p2dwn = sf::Keyboard::Up;
					break;
				}
				this->keyChange = false;
				Game::file->write(*Game::ini);
			}
			else
			{
				this->sOption--;
				if (this->sOption < 0)
				{
					this->sOption = 5;
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			this->oMusic.openFromFile("playerCollision.wav");
			this->oMusic.play();
			if (this->keyChange)
			{
				switch (this->sOption)
				{
				case 2:(*Game::ini)["KEYBINDING"]["PLAYER1UP"] = "139";
					*Game::p1up = sf::Keyboard::Down;
					break;
				case 3:(*Game::ini)["KEYBINDING"]["PLAYER1DOWN"] = "139";
					*Game::p1dwn = sf::Keyboard::Down;
					break;
				case 4:(*Game::ini)["KEYBINDING"]["PLAYER2UP"] = "139";
					*Game::p2up = sf::Keyboard::Down;
					break;
				case 5:(*Game::ini)["KEYBINDING"]["PLAYER2DOWN"] = "139";
					*Game::p2dwn = sf::Keyboard::Down;
					break;
				}
				this->keyChange = false;
				Game::file->write(*Game::ini);
			}
			else
			{
				this->sOption++;
				if (this->sOption > 5)
				{
					this->sOption = 0;
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			this->oMusic.openFromFile("playerCollision.wav");
			this->oMusic.play();
			if (this->keyChange)
			{
				switch (this->sOption)
				{
				case 2:(*Game::ini)["KEYBINDING"]["PLAYER1UP"] = "136";
					*Game::p1up = sf::Keyboard::Left;
					break;
				case 3:(*Game::ini)["KEYBINDING"]["PLAYER1DOWN"] = "136";
					*Game::p1dwn = sf::Keyboard::Left;
					break;
				case 4:(*Game::ini)["KEYBINDING"]["PLAYER2UP"] = "136";
					*Game::p2up = sf::Keyboard::Left;
					break;
				case 5:(*Game::ini)["KEYBINDING"]["PLAYER2DOWN"] = "136";
					*Game::p2dwn = sf::Keyboard::Left;
					break;
				}
				this->keyChange = false;
				Game::file->write(*Game::ini);
			}
			else
			{
				if (sOption == 0)
				{
					Game::winscore--;
					if (Game::winscore < 5)
					{
						Game::winscore = 21;
					}
					this->wv.setString(std::to_string(Game::winscore));
					(*Game::ini)["GENERAL"]["POINTS"] = std::to_string(Game::winscore);
					(Game::file->write(*Game::ini));
				}
				if (sOption == 1)
				{
					Game::volume--;
					if (Game::volume < 0)
					{
						Game::volume = 0;
					}
					this->vv.setString(std::to_string(Game::volume));
					(*Game::ini)["GENERAL"]["VOLUME"] = std::to_string(Game::volume);
					(Game::file->write(*Game::ini));

				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			this->oMusic.openFromFile("playerCollision.wav");
			this->oMusic.play();
			if (this->keyChange)
			{
				switch (this->sOption)
				{
				case 2:(*Game::ini)["KEYBINDING"]["PLAYER1UP"] = "137";
					*Game::p1up = sf::Keyboard::Right;
					break;
				case 3:(*Game::ini)["KEYBINDING"]["PLAYER1DOWN"] = "137";
					*Game::p1dwn = sf::Keyboard::Right;
					break;
				case 4:(*Game::ini)["KEYBINDING"]["PLAYER2UP"] = "137";
					*Game::p2up = sf::Keyboard::Right;
					break;
				case 5:(*Game::ini)["KEYBINDING"]["PLAYER2DOWN"] = "137";
					*Game::p2dwn = sf::Keyboard::Right;
					break;
				}
				this->keyChange = false;
				Game::file->write(*Game::ini);
			}
			else
			{
				if (sOption == 0)
				{
					Game::winscore++;
					if (Game::winscore > 21)
					{
						Game::winscore = 5;
					}
					this->wv.setString(std::to_string(Game::winscore));
					(*Game::ini)["GENERAL"]["POINTS"] = std::to_string(Game::winscore);
					(Game::file->write(*Game::ini));
				}
				if (sOption == 1)
				{
					Game::volume++;
					if (Game::volume > 100)
					{
						Game::volume = 100;
					}
					this->vv.setString(std::to_string(Game::volume));
					(*Game::ini)["GENERAL"]["VOLUME"] = std::to_string(Game::volume);
					(Game::file->write(*Game::ini));
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			this->oMusic.openFromFile("playerCollision.wav");
			this->oMusic.play();
			if(!this->keyChange)
			{
				 switch (this->sOption)
				{
				case 2:this->keyChange = true;
						break;
				case 3:this->keyChange = true;
						break;
				case 4:this->keyChange = true;
						break;
				case 5:this->keyChange = true;
						break;
				}
			}
		}
		
	}

}


void Settings::update()
{
	this->wv.setFillColor(sf::Color::White);
	this->vv.setFillColor(sf::Color::White);
	this->p1uv.setFillColor(sf::Color::White);
	this->p1dv.setFillColor(sf::Color::White);
	this->p2uv.setFillColor(sf::Color::White);
	this->p2dv.setFillColor(sf::Color::White);
	this->getInput();
	this->keyUpdate();
	switch (this->sOption)
	{
	case 0: this->wv.setFillColor(sf::Color::Red);
		break;
	case 1: this->vv.setFillColor(sf::Color::Red);
		break;
	case 2: this->p1uv.setFillColor(sf::Color::Red);
		break;
	case 3:this->p1dv.setFillColor(sf::Color::Red);
		break;
	case 4:this->p2uv.setFillColor(sf::Color::Red);
		break;
	case 5:this->p2dv.setFillColor(sf::Color::Red);
		break;
	}

	if (this->keyChange)
	{
		switch (this->sOption)
		{
		case 2:	this->p1uv.setString("Enter any Key");
			this->p1uv.setOrigin(this->p1uv.getGlobalBounds().width / 2, this->p1uv.getGlobalBounds().height / 2);
			break;
		case 3:	this->p1dv.setString("Enter any Key");
			this->p1dv.setOrigin(this->p1dv.getGlobalBounds().width / 2, this->p1dv.getGlobalBounds().height / 2);
			break;
		case 4:	this->p2uv.setString("Enter any Key");
			this->p2uv.setOrigin(this->p2uv.getGlobalBounds().width / 2, this->p2uv.getGlobalBounds().height / 2);
			break;
		case 5:	this->p2dv.setString("Enter any Key");
			this->p2dv.setOrigin(this->p2dv.getGlobalBounds().width / 2, this->p2dv.getGlobalBounds().height / 2);
			break;
		}

	}


}

void Settings::render()
{
	this->window->clear();
	this->window->draw(this->setting);
	this->window->draw(this->volume);
	this->window->draw(this->controls);
	this->window->draw(this->p1);
	this->window->draw(this->p1up);
	this->window->draw(this->p1dwn);
	this->window->draw(this->p2up);
	this->window->draw(this->p2dwn);
	this->window->draw(this->winscore);
	this->window->draw(this->vc);
	this->window->draw(this->vv);
	this->window->draw(this->p1uc);
	this->window->draw(this->p1uv);
	this->window->draw(this->p1dc);
	this->window->draw(this->p1dv);
	this->window->draw(this->p2uc);
	this->window->draw(this->p2uv);
	this->window->draw(this->p2dc);
	this->window->draw(this->p2dv);
	this->window->draw(this->wc);
	this->window->draw(this->wv);
	this->window->draw(this->p2);
	this->window->display();

}
