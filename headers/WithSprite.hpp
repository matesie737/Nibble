#ifndef WITHSPRITE_HPP 
#define WITHSPRITE_HPP

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

class withSprite : public GameObject
{
protected:

	sf::Sprite sprite;
	sf::Texture texture2;

public:

	void draw(sf::RenderWindow& window) const override
	{
		window.draw(sprite);
	}

	
	sf::Vector2f position()
	{
		return this->sprite.getPosition();
	}

	void move(const int& _x, const int& _y)
	{
		sprite.move(_x, _y);
		
	}

	withSprite(const int& _x, const int& _y, const sf::Texture& texture) : GameObject(_x, _y), texture2(texture)
	{
		sprite.setPosition(x - texture2.getSize().x / 2, y - texture2.getSize().y / 2);
		sprite.setTexture(texture2);
	}

};
#endif