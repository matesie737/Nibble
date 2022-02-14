#include "../headers/GameWindow.hpp"
#include "../headers/BackGround.hpp"
#include "../headers/Snake.hpp"
#include "../headers/Text.hpp"

GameWindow::GameWindow()
{
    resolution = sf::Vector2f(1600, 900);
    window.create(sf::VideoMode(resolution.x, resolution.y), "Nibble", sf::Style::Default);
    game = std::make_unique<Game>();
}

void GameWindow::input()
{
    int c=0;
    if (this->game->old_status != this->game->new_status)
    {
        this->game->old_status = this->game->new_status;
        this->game->deletepointers();
        c = this->game->status(this->game->new_status);
        if(c==2)
            this->i=0;
    }

    sf::Event event{};

    switch (this->game->old_status)
    {
    case in_menu:
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (!this->game->in_menu_event(event))
                window.close();
        }
    };
    break;
    case in_game:
    {
        this->game->is_input = true;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (!this->game->in_game_event(event, this->i))
                window.close();
        }
        if (this->game->is_input)
        {
            if (this->i == -1)
            {
                for (auto i : this->game->objects)
                {
                    Snake *isSnake = dynamic_cast<Snake *>(i);
                    if (isSnake)
                        i->update(0);
                    if (isSnake)
                    {
                        game->data->update_data(i->get_data(), 3, 1);
                        break;
                    }
                }
            }
            if (this->i != -1)
            {
                for (auto i : this->game->objects)
                {
                    Text *isText = dynamic_cast<Text *>(i);
                    if (isText)
                        if (i->get_data() == 0)
                            i->update(0);
                }
            }
            if (this->i >= 0)
                this->i = this->i + 1;
            if (this->i == 24)
                this->i = -1;

            for (auto i : this->game->objects)
            {
                if (i->snakecollision())
                    game->col = true;
            }

            if (game->col && game->lives >= 0)
            {
                game->lives--;
                this->game->old_status = init;
                game->col = false;
                this->i=0;
            }
            if(game->lives < 0)
            {
                this->game->new_status = game_over;
                game->lives = 3;
                game->col = false;
                game->scr->addscore(game->score);
                this->i=0;
            }
        }
        game->data->write(&(this->game->score));
    };
    break;
    case game_over: 
    while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (!this->game->in_game_event(event, this->i))
                window.close();
        }
        break;
    case in_best: 
    while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (!this->game->in_game_event(event, this->i))
                window.close();
        }
        break;
    case in_settings:
    while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (!this->game->in_menu_event(event))
                window.close();
        }
        break;

    default:
    {
    };
    }
}

void GameWindow::update()
{
    if (this->game->new_status == in_game)
    {

        GameObject *tmps;
        sf::Vector2f position;

        for (auto i : this->game->objects)
        {
            Snake *isSnake = dynamic_cast<Snake *>(i);
            if (isSnake)
            {
                tmps = i;
                position = tmps->position();
            }
        }

        for (auto i : this->game->objects)
        {
            Obstacles *isOBS = dynamic_cast<Obstacles *>(i);
            if (isOBS)
            {
                //std::cout << position.x << " " << position.y << " " << i->getX() << " " << i->getY() << " " << std::endl;

                if ((position.x + 15 > i->getX() - 30 && position.x + 15 < i->getX() + 30) &&
                    (position.y + 15 > i->getY() - 75 && position.y + 15 < i->getY() + 75))
                {
                    tmps->collisionevent();
                    std::cout << "KOLIZJAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
                }
            }
        }

        game->fruiteat();

        if (this->game->old_status == init)
            this->i = 0;
    }
}

void GameWindow::draw()
{
    window.clear(sf::Color::Black);
    game->draw(window);
    window.display();
}

//16666

void GameWindow::run()
{
    while (window.isOpen())
    {
        if (zegar.getElapsedTime().asMicroseconds() >= 166666 - RenderTime)
        {
            zegar2.restart();

            input();
            update();
            //game->doDebug();
            draw();

            zegar.restart();
            RenderTime = zegar2.getElapsedTime().asMicroseconds();
        }
    }
}