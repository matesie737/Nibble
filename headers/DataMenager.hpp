#ifndef DATAMENAGER_HPP
#define DATAMENAGER_HPP

#include <fstream>

class Data
{

private:
	int data_snake_size = 6;
	int data_lives = 3;
	int data_level = 1;
	int background = 24;
	int snake_texture = 1;
	sf::Texture snakeModule;
	sf::Texture snakeHead;

public:
	void read(int *score)
	{
		try
		{
			std::fstream file;
			file.open("data.txt", std::ios::in);
			if (file.good())
			{
				file >> data_snake_size;
				if (data_snake_size < 0)
					throw std::logic_error("Error in snake size");
				file >> data_lives;
				if (data_lives < 0 || data_lives > 3)
					throw std::logic_error("Error in lives");
				file >> data_level;
				if (data_level < 0)
					throw std::logic_error("Error in level");
				file >> *score;
				if (*score < 0)
					throw std::logic_error("Error in score");
				file >> background;
				if (background != 21 && background != 22 && background != 23 && background != 24)
					throw std::logic_error("Error background");
				file.close();
			}
		}
		catch (std::exception &e)
		{
			std::cout << "Error in data read: " << e.what() << '\n';
			data_snake_size = 6;
			data_lives = 3;
			data_level = 1;
			*score = 0;
			background = 21;
		}
	}

	void write(int *score)
	{
		std::fstream file;
		file.open("data.txt", std::ios::out);
		if (file.good())
		{
			file << data_snake_size;
			file << std::endl;
			file << data_lives;
			file << std::endl;
			file << data_level;
			file << std::endl;
			file << *score;
			file << std::endl;
			file << background;
			file.close();
		}
	}

	void update_texture(int i)
	{
		if (i == 1)
		{
			snakeModule.loadFromFile("./graphics/snake/SnakeModule.png");
			snakeHead.loadFromFile("./graphics/snake/SnakeHead.png");
		}
		else if (i == 2)
		{
			snakeModule.loadFromFile("./graphics/snake/SnakeModuleB.png");
			snakeHead.loadFromFile("./graphics/snake/SnakeHeadB.png");
		}
		else
		{
			snakeModule.loadFromFile("./graphics/snake/SnakeModule.png");
			snakeHead.loadFromFile("./graphics/snake/SnakeHead.png");
		}
	}

	void update_data(int i, int j, int k)
	{
		data_snake_size = i;
		data_lives = j;
		data_level = k;
	}

	Data()
	{
		snakeModule.loadFromFile("./graphics/snake/SnakeModule.png");
		snakeHead.loadFromFile("./graphics/snake/SnakeHead.png");
	}

	friend class Game;
};
#endif