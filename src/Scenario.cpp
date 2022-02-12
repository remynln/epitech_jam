/*
** EPITECH PROJECT, 2022
** Scenario
** File description:
** Scenario
*/

#include "Scenario.hpp"

Scenario::Scenario() : _name("start")
{

}

void Scenario::setMap(std::string name, void (*func)(sf::RenderWindow *))
{
    _choice[name] = func;
}

void Scenario::startScenario(sf::RenderWindow *window)
{
    _choice[_name](window);
}

void Scenario::setScenario(std::string name)
{
    _name = name;
}