#include "../headers/Button.hpp"

void Button::debug()
{
	std::string s = napis.getString();
	std::cout << " Button " << s << "\n";
}

void Button::draw(sf::RenderWindow& window) const 
{
	window.draw(sprite);
	window.draw(napis);
}

int Button::get_data(){
	return 0;
}

int Button::processInput(sf::Event& event)
{			
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (!mousepressed)
		{
			mousepressed = true;
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (sprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					return type;
				}
			}
		}
	}
	if (event.type == sf::Event::MouseButtonReleased)
		mousepressed = false;
	return -1;
}

bool Button::update(int _rotation)
{
	return true;
}

Button::Button(const int& _x, const int& _y, const sf::Texture& texture, const std::string ptext, const int& cSize, const sf::Font& font, const int& _type) : withSprite(_x, _y, texture), type(_type), _font(font)
{
	mousepressed = false;
	napis.setFillColor(sf::Color(237, 28, 36, 255));
	napis.setCharacterSize(cSize);
	napis.setFont(_font);
	napis.setString(ptext);
    napis.setOutlineColor(sf::Color::Red);
	napis.setPosition(_x - napis.getGlobalBounds().width / 2, _y - napis.getGlobalBounds().height / 2 - cSize / 2);
}