/*
** EPITECH PROJECT, 2022
** Scenario
** File description:
** Scenario
*/

#include "Scenario.hpp"

Scenario::Scenario(std::string name) : _name(name)
{

}

Scenario::~Scenario()
{
    for (auto module : _choice)
        if (module.second)
            delete module.second;
}

void Scenario::addScene(std::string text, std::string picture)
{
    _scene.push_back(make_pair(text, picture));
}

void Scenario::setMap(std::string name, Scenario *scenario)
{
    if (_choice.count(name) == 0)
        _choice[name] = scenario;
}