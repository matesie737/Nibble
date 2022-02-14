#ifndef GAMEWINDOW_HPP 
#define GAMEWINDOW_HPP

#include <SFML/Graphics.hpp>
#include "BackGround.hpp"
#include "Game.hpp"

class GameWindow 
{

    private:

        sf::Vector2f resolution;
        sf::Clock zegar;
        sf::Clock zegar2;
        int i=0;
        int Status;
        std::unique_ptr<Game> game;
        float RenderTime;
        unsigned int windowtype;
        sf::RenderWindow window;
    

    public:

        void draw();
        void run();
        void input();
        void update();
        
        GameWindow();
        ~GameWindow(){
            game->deletepointers();
        }
        friend class Game;
};

#endif