/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** DodgeBottle
*/

#include "../../headers/DodgeBottle.hpp"

DodgeBottle::DodgeBottle()
{
    _bg_texture.loadFromFile("assets/images/dodge_bottle/background.png");
    _bg_sprite.setTexture(_bg_texture);
    _guy_texture.loadFromFile("assets/images/dodge_bottle/guy.png");
    _guy_sprite.setTexture(_guy_texture);
    _score = 0;
    _ret = AlcoholState::ERROR;
    _cooldown = 0;
}

DodgeBottle::~DodgeBottle()
{
}

void DodgeBottle::eventHandelling(sf::RenderWindow *window)
{
    sf::Event event;

    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void DodgeBottle::displayWindow(sf::RenderWindow *window)
{
    window->clear();
    window->draw(this->_bg_sprite);
    window->draw(this->_guy_sprite);
    for (Alcohol_Barier *prio : this->_bariers)
        window->draw(prio->getSprite());
    window->display();
}

void DodgeBottle::moveSprites(sf::RenderWindow *window)
{
    sf::Vector2i pos = sf::Mouse::getPosition(*window);

    this->_guy_sprite.setPosition(pos.x - 25, pos.y - 25);
    for (Alcohol_Barier *bar : this->_bariers) {
        bar->moveSprite(-1);
        if (bar->getSprite().getPosition().x < -300) {
            this->_bariers.remove(bar);
            this->_score++;
            return;
        }
    }
}

void DodgeBottle::addSprites()
{
    if (this->_cooldown != 0)
        this->_cooldown--;
    if (this->_cooldown == 0 && std::rand() % 800 == 1) {
        this->_bariers.push_front(new Alcohol_Barier());
        this->_cooldown = 500;
    }
}

bool DodgeBottle::checkForEnd()
{
    sf::Vector2f pos =  this->_guy_sprite.getPosition();
    sf::Vector2f curr_pos;

    if (this->_score > 14)
        this->_ret = AlcoholState::SOBER;
    for (Alcohol_Barier *bar : this->_bariers) {
        curr_pos = bar->getSprite().getPosition();
        if (pos.x > curr_pos.x && pos.x < curr_pos.x + 325 &&
        pos.y > curr_pos.y - 50 && pos.y < curr_pos.y + 500)
            this->_ret = AlcoholState::DRUNK;
    }
    if (this->_ret != AlcoholState::ERROR)
        return (true);
    return (false);
}

AlcoholState DodgeBottle::getRet()
{
    return (this->_ret);
}

Alcohol_Barier::Alcohol_Barier()
{
    int r = rand() % 3;
    if (r == 0)
        _texture.loadFromFile("assets/images/dodge_bottle/beer.png");
    else if (r == 1)
        _texture.loadFromFile("assets/images/dodge_bottle/bottle.png");
    else
        _texture.loadFromFile("assets/images/dodge_bottle/fancy_glass.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(1200, rand() % 300);
}

Alcohol_Barier::~Alcohol_Barier()
{
}

sf::Sprite Alcohol_Barier::getSprite()
{
    return (this->_sprite);
}

void Alcohol_Barier::moveSprite(int move)
{
    this->_sprite.move(move, 0);
}