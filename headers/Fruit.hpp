#ifndef FRUIT_HPP 
#define FRUIT_HPP

#include <SFML/Graphics.hpp>
#include "WithSprite.hpp"

class Fruit : public withSprite
{
public: 
    void debug() override
	{
		return;
	}

	int get_data() override
	{
		return 0;
	}

	void draw(sf::RenderWindow& window) const override
	{
		window.draw(sprite);
	}

	int processInput(sf::Event& event) override
	{
		return -1;
	}

	bool update(int _rotation) override
	{
		return true;
	}

    Fruit(const int &_x, const int &_y, const sf::Texture &texture) : withSprite(_x, _y, texture)
	{	
        
    }


};

#endif