#ifndef TEXT_HPP
#define TEXT_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

enum text_type
{
    info_lvl,
    info_score,
    info_lives,
    info_count,
    score_text,
    info_togo
};

class Text : public GameObject
{
protected:
    text_type type;
    sf::Text napis;
    sf::Font _font;
    int x = 0;

public:
    void debug() override
    {
        return;
    }

    int get_data() override
    {
        if(type==info_count)
        return 0;
        else if (type==info_score)
        return 1;
        else if (type==info_togo)
        return 1;
        else return 2;
    }
    sf::Vector2f position() override
    {
        return {0, 0};
    }

    void move(const int &_x, const int &_y)
    {
    }
    int processInput(sf::Event &event) override
    {
        return -1;
    }

    bool update(int _rotation) override
    {
        if (type == info_count)
        {
            if (x == 6)
                napis.setString("2");
            else if (x == 12)
                napis.setString("1");
            else if (x == 18)
                napis.setString("0");
            else if (x == 23)
                napis.setString("");
            x++;
        }
        if(type == info_score)
        {
            std::string x="Score " + std::to_string(_rotation);
            napis.setString(x);
        }
        if(type == info_togo)
        {
            std::string tmp=napis.getString();
            int a = atoi(tmp.c_str());
            a--;
            napis.setString(std::to_string(a));
        }
        return true;
    }

    void draw(sf::RenderWindow &window) const override
    {
        window.draw(napis);
    }

    Text(const int &_x, const int &_y, const std::string text, sf::Font &font, const int &cSize, text_type _type) : GameObject(_x, _y), _font(font), type(_type)
    {
        font = _font;
        napis.setFillColor(sf::Color(237, 28, 36, 255));
        napis.setCharacterSize(cSize);
        napis.setFont(_font);
        napis.setString(text);
        napis.setOutlineColor(sf::Color::Red);
        napis.setPosition(_x - napis.getGlobalBounds().width / 2, _y - napis.getGlobalBounds().height / 2 - cSize / 2);
    }
};

#endif