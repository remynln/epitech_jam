/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** dodgeBottle
*/

#include "../../headers/DodgeBottle.hpp"

AlcoholState dodgeBottle(sf::RenderWindow *window)
{
    DodgeBottle engine;

    while (true) {
        engine.eventHandelling(window);
        if (!window->isOpen())
            return (AlcoholState::ERROR);
        if (engine.checkForEnd())
            return (engine.getRet());
        engine.moveSprites(window);
        engine.displayWindow(window);
        engine.addSprites();
    }
}