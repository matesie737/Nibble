#ifndef BUTTON_H 
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "WithSprite.hpp"

class Button : public withSprite
{

	int type;
	bool mousepressed;
	sf::Text napis;
	sf::Font _font;

public:

	void debug() override;
	
	int get_data() override;

	void draw(sf::RenderWindow& window) const override;

	int processInput(sf::Event& event) override;

	bool update(int _rotation);

	Button(const int& _x, const int& _y, const sf::Texture& texture, const std::string ptext, const int& cSize, const sf::Font& font, const int& _type);

	~Button()
	{
	}

};

#endif