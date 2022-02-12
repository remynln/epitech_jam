/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** SchoolPriorities
*/

#ifndef SCHOOLPRIORITIES_HPP_
#define SCHOOLPRIORITIES_HPP_

#include <SFML/Graphics.hpp>
#include <list>

enum Priorities {
    SCHOOL,
    STREET,
    ERROR
};

class Priority
{
    private:
        Priorities _prio;
        sf::Texture _texture;
        sf::Sprite _sprite;
    public:
        Priority(Priorities);
        ~Priority();
        sf::Sprite getSprite();
        Priorities getPrio();
        void moveSprite(int);
};

class SchoolPriorities {
    public:
        SchoolPriorities();
        ~SchoolPriorities();
        void eventHandelling(sf::RenderWindow *window);
        void displayWindow(sf::RenderWindow *window);
        void moveSprites();
        void addSprites();
        Priorities getRet();
        bool checkForEnd();

    private:
        sf::Texture _bg_texture;
        sf::Sprite _bg_sprite;
        std::list<Priority *> _priorities;
        size_t _school_score;
        size_t _street_score;
        Priorities _ret;
};

#endif /* !SCHOOLPRIORITIES_HPP_ */
