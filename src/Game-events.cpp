#include "../headers/Game.hpp"
#include "../headers/Snake.hpp"
#include "../headers/Text.hpp"
#include "../headers/Keys.hpp"

bool Game::in_menu_event(sf::Event event)
{
    for (auto i : this->objects)
    {
        switch (i->processInput(event))
        {
        case -1:
            break;
        case 0:
            this->new_status = in_game;
            std::cout << "New Game Button Pressed" << std::endl;
            break;
        case 1:
            this->new_status=is_continue;
            std::cout << "Continue Button Pressed" << std::endl;
            break;
        case 2:
            this->new_status=in_best;
            std::cout << "Scores Button Pressed" << std::endl;
            break;
        case 3:
        this->new_status=in_settings;
            std::cout << "Options Button Pressed" << std::endl;
            break;
        case 4:
            std::cout << "apliakcja zostanie zamknięta" << std::endl;
            return false;
            break;
        case 5:
            this->data->background=21;
            std::cout << "tlo 1" << std::endl;
            break;
        case 6:
            this->data->background=22;
            std::cout << "tlo 2" << std::endl;
            break;
        case 7:
            this->data->background=23;
            std::cout << "tlo 3" << std::endl;
            break;
        case 8:
            this->data->background=24;
            std::cout << "tlo 4" << std::endl;
            break;
        case 9:
            this->data->update_texture(1);
            std::cout << "zielony" << std::endl;
            break;
        case 10:
            this->data->update_texture(2);
            std::cout << "niebieski" << std::endl;
            break;
        case 11:
            this->new_status=in_menu;
            break;
        }
    }
    return true;
}

bool Game::in_game_event(sf::Event event, int i)
{


    int key = keys(event);

    if (key == -1)
        return false;
    else if (key == 0)
    {
        return true;
    }
    else
    {
        if (i == -1 && key < 5)
        {
            for (auto i : this->objects)
            {
                Snake *isSnake = dynamic_cast<Snake *>(i);
                if (isSnake)
                    i->update(key);
            }
            this->is_input = false;
        }
        if(key>=5)
        {
                this->new_status = in_menu;
        }
    }
    if (this->fruit_nr == 0)
    {
        for (auto i : this->objects)
        {
            Text *isText = dynamic_cast<Text *>(i);
            if (isText)
                if (i->get_data() == 0)
                    i->update(key);
        }
    }

	this->data->write(&(this->score));

    return true;
}