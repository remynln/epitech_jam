/*
** EPITECH PROJECT, 2022
** mainGame
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_
    
    #include <SFML/Audio.hpp>
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>

class Player {
    public:
        //Player();
        //~Player();

        sf::Vector2f pos = sf::Vector2f(0, 0);
        sf::Vector2f speed = sf::Vector2f(0, 0);
    protected:
    private:
};

#endif /* !PLAYER_HPP_ */
