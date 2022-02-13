/*
** EPITECH PROJECT, 2022
** mainGame
** File description:
** Game
*/

#include <iostream>
#include "Game.hpp"

BackgroundImages *createBg(std::string file, sf::Vector2f pos)
{
    BackgroundImages *res = new BackgroundImages();
    res->tex = sf::Texture();
    res->spt = sf::Sprite();
    res->tex.loadFromFile(file);
    res->spt.setTexture(res->tex);
    res->pos = pos;
    return (res);
}

Game::Game()
    : backgrondImages(
         { createBg("assets/background.jpg", sf::Vector2f(0, 0)) }
    ), 
    win(sf::VideoMode(1200, 800), "Game"),
    scenario(Scenario())
{
}

Game::~Game()
{
}

void Game::handleEvent()
{
    sf::Event event;

    while (win.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            win.close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Z) {
                this->player.speed.y = -1;
            } else if (event.key.code == sf::Keyboard::S) {
                this->player.speed.y = 1;
            } else if (event.key.code == sf::Keyboard::Q) {
                this->player.speed.x = -1;
            } else if (event.key.code == sf::Keyboard::D) {
                this->player.speed.x = 1;
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if ((event.key.code == sf::Keyboard::S && player.speed.y == 1) ||
            (event.key.code == sf::Keyboard::Z && player.speed.y == -1)) {
                this->player.speed.y = 0;            
            } else if ((event.key.code == sf::Keyboard::Q && player.speed.x == -1) ||
            (event.key.code == sf::Keyboard::D && player.speed.x == 1)) {
                this->player.speed.x = 0;
            }
        }
    }
}

void Game::render()
{
    handleEvent();
    if (scenario.getInScenario()) {
        scenario.startScenario(&win);
        if (scenario.isAnEnd() && scenario.getInScenario() == false)
            return (win.close());
    }
    this->player.pos += this->player.speed;
    for (BackgroundImages *bg : backgrondImages) {
        bg->spt.setPosition(bg->pos - this->player.pos);
    }
    win.clear();
    for (BackgroundImages *bg : backgrondImages) {
        win.draw(bg->spt);
    }
    win.display();
}