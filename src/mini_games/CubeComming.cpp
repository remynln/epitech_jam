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
    std::string paths_blue[] = {
        "assets/images/beetsaber/true_bas_blue.png",
        "assets/images/beetsaber/true_droite_blue.png",
        "assets/images/beetsaber/true_haut_blue.png",
        "assets/images/beetsaber/true_gauche_blue.png"
    };
    std::string paths_red[] = {
        "assets/images/beetsaber/true_bas_red.png",
        "assets/images/beetsaber/true_droite_red.png",
        "assets/images/beetsaber/true_haut_red.png",
        "assets/images/beetsaber/true_gauche_red.png"
    };
    sf::Keyboard::Key keys[] = {
        sf::Keyboard::Key::Down,
        sf::Keyboard::Key::Right,
        sf::Keyboard::Key::Up,
        sf::Keyboard::Key::Left
    };
    if (rand() % 2 == 0) {
        texture->loadFromFile(paths_blue[flech_direction]);
    } else {
        texture->loadFromFile(paths_red[flech_direction]);
    }
    key = keys[flech_direction];
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

bool CubeComming::check_collision(bool *first_flech)
{
    bool ret_value = false;
    sf::FloatRect boundssprite;

    if (is_touched == false && sf::Keyboard::isKeyPressed(key)) {
        boundssprite = sprite.getGlobalBounds();
        if (*first_flech == false) {
            ret_value = true;
            *first_flech = true;
        }
        if (boundssprite.top < Y_MAX && boundssprite.top + boundssprite.height > Y_MAX - PAD_SPACE_KEY) {
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