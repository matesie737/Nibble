#ifndef SNAKE_HPP 
#define SNAKE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "WithSprite.hpp"
//#include "./Fruit.h"


class Snake : public withSprite
{
protected:
	Snake* nextmodule;
	int SnakeSize;
	int new_SnakeSize;
	int number;
	int rotation;
	bool aftercollision = false;
	bool snakecollision() override;

public:

	void debug() override;
	
	int get_data() override;

	void draw(sf::RenderWindow& window) const override;

	int processInput(sf::Event& event) override;

	bool update(int _rotation) override;

	bool check_if_possible(int x, int y) override;
	
	void upsize(int s) override
	{
		this->new_SnakeSize+=s;
	}

	void collisionevent() override
	{
		std::cout<<"DZIALA"<<std::endl;
		aftercollision=true;
	}

	Snake(const int& _x, const int& _y, const sf::Texture& texture, const sf::Texture& _texture, int _SnakeSize, int _new_SnakeSize, int _number, int _rotation);

	~Snake();

	friend class Game;
};

#endif