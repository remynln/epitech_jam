/*
** EPITECH PROJECT, 2022
** mainGame
** File description:
** Game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_

    #include "../headers/Player.hpp"
    #include <vector>
    #include <SFML/Audio.hpp>
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>

struct BackgroundImages {
    sf::Texture tex;
    sf::Vector2f pos;
    sf::Sprite spt;
};

class Game {
    public:
        Game();
        ~Game();

        void render();

        std::vector<BackgroundImages *> backgrondImages;
        sf::RenderWindow win;
        Player player;

    protected:
    private:
};

#endif /* !GAME_HPP_ */
