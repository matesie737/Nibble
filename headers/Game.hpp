#ifndef GAME_HPP
#define GAME_HPP

#include <stdlib.h> 
#include <vector>
#include "BackGround.hpp"
#include "DataMenager.hpp"
#include "Obstacles.hpp"
#include "Lvlgenerator.hpp"
#include "Bestscores.hpp"
#include <iostream>

enum game_status{ in_menu , in_game, is_continue, game_over, in_settings, in_best,init};

class Game
{
	private:

		std::unique_ptr<Data> data;
		std::unique_ptr<Lvlgenerator> gen; 
		std::unique_ptr<BestScores> scr;

    protected:

        std::vector < GameObject* > objects;

    public:

		game_status old_status=init;
		game_status new_status=in_menu;
        bool is_input = true;
		bool col=true;
		int fruit_nr=0;
		int lvl=1;
		int score = 0;
		int lives = 3;
		int status(game_status status);
		void doDebug();
		void draw(sf::RenderWindow &window);
		void deletepointers();
		void fruitinit();
		void fruiteat();

		void InGame();
		void Continue();
		void MenuInit();
		void Options();
		void Best();
		void GameOver();
		void count();

		bool in_menu_event(sf::Event event);
		bool in_game_event(sf::Event event, int i);

		Game()
		{
			data = std::make_unique<Data>();
			gen = std::make_unique<Lvlgenerator>();
			scr = std::make_unique<BestScores>();
		}
		~Game()
		{
		}

		friend class GameWindow;
};

#endif