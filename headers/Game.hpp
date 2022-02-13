/*
** EPITECH PROJECT, 2022
** mainGame
** File description:
** Game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_

    #include "Player.hpp"
    #include "Scenario.hpp"
    #include <vector>
    #include <SFML/Audio.hpp>
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <unordered_map>
    #include "DecisionWall.hpp"

struct BackgroundImages {
    sf::Texture tex;
    sf::Vector2f pos;
    sf::Sprite spt;
};

class DecisionWall;

class Game {
    public:
        Game();
        ~Game();

        void render();
        void startScenario();
        void handleEvent();

        std::vector<BackgroundImages *> backgrondImages;
        sf::RenderWindow win;
        Player player;
        Scenario scenario;
        std::vector<DecisionWall *> walls;
        
    private:
        bool _inScenario;
        sf::Texture *_texture_perso;
        sf::Sprite _sprite;
};

#endif /* !GAME_HPP_ */
