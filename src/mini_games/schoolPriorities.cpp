/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** gameplay
*/

#include "SchoolPriorities.hpp"
#include <iostream>

Priorities schoolPriorities(sf::RenderWindow *window)
{
    SchoolPriorities engine;

    while (true) {
        engine.eventHandelling(window);
        if (!window->isOpen())
            return (Priorities::ERROR);
        if (engine.checkForEnd())
            return (engine.getRet());
        engine.moveSprites();
        engine.displayWindow(window);
        engine.addSprites();
    }
}