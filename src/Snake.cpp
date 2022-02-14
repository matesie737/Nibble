#include "../headers/Snake.hpp"

void Snake::debug()
{
	if (this->number == 1)
		std::cout << " SnakeSize: " << SnakeSize << "\n";
}

int Snake::get_data()
{
	return this->SnakeSize;
}

bool Snake::snakecollision(){
	return aftercollision;
}

void Snake::draw(sf::RenderWindow &window) const
{
	if (nextmodule)
		nextmodule->draw(window);
		
	window.draw(sprite);
}

int Snake::processInput(sf::Event &event)
{
	return -1;
}

bool Snake::update(int _rotation)
{
	if (aftercollision)
		return false;

	if (number == 1 && ((rotation == 1 && _rotation == 2) || (rotation == 2 && _rotation == 1) || (rotation == 4 && _rotation == 3) || (rotation == 3 && _rotation == 4)))
		_rotation = 0;

	sf::Vector2f position = this->sprite.getPosition();
	if (number == 1 && (position.x >= 1370 || position.x <= 200 || position.y >= 770 || position.y <= 200))
		{
			aftercollision=true;
			return false;
			}

	if (number == 1)
	{
		Snake *tmp = this->nextmodule;
		Snake *tmp2;
		while (tmp)
		{
			sf::Vector2f _position = tmp->sprite.getPosition();
			if (position.x == _position.x && position.y == _position.y)
			{
				aftercollision=true;
				return false;
			}
			tmp2 = tmp;
			tmp = tmp->nextmodule;
		}
		this->SnakeSize = tmp2->SnakeSize;
	}

	if (_rotation != 0)
		this->rotation = _rotation;

	switch (this->rotation)
	{
	case 1:
	{
		this->move(0, -30);
	}
	break;
	case 2:
	{
		this->move(0, 30);
	}
	break;
	case 3:
	{
		this->move(-30, 0);
	}
	break;
	case 4:
	{
		this->move(30, 0);
	}
	break;
	}

	if (nextmodule)
	{
		nextmodule->SnakeSize = this->SnakeSize;
		nextmodule->new_SnakeSize = this->new_SnakeSize;
		nextmodule->update(0);
		nextmodule->rotation = this->rotation;
	}

	if (this->nextmodule == nullptr)
		if (this->number < this->new_SnakeSize)
		{
			//std::cout<<this->SnakeSize<<std::endl;
			int k = this->SnakeSize;
			k++;
			sf::Vector2f __position = this->sprite.getPosition();
			if (this->rotation == 4)
				this->nextmodule = new Snake(__position.x - 15, __position.y + 15, this->texture2, this->texture2, k, this->new_SnakeSize, this->number + 1, this->rotation);
			if (this->rotation == 3)
				this->nextmodule = new Snake(__position.x + 45, __position.y + 15, this->texture2, this->texture2, k, this->new_SnakeSize, this->number + 1, this->rotation);
			if (this->rotation == 2)
				this->nextmodule = new Snake(__position.x + 15, __position.y - 15, this->texture2, this->texture2, k, this->new_SnakeSize, this->number + 1, this->rotation);
			if (this->rotation == 1)
				this->nextmodule = new Snake(__position.x + 15, __position.y + 45, this->texture2, this->texture2, k, this->new_SnakeSize, this->number + 1, this->rotation);
		}
	return true;
}

bool Snake::check_if_possible(int x, int y)
{
	if (this)
	{
		sf::Vector2f position = this->sprite.getPosition();

		if (position.x == x - 15 && position.y == y - 15)
		{
			return false;
			std::cout << position.x << "  " << position.y << std::endl;
		}
		else if (this->nextmodule != nullptr)
		{
			if (this->nextmodule->check_if_possible(x, y))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
			return true;
	}
	else
		return true;
}

Snake::Snake(const int &_x, const int &_y, const sf::Texture &texture, const sf::Texture &_texture, int _SnakeSize, int _new_SnakeSize, int _number, int _rotation) : withSprite(_x, _y, texture), SnakeSize(_SnakeSize), new_SnakeSize(_new_SnakeSize), number(_number), rotation(_rotation)
{
	if (SnakeSize > number)
	{
		int px, py;
		if (rotation == 1)
		{
			px = _x;
			py = _y + 30;
		}
		if (rotation == 2)
		{
			px = _x;
			py = _y - 30;
		}
		if (rotation == 3)
		{
			py = _y;
			px = _x + 30;
		}
		if (rotation == 4)
		{
			py = _y;
			px = _x - 30;
		}
		nextmodule = new Snake(px, py, _texture, _texture, _SnakeSize, _new_SnakeSize, _number + 1, rotation);
	}
	else
		nextmodule = nullptr;
}

Snake::~Snake()
{
	delete this->nextmodule;
}