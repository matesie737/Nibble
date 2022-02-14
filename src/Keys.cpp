#include "../headers/Keys.hpp"
#include <iostream>


int keys(sf::Event& event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
	{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
			{
				return 3;
			}
			break;
			case sf::Keyboard::Right:
			{
				return 4;
			}
			break;
			case sf::Keyboard::Up:
			{
				return 1;
			}
			break;
			case sf::Keyboard::Down:
			{
				return 2;
			}
			break;
			case sf::Keyboard::Escape:
			{
				return 5;
			}
			break;
			case sf::Keyboard::Enter:
			{
				return 5;
			}
			break;
			}
	}
	}
	return 0;
}
