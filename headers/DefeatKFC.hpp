/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** DefeatKFC
*/

#ifndef DEFEATKFC_HPP_
#define DEFEATKFC_HPP_

#include <SFML/Graphics.hpp>

class DefeatKFC {
    public:
        DefeatKFC();
        ~DefeatKFC();
        void eventHandelling(sf::RenderWindow *window);
        void displayWindow(sf::RenderWindow *window);
        void moveSprites();
        sf::Clock clock;
        bool checkWon();

    protected:
    private:
        sf::Texture _bg_texture;
        sf::Sprite _bg_sprite;
        sf::Texture _bucket_texture;
        sf::Sprite _bucket_sprite;
        sf::Texture _chicken_texture;
        sf::Sprite _chicken_sprite;
        bool _going_left;
        bool _is_flying;
        bool _is_won;
        bool _move_chicken;
        size_t _score;
        sf::Vector2f _vector;
};

#endif /* !DEFEATKFC_HPP_ */
