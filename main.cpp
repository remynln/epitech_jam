/*
** EPITECH PROJECT, 2022
** mainGame
** File description:
** main
*/

#include "headers/Game.hpp"

int main()
{
    Game game;

    srand(time(0));
    while (game.win.isOpen()) {
        game.render();
    }
    return 0;
}