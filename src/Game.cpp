#include "../headers/Game.hpp"
#include <iostream>

int Game::status(game_status status)
{
	switch (status)
	{
	case in_menu:
	{
		MenuInit();
		return 1;
		break;
	}
	case in_game:
	{
		InGame();
		return 2;
		break;
	}
	case is_continue:
	{
		Continue();
		return 2;
		break;
	}
	case in_settings:
	{
		Options();
		return 3;
		break;
	}
	case game_over:
	{
		GameOver();
		return 4;
		break;
	}
	case in_best:
	{
		Best();
		return 4;
		break;
	}
	}
}

void Game::doDebug()
{
	for (auto v : objects)
		v->debug();
}

void Game::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < objects.size(); ++i)
		objects[i]->draw(window);
}

void Game::deletepointers()
{
	for (auto p : this->objects)
	{
		delete p;
	}
	this->objects.clear();
}
