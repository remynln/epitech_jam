/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** defeatKFC
*/

#include "../../headers/DefeatKFC.hpp"

void defeatKFC(sf::RenderWindow *window)
{
    DefeatKFC engine;

    engine.clock.restart();
    while (true) {
        engine.eventHandelling(window);
        if (!window->isOpen())
            return;
        if (engine.checkWon())
            return;
        engine.moveSprites();
        engine.displayWindow(window);
    }
}