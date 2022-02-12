//
// EPITECH PROJECT, 2022
// epitech jam
// File description:
// beet saber
//

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Types.h>
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

class CubeComming
{
    public:
    sf::Texture *texture;
    sf::Sprite sprite;
    sf::Keyboard::Key key;
    float times;
    int flech_direction;
    bool is_touched;

    CubeComming() {
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

    ~CubeComming()
    {
        //delete (texture);
    }

    void update(float delatime)
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

    void check_collision(sf::RenderWindow *window)
    {
        sf::FloatRect boundssprite;

        if (is_touched == false && sf::Keyboard::isKeyPressed(key)) {
            boundssprite = sprite.getGlobalBounds();
            if (boundssprite.top < Y_MAX && boundssprite.top > Y_MAX - PAD_SPACE_KEY) {
                is_touched = true;
            }
        }
    }

    void draw(sf::RenderWindow *window)
    {
        if (is_touched == false) {
            window->draw(sprite);
        }
    }
};

static bool is_all_under_window(std::vector<CubeComming> cubes)
{
    sf::FloatRect bounds;

    for (int i = 0; i < NB_CUBES; i++) {
        if (cubes.at(i).is_touched == true) {
            continue;
        }
        bounds = cubes.at(i).sprite.getGlobalBounds();
        if (bounds.top < Y_MAX) {
            return (false);
        }
    }
    return (true);
}

static int set_basic(sf::Texture *texture, sf::Sprite *sprite, sf::Font *font, sf::Text *text)
{
    if (!texture->loadFromFile("assets/images/beetsaber/beetsaber_bg.png")) {
        return (84);
    }
    sprite->setTexture(*texture);
    if (!font->loadFromFile("assets/Roboto.ttf")) {
        return (84);
    }
    text->setFont(*font);
    text->setCharacterSize(20);
    return (0);
}

static void start_beetsaber(sf::Text *text, sf::RenderWindow *window)
{
    sf::Clock clock;
    sf::Time time;

    time = clock.getElapsedTime();
    text->setString("Vous avez choisie de rencontrer Remy (champion du monde de BeatSaber) ! ...");
    while (time.asSeconds() < 4.0) {
        window->clear();
        window->draw(*text);
        window->display();
        time = clock.getElapsedTime();
    }
    text->setString("Il vous propose de faire une partie...");
    clock.restart();
    time = clock.getElapsedTime();
    while (time.asSeconds() < 4.0) {
        window->clear();
        window->draw(*text);
        window->display();
        time = clock.getElapsedTime();
    }
}

static void loop_beetsaber(sf::Sprite *sprite, sf::Text *text, sf::RenderWindow *window)
{
    std::vector<CubeComming> cubes;
    sf::Clock clock;
    sf::Time time;

    for (int i = 0; i < NB_CUBES; i++) {
        cubes.push_back(CubeComming());
    }
    text->setString("Appui sur les fleches quand les cubes arrivent");
    while (!is_all_under_window(cubes)) {
        time = clock.restart();
        for (int i = 0; i < NB_CUBES; i++) {
            cubes.at(i).update(time.asSeconds());
            cubes.at(i).check_collision(window);
        }
        window->clear();
        window->draw(*sprite);
        window->draw(*text);
        for (int i = 0; i < NB_CUBES; i++) {
            cubes.at(i).draw(window);
        }
        window->display();
    }
}

static void end_beetsaber(sf::Sprite *sprite, sf::Text *text, sf::RenderWindow *window)
{
    sf::Clock clock;
    sf::Time time;

    time = clock.getElapsedTime();
    text->setString("\nPar felix le chat chanceux de la chance,\ntu gagnes!!"
                    "\n\nAyant battu le champion du monde Remy, tu fais finalement carriere dans le gaming");
    while (time.asSeconds() < 5.0) {
        window->clear();
        window->draw(*sprite);
        window->draw(*text);
        window->display();
        time = clock.getElapsedTime();
    }
}

void beet_saber_game(sf::RenderWindow *window)
{
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font;
    sf::Text text;

    if (set_basic(&texture, &sprite, &font, &text) == 84) {
        return;
    }
    start_beetsaber(&text, window);
    loop_beetsaber(&sprite, &text, window);
    end_beetsaber(&sprite, &text, window);
    return;
}
