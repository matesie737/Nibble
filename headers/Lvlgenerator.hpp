#ifndef LVLGENERATOR_HPP
#define LVLGENERATOR_HPP

#include <iostream>
#include <stdlib.h> 
#include <vector>
#include "Obstacles.hpp"

class Lvlgenerator
{
    private:
        sf::Texture texture;
    public:

        void lvl1(std::vector < GameObject* > &objects)
        {
	        GameObject *obstacle = new Obstacles(1, 1, texture);
	        GameObject *obstacle2 = new Obstacles(37, 1, texture);
	        GameObject *obstacle3 = new Obstacles(1, 14, texture);
	        GameObject *obstacle4 = new Obstacles(37, 14, texture);
            
            objects.push_back(obstacle);
	        objects.push_back(obstacle2);
	        objects.push_back(obstacle3);
	        objects.push_back(obstacle4);
        }
        void lvl2(std::vector < GameObject* > &objects)
        {
	        GameObject *obstacle = new Obstacles(1, 1, texture);
	        GameObject *obstacle2 = new Obstacles(37, 1, texture);
	        GameObject *obstacle3 = new Obstacles(1, 14, texture);
	        GameObject *obstacle4 = new Obstacles(37, 14, texture);
	        GameObject *obstacle5 = new Obstacles(5, 5, texture);
	        GameObject *obstacle6 = new Obstacles(33, 5, texture);
	        GameObject *obstacle7 = new Obstacles(5, 10, texture);
	        GameObject *obstacle8 = new Obstacles(33, 10, texture);
            
            objects.push_back(obstacle);
	        objects.push_back(obstacle2);
	        objects.push_back(obstacle3);
	        objects.push_back(obstacle4);
	        objects.push_back(obstacle5);
	        objects.push_back(obstacle6);
	        objects.push_back(obstacle7);
	        objects.push_back(obstacle8);
        }
        
        void lvl3(std::vector < GameObject* > &objects)
        {
	        GameObject *obstacle = new Obstacles(1, 1, texture);
	        GameObject *obstacle2 = new Obstacles(37, 1, texture);
	        GameObject *obstacle3 = new Obstacles(1, 14, texture);
	        GameObject *obstacle4 = new Obstacles(37, 14, texture);
	        GameObject *obstacle5 = new Obstacles(5, 5, texture);
	        GameObject *obstacle6 = new Obstacles(33, 5, texture);
	        GameObject *obstacle7 = new Obstacles(5, 10, texture);
	        GameObject *obstacle8 = new Obstacles(33, 10, texture);
            
	        GameObject *obstacle9 = new Obstacles(8, 5, texture);
	        GameObject *obstacle10 = new Obstacles(30, 5, texture);
	        GameObject *obstacle11 = new Obstacles(8, 10, texture);
	        GameObject *obstacle12 = new Obstacles(30, 10, texture);
            
	        GameObject *obstacle13 = new Obstacles(7,0, texture);
	        GameObject *obstacle14 = new Obstacles(7,15, texture);
	        GameObject *obstacle15 = new Obstacles(31,0, texture);
	        GameObject *obstacle16 = new Obstacles(31,15, texture);
            
            objects.push_back(obstacle);
	        objects.push_back(obstacle2);
	        objects.push_back(obstacle3);
	        objects.push_back(obstacle4);
	        objects.push_back(obstacle5);
	        objects.push_back(obstacle6);
	        objects.push_back(obstacle7);
	        objects.push_back(obstacle8);
            objects.push_back(obstacle9);
            objects.push_back(obstacle10);
            objects.push_back(obstacle11);
            objects.push_back(obstacle12);
            objects.push_back(obstacle13);
            objects.push_back(obstacle14);
            objects.push_back(obstacle15);
            objects.push_back(obstacle16);

        }

        Lvlgenerator()
        {
            texture.loadFromFile("./graphics/obstacles/obs.png");
        }
};

#endif