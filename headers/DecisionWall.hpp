/*
** EPITECH PROJECT, 2022
** johann_push
** File description:
** DecisionWall
*/

#ifndef DECISIONWALL_HPP_
    #define DECISIONWALL_HPP_

    #include <vector>
    #include <SFML/Window.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include "Game.hpp"

class Game;

struct Door {
    Door(float _x1, float _x2, std::string _imagefile, void (*_callback)());
    float x1;
    float x2;

    float yOffset;

    sf::Texture tex;
    sf::Sprite sprite;

    void (*callback)();
    void checkCollisions(sf::Vector2f const &pos);
};


class DecisionWall {
    public:
        DecisionWall(float y, std::vector<Door *> doors, Game &game);
        ~DecisionWall();
        bool isInWall(sf::Vector2f vect);
        void checkCollisions();
        void renderDoors();
    protected:
    private:
        float _y;
        Game &_game;
        std::vector<Door *> _doors;
};

#endif /* !DECISIONWALL_HPP_ */
