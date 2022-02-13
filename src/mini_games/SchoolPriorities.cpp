/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** SchoolPriorities
*/

#include "SchoolPriorities.hpp"

SchoolPriorities::SchoolPriorities()
{
    _bg_texture.loadFromFile("assets/images/school_priorities/background.png");
    _bg_sprite.setTexture(_bg_texture);
    _school_score = 0;
    _street_score = 0;
    _ret = Priorities::ERROR_;
}

SchoolPriorities::~SchoolPriorities()
{
}

void SchoolPriorities::eventHandelling(sf::RenderWindow *window)
{
    sf::Event event;
    sf::Vector2i pos;
    sf::Vector2f spr_pos;

    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::MouseButtonPressed) {
            pos = sf::Mouse::getPosition(*window);
            for (Priority *prio : this->_priorities) {
                spr_pos = prio->getSprite().getPosition();
                if (spr_pos.x < pos.x && pos.x < spr_pos.x + 200 &&
                spr_pos.y < pos.y && pos.y < spr_pos.y + 200) {
                    if (prio->getPrio() == Priorities::SCHOOL)
                        this->_school_score++;
                    if (prio->getPrio() == Priorities::STREET)
                        this->_street_score++;
                    this->_priorities.remove(prio);
                    return;
                }
            }
        }
    }
}

void SchoolPriorities::displayWindow(sf::RenderWindow *window)
{
    window->clear();
    window->draw(this->_bg_sprite);
    for (Priority *prio : this->_priorities)
        window->draw(prio->getSprite());
    window->display();
}

void SchoolPriorities::moveSprites()
{
    for (Priority *prio : this->_priorities) {
        prio->moveSprite(-1);
        if (prio->getSprite().getPosition().x < -200) {
            this->_priorities.remove(prio);
            return;
        }
    }
}

void SchoolPriorities::addSprites()
{
    if (std::rand() % 300 == 1) {
        if (std::rand() % 2 == 1)
            this->_priorities.push_front(new Priority(Priorities::SCHOOL));
        else
            this->_priorities.push_front(new Priority(Priorities::STREET));
    }
}

bool SchoolPriorities::checkForEnd()
{
    if (this->_school_score >= 10)
        this->_ret = Priorities::SCHOOL;
    if (this->_street_score >= 10)
        this->_ret = Priorities::STREET;
    if (this->_ret != Priorities::ERROR_)
        return (true);
    return (false);
}

Priorities SchoolPriorities::getRet()
{
    return (this->_ret);
}

Priority::Priority(Priorities prio)
{
    _prio = prio;
    if (prio == Priorities::SCHOOL) {
        if (rand() % 2 == 1)
            _texture.loadFromFile("assets/images/school_priorities/pencil.png");
        else
            _texture.loadFromFile("assets/images/school_priorities/page.png");
    } else if (prio == Priorities::STREET) {
        if (rand() % 2 == 1)
            _texture.loadFromFile("assets/images/school_priorities/beer.png");
        else
            _texture.loadFromFile("assets/images/school_priorities/drug.png");
    }
    _sprite.setTexture(_texture);
    _sprite.setPosition(1200, rand() % 600);
}

Priority::~Priority()
{
}

sf::Sprite Priority::getSprite()
{
    return (this->_sprite);
}

Priorities Priority::getPrio()
{
    return (this->_prio);
}

void Priority::moveSprite(int move)
{
    this->_sprite.move(move, 0);
}