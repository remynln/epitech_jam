//
// EPITECH PROJECT, 2022
// epitech jam
// File description:
// beet saber
//

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics.hpp>
#include <cstdbool>
#include <iostream>
#include <vector>
#include "../../headers/BeetSaber.hpp"

CubeComming::CubeComming()
{
    int x = rand() % (X_MAX / 2);
    int y = rand() % (Y_MAX * 4);
    is_touched = false;
    texture = new sf::Texture;
    times = 0.0;
    flech_direction = rand() % 4;
    switch (flech_direction) {
        case 0:
            texture->loadFromFile("assets/images/beetsaber/bas.png");
            key = sf::Keyboard::Key::Down;
            break;
        case 1:
            texture->loadFromFile("assets/images/beetsaber/droite.png");
            key = sf::Keyboard::Key::Right;
            break;
        case 2:
            texture->loadFromFile("assets/images/beetsaber/haut.png");
            key = sf::Keyboard::Key::Up;
            break;
        case 3:
            texture->loadFromFile("assets/images/beetsaber/gauche.png");
            key = sf::Keyboard::Key::Left;
            break;
        default:
            break;
    }
    sprite.setTexture(*texture);
    sprite.setScale(0.2, 0.2);
    sprite.setPosition(x + (int) (X_MAX / 4), -y);
}

CubeComming::~CubeComming()
{
    //delete (texture);
}

void CubeComming::update(float delatime)
{
    sf::Vector2f pos;

    times += delatime;
    if (is_touched == false && times > 1.0 / 30.0) {
        times = 0.0;
        sprite.move(0, 5);
        pos = sprite.getPosition();
        sprite.setScale((pos.y / 800.0 / RATIO_SCALE) + SCALE_OFFSET, (pos.y / 800.0 / RATIO_SCALE) + SCALE_OFFSET);
    }
}

bool CubeComming::check_collision(sf::RenderWindow *window, bool *first_flech)
{
    bool ret_value = false;
    sf::FloatRect boundssprite;

    if (is_touched == false && sf::Keyboard::isKeyPressed(key)) {
        boundssprite = sprite.getGlobalBounds();
        if (*first_flech == false) {
            ret_value = true;
            *first_flech = true;
        }
        if (boundssprite.top < Y_MAX && boundssprite.top > Y_MAX - PAD_SPACE_KEY) {
            is_touched = true;
        }
    }
    return (ret_value);
}

void CubeComming::draw(sf::RenderWindow *window)
{
    if (is_touched == false) {
        window->draw(sprite);
    }
}