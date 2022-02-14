#include "../headers/Game.hpp"
#include "../headers/Button.hpp"
#include "../headers/Snake.hpp"
#include "../headers/Fruit.hpp"
#include "../headers/Text.hpp"

void Game::MenuInit()
{

    

	sf::Texture button;
	button.loadFromFile("./graphics/button/Button.png");
	sf::Font font;
	font.loadFromFile("Arial.ttf");

	GameObject *menu_background = new Background(11);
	GameObject *new_game_button = new Button(800 - 175, 400, button, "New Game!", 40, font, 0);
	GameObject *continue_button = new Button(800 + 175, 400, button, "Continue!", 40, font, 1);
	GameObject *scores_button = new Button(800 - 175, 400 + 150, button, "Scores", 40, font, 2);
	GameObject *options_button = new Button(800 + 175, 400 + 150, button, "Options", 40, font, 3);
	GameObject *exit_button = new Button(800, 400 + 300, button, "Exit", 40, font, 4);
	this->objects.push_back(menu_background);
	this->objects.push_back(new_game_button);
	this->objects.push_back(continue_button);
	this->objects.push_back(scores_button);
	this->objects.push_back(options_button);
	this->objects.push_back(exit_button);
}

void Game::InGame()
{
	if (lives >= 0)
	{
		sf::Texture obstexture;
		obstexture.loadFromFile("./graphics/obstacles/obs.png");

		GameObject *game_background = new Background(data->background);
		this->objects.push_back(game_background);

		sf::Font font;
		font.loadFromFile("Arial.ttf");

		std::string lvltext = "Lvl " + std::to_string(this->lvl);
		GameObject *header_lvl = new Text(70, 50, lvltext, font, 40, info_lvl);
		this->objects.push_back(header_lvl);

		std::string scoretext = "Score " + std::to_string(this->score);
		GameObject *header_score = new Text(300, 50, scoretext, font, 40, info_score);
		this->objects.push_back(header_score);

		std::string livestext = "Lives " + std::to_string(this->lives + 1);
		GameObject *header_lives = new Text(1500, 50, livestext, font, 40, info_lives);
		this->objects.push_back(header_lives);

		std::string togotext = "To next Lvl: ";
		GameObject *header_togo = new Text(650, 50, togotext, font, 40, info_lvl);
		this->objects.push_back(header_togo);

		std::string togoint = std::to_string(9 - this->fruit_nr);
		GameObject *header_togot = new Text(780, 50, togoint, font, 40, info_togo);
		this->objects.push_back(header_togot);

		if (lvl == 1)
			this->gen->lvl1(this->objects);
		else if (lvl == 2)
			this->gen->lvl2(this->objects);
		else if (lvl >= 3)
			this->gen->lvl3(this->objects);

		GameObject *snakeX = new Snake(800, 500, data->snakeHead, data->snakeModule, 3, data->data_snake_size, 1, 1);
		this->objects.push_back(snakeX);

		count();

		fruitinit();
	}
}

void Game::Continue()
{
	
	this->data->read(&(this->score));
	this->new_status = in_game;
}

void Game::Options()
{
	GameObject *options_background = new Background(51);
	this->objects.push_back(options_background);
	sf::Font font;
	font.loadFromFile("Arial.ttf");
	sf::Texture button;
	button.loadFromFile("./graphics/button/Button.png");
	GameObject *background1 = new Button(400, 100, button, "Plain", 40, font, 5);
	GameObject *background2 = new Button(400, 230, button, "Jungle", 40, font, 6);
	GameObject *background3 = new Button(400, 360, button, "Beach", 40, font, 7);
	GameObject *background4 = new Button(400, 490, button, "Amazon", 40, font, 8);
	
	this->objects.push_back(background1);
	this->objects.push_back(background2);
	this->objects.push_back(background3);
	this->objects.push_back(background4);

	GameObject *snake1 = new Button(400, 650, button, "Green", 40, font, 9);
	GameObject *snake2 = new Button(400, 780, button, "Blue", 40, font, 10);

	this->objects.push_back(snake1);
	this->objects.push_back(snake2);


	GameObject *back = new Button(1300, 780, button, "Back", 40, font, 11);
	this->objects.push_back(back);
}

