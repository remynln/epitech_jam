//
// EPITECH PROJECT, 2022
// epitech jam
// File description:
// beet saber
//

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
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
#include "../../headers/Scenario.hpp"

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

static void event_handle(sf::RenderWindow *window, Scenario *scene)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        scene->checkSuccessDelete(event, window);
    }
}

static void start_beetsaber(sf::Text *text, sf::RenderWindow *window, Scenario *scene)
{
    sf::Clock clock;
    sf::Time time;
    sf::Texture texture;

    texture.loadFromFile("assets/images/beetsaber/REMY.jpg");
    sf::Sprite sprite(texture);
    sprite.setPosition((int) (X_MAX / 2) - 150, (int) (Y_MAX / 2) - 150);
    sprite.setScale(0.2, 0.2);
    clock.restart();
    time = clock.getElapsedTime();
    text->setString("Vous avez choisie de rencontrer Remy (champion du monde de BeatSaber) ! ...");
    while (window->isOpen() && time.asSeconds() < 4.0) {
        window->clear();
        window->draw(sprite);
        window->draw(*text);
        scene->displaySuccess(window);
        window->display();
        time = clock.getElapsedTime();
        event_handle(window, scene);
    }
    text->setString("Il vous propose de faire une partie...");
    clock.restart();
    time = clock.getElapsedTime();
    while (window->isOpen() && time.asSeconds() < 4.0) {
        window->clear();
        window->draw(sprite);
        window->draw(*text);
        scene->displaySuccess(window);
        window->display();
        time = clock.getElapsedTime();
        event_handle(window, scene);
    }
}

static void loop_beetsaber(sf::Sprite *sprite, sf::Text *text, sf::RenderWindow *window, Scenario *scene)
{
    std::vector<CubeComming> cubes;
    sf::Clock clock;
    sf::Time time;
    sf::RectangleShape rect(sf::Vector2f(X_MAX, PAD_SPACE_KEY));
    bool first_flech = false;

    rect.setPosition(0, Y_MAX - PAD_SPACE_KEY);
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(10);
    for (int i = 0; i < NB_CUBES; i++) {
        cubes.push_back(CubeComming());
    }
    text->setString("Appui sur les fleches quand les cubes arrivent");
    while (window->isOpen() && !is_all_under_window(cubes)) {
        time = clock.restart();
        for (int i = 0; i < NB_CUBES; i++) {
            cubes.at(i).update(time.asSeconds());
            if (cubes.at(i).check_collision(&first_flech)) {
                scene->giveSuccess("Premier Appui sur une Fleche");
                scene->addSuccess(L"Bravo tu as \nappuyé pour la \npremière fois \nsur une touche \ndirectionnel", "assets/images/beetsaber/true_bas_blue.png");
            }
        }
        window->clear();
        window->draw(*sprite);
        window->draw(*text);
        for (int i = 0; i < NB_CUBES; i++) {
            cubes.at(i).draw(window);
        }
        window->draw(rect);
        scene->displaySuccess(window);
        window->display();
        event_handle(window, scene);
    }
}

static void end_beetsaber(sf::Sprite *sprite, sf::Text *text, sf::RenderWindow *window, Scenario *scene)
{
    sf::Clock clock;
    sf::Time time;

    time = clock.getElapsedTime();
    text->setString("\nPar felix le chat chanceux de la chance,\ntu gagnes!!"
                    "\n\nAyant battu le champion du monde Remy, tu fais finalement carriere dans le gaming");
    while (window->isOpen() && time.asSeconds() < 5.0) {
        window->clear();
        window->draw(*sprite);
        window->draw(*text);
        scene->displaySuccess(window);
        window->display();
        time = clock.getElapsedTime();
        event_handle(window, scene);
    }
}

void Scenario::BeetSaber_MiniGame(sf::RenderWindow *window)
{
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font;
    sf::Text text;

    if (set_basic(&texture, &sprite, &font, &text) == 84) {
        return;
    }
    this->giveSuccess("Rencontre Avec Remy");
    this->addSuccess(L"GG tu as \nrencontré \nREMY.pnj", "assets/images/beetsaber/REMY.jpg");
    start_beetsaber(&text, window, this);
    loop_beetsaber(&sprite, &text, window, this);
    end_beetsaber(&sprite, &text, window, this);
    this->giveSuccess("Joueur Pro de beat saber");
    this->addSuccess(L"Tu es \ndevenu un \njoueur pro de \nbeatsaber", "assets/images/beetsaber/beetsaber_bg.png");
    _inScenario = false;
}

