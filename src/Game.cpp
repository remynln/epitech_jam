/*
** EPITECH PROJECT, 2022
** mainGame
** File description:
** Game
*/

#include <iostream>
#include "Game.hpp"

void lecole()
{
    std::cout << "L'ecole" << std::endl;
}

void larue()
{
    std::cout << "La rue, la vré" << std::endl;
}

BackgroundImages *createBg(std::string file,
    sf::Vector2f pos,
    sf::Vector2f size = sf::Vector2f(0, 0))
{
    BackgroundImages *res = new BackgroundImages();
    res->tex = sf::Texture();
    res->spt = sf::Sprite();
    std::cout << res->tex.loadFromFile(file) << std::endl;
    res->spt.setTexture(res->tex);
    res->pos = pos;
    return (res);
}

Game::Game()
    : backgrondImages({
        createBg("assets/route1.png", sf::Vector2f(-374, -570)),
        createBg("assets/tree.png", sf::Vector2f(-404, -470), sf::Vector2f(0.8, 0.8)),
        createBg("assets/tree.png", sf::Vector2f(400, -800), sf::Vector2f(0.8, 0.8))
        //createBg("assets/school.png", sf::Vector2f(-100, -800), sf::Vector2f(1.2, 1.2)),
        //createBg("assets/street.jpg", sf::Vector2f(1200, -800), sf::Vector2f(0.4, 0.4))
    })
    , win(sf::VideoMode(1200, 800), "Game"),
    scenario(Scenario()),
    _inScenario(true),
    walls({
        new DecisionWall(-880, {
            new Door(-100, 200, "assets/school.png", lecole),
            new Door(1200, 1800, "assets/street.jpg", larue),
        }, *this)
    })
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
    if (_inScenario) {
        scenario.startScenario(&win);
        if (scenario.isAnEnd())
            return (win.close());
        _inScenario = false;
    }
    bool isInWall = false;
    for (DecisionWall *wall : this->walls) {
        if (wall->isInWall(this->player.pos) && this->player.speed.y < 0)
            isInWall = true;
        wall->checkCollisions();
    }
    this->player.pos.x += this->player.speed.x;
    if (!isInWall) {
        this->player.pos.y += this->player.speed.y;
    }
    for (BackgroundImages *bg : backgrondImages) {
        bg->spt.setPosition(bg->pos - this->player.pos);
    }
    win.clear();
    for (BackgroundImages *bg : backgrondImages) {
        win.draw(bg->spt);
    }

    for (DecisionWall *wall : this->walls) {
        wall->renderDoors();
    }
    win.display();
}