void Game::Best()
{
	sf::Font font;
	font.loadFromFile("Arial.ttf");
	GameObject *background = new Background(41);
	this->objects.push_back(background);
	int a = 0;
	
			GameObject *data_text = new Text(710, 300, "Date:", font, 30, score_text);
			GameObject *resoult_text = new Text(1030, 300, "Score:", font, 30, score_text);
			this->objects.push_back(data_text);
			this->objects.push_back(resoult_text);
	for (auto i : this->scr->scores)
	{
		if (a < 10)
		{
			GameObject *time = new Text(710, 350 + 50 * a, "#"+std::to_string(a+1)+" "+i.first, font, 30, score_text);
			GameObject *resoult = new Text(1000, 350 + 50 * a, std::to_string(i.second), font, 30, score_text);
			this->objects.push_back(time);
			this->objects.push_back(resoult);
		}
		a++;
	}
}

void Game::GameOver()
{
	this->data->write(&(this->score));
	sf::Font font;
	font.loadFromFile("Arial.ttf");
	GameObject *background = new Background(31);
	this->objects.push_back(background);
	std::string scoretext = "Score: " + std::to_string(this->score);
	GameObject *_score = new Text(800, 600, scoretext, font, 70, info_score);
	this->objects.push_back(_score);
}

void Game::count()
{

	sf::Font font;
	font.loadFromFile("Arial.ttf");

	GameObject *count = new Text(800, 450, "3", font, 100, info_count);
	this->objects.push_back(count);
}

void Game::fruitinit()
{

	sf::Texture fruittexture;
	fruittexture.loadFromFile("./graphics/fruit/Fruit.png");

	srand(time(NULL));

	bool nope = true;

	while (nope)
	{
		nope = false;
		int x = rand() % 39;
		int y = rand() % 19;

		std::cout << 230 + x * 30 << "  " << 230 + y * 30 << std::endl;

		for (auto i : this->objects)
		{
			Fruit *isFruit = dynamic_cast<Fruit *>(i);
			if (!i->check_if_possible(230 + x * 30, 230 + y * 30) && !isFruit)
				nope = true;
		}
		if (!nope)
		{
			GameObject *fruit = new Fruit(230 + x * 30, 230 + y * 30, fruittexture);
			this->objects.push_back(fruit);
		}
	}
}

void Game::fruiteat()
{
	sf::Vector2f positionSnake;
	sf::Vector2f positionFruit;

	for (auto i : this->objects)
	{

		Snake *isSnake = dynamic_cast<Snake *>(i);
		Fruit *isFruit = dynamic_cast<Fruit *>(i);

		if (isSnake)
		{
			positionSnake = i->position();
		}
		if (isFruit)
		{
			positionFruit = i->position();
		}
	}

	if ((positionFruit.x == positionSnake.x && positionSnake.y == positionFruit.y) && positionFruit.x != 0)
	{
		int a = 0, b = 0, c;
		for (auto i : this->objects)
		{
			Fruit *isFruit = dynamic_cast<Fruit *>(i);
			if (isFruit)
			{
				c = a;
			}
			a++;
		}
		delete this->objects[c];
		this->objects.erase(this->objects.begin() + c);
		this->data->data_snake_size += 3;

		for (auto i : this->objects)
		{
			Snake *isSnake = dynamic_cast<Snake *>(i);
			i->upsize(this->lvl + 4);
		}
		fruit_nr++;
		score = score + fruit_nr * 4 * lvl;
		for (auto i : this->objects)
		{
			Text *istext = dynamic_cast<Text *>(i);
			if (istext && i->get_data() == 1)
			{
				i->update(score);
			}
		}
		if (fruit_nr < 9)
			fruitinit();
		else
		{
			lvl++;
			deletepointers();
			old_status = init;
			fruit_nr = 0;
		}
	}
}