#ifndef GAMEOBJECT_HPP 
#define GAMEOBJECT_HPP 

#include <SFML/Graphics.hpp>

class GameObject
{
	protected:

		int x, y;

	public:

		virtual void draw(sf::RenderWindow& window) const = 0;
		virtual void move(const int& _x, const int& _y) = 0;
		virtual int processInput(sf::Event& event) = 0;
		virtual void debug() = 0;
		virtual bool update(int _rotation) = 0;
		virtual int get_data() = 0;
		virtual sf::Vector2f position() = 0;
		virtual void collisionevent(){}
		virtual void upsize(int s){return;}
		virtual bool snakecollision(){return false;}
		virtual bool check_if_possible(int x, int y)
		{
			return true;
		}
		
		int getX()
		{
			return x;
		}
		int getY()
		{
			return y;
		}

		GameObject(const int& _x, const int& _y) : x(_x), y(_y){}
		virtual ~GameObject(){ }
};

#endif