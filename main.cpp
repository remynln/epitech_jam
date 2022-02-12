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

    while (game.win.isOpen()) {
        game.render();
    }
    return 0;
}