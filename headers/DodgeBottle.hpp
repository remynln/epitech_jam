/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** DodgeBottle
*/

#ifndef DODGEBOTTLE_HPP_
#define DODGEBOTTLE_HPP_

#include <SFML/Graphics.hpp>
#include <list>

enum AlcoholState {
    SOBER,
    DRUNK,
    ERROR
};

class Alcohol_Barier
{
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
public:
    Alcohol_Barier();
    ~Alcohol_Barier();
    sf::Sprite getSprite();
    void moveSprite(int);
};

class DodgeBottle {
    public:
        DodgeBottle();
        ~DodgeBottle();
        void eventHandelling(sf::RenderWindow *window);
        void displayWindow(sf::RenderWindow *window);
        void moveSprites(sf::RenderWindow *window);
        void addSprites();
        AlcoholState getRet();
        bool checkForEnd();
        size_t _score;

    private:
        sf::Texture _bg_texture;
        sf::Sprite _bg_sprite;
        sf::Texture _guy_texture;
        sf::Sprite _guy_sprite;
        std::list<Alcohol_Barier *> _bariers;
        AlcoholState _ret;
        size_t _cooldown;
};

#endif /* !DODGEBOTTLE_HPP_ */
