#include "../headers/GameWindow.hpp"
#include <time.h>
#include <iostream>
#include <string>
#include <utility>
#include <stdio.h>
#include <memory>


int main()
{


    std::unique_ptr<GameWindow> gamewindow = std::make_unique<GameWindow>();

    gamewindow->run();

    return 0;

}