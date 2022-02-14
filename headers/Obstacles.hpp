#ifndef OBSTACLES_HPP 
#define OBSTACLES_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "WithSprite.hpp"

class Obstacles  : public withSprite
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

	bool check_if_possible(int x, int y) override
	{

		sf::Vector2f position = this->sprite.getPosition();
		std::cout<<position.x <<" "<< x <<" "<<position.y <<" "<<y<<std::endl;


		if (	(position.x == ( x - 15 ) && position.y == ( y - 105 ) ) ||
				(position.x == ( x - 15 ) && position.y == ( y - 45 ) ) ||
				(position.x == ( x - 15 ) && position.y == ( y - 15 ) ) ||
				(position.x == ( x - 15 ) && position.y == ( y - 75 ) ) 	)
				{
					std::cout<<"kurwa"<<std::endl;
					return false;
				}

		return true;

	}

    Obstacles(const int &_x, const int &_y, const sf::Texture &texture) : withSprite(230+_x*30, 275+_y*30, texture)
	{	

	}

    ~Obstacles()
	{

	}





	friend class Game;
};


#endif