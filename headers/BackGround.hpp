#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "WithSprite.hpp"


class Background : public withSprite
{
public:

	void draw(sf::RenderWindow& window) const override
	{
		window.draw(sprite);
	}
    
	int processInput(sf::Event& event) override
	{
		return -1;
	}
	int get_data() override
    {
        return 0;
    }

	void debug() override
	{
		return;
	}
	bool update(int _rotation)
	{
		return true;
	}

    sf::Texture backgroundtexture(int type)
    {
	    sf::Texture texture;
        switch(type)
        {
            case 11:
            {
                texture.loadFromFile("./graphics/Board/BackGround.jpg");

                break;
            }
            case 21:
            {
                texture.loadFromFile("./graphics/board/plain.jpg");

                break;
            }
            case 22:
            {
                texture.loadFromFile("./graphics/board/jungle.jpg");

                break;
            }
            case 23:
            {
                texture.loadFromFile("./graphics/board/beach.jpg");

                break;
            }
            case 24:
            {
                texture.loadFromFile("./graphics/board/amazon.jpg");

                break;
            }
            case 31:
            {
                texture.loadFromFile("./graphics/board/BackGroundLose.jpg");

                break;
            }
            case 41:
            {
                texture.loadFromFile("./graphics/board/Scores.jpg");

                break;
            }
            case 51:
            {
                texture.loadFromFile("./graphics/board/options.jpg");

                break;
            }
            default:
            {

            }
        }
        return texture;
    }
	
    Background(int type) : withSprite(800, 450, backgroundtexture(type))
    {

    }

};


#endif