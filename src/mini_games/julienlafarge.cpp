/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** julien lafarge
*/

#include "../../headers/Scenario.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>

void Scenario::JulienLaFarge(sf::RenderWindow *window)
{
    sf::Texture texture_lafarge;
    sf::Texture texture_julien;
    sf::Event event;
    sf::Font font;
    sf::Text text;
    sf::FloatRect rect;
    int scene_max = 2;
    int curr_dialog = 0;
    std::wstring dialog[] = {
        L"Aujourd'hui c'est David Lafarge, On se Retrouve avec un Individu de KALITAY",
        L"JULIENNNNNNNN!!!!!!!!"
    };
    
    texture_lafarge.loadFromFile("assets/images/julienlafarge/LAFARGE.png");
    sf::Sprite sprite_lafarge(texture_lafarge);
    rect = sprite_lafarge.getGlobalBounds();
    sprite_lafarge.setOrigin(rect.width / 2, rect.height / 2);
    sprite_lafarge.setPosition(rect.width / 2, rect.height / 2);
    texture_julien.loadFromFile("assets/images/julienlafarge/JULIEN.png");
    sf::Sprite sprite_julien(texture_julien);
    rect = sprite_julien.getGlobalBounds();
    sprite_julien.setOrigin(rect.width / 2, rect.height / 2);
    sprite_julien.setPosition(rect.width / 2, rect.height / 2);
    font.loadFromFile("assets/Roboto.ttf");
    text.setFont(font);
    text.setCharacterSize(30);
    while (window->isOpen() && curr_dialog < scene_max) {
        window->clear();
        text.setString(dialog[curr_dialog]);
        sprite_julien.rotate(0.1);
        sprite_lafarge.rotate(-0.1);
        window->draw(sprite_lafarge);
        if (curr_dialog != 0) {
            window->draw(sprite_julien);
        }
        window->draw(text);
        window->display();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window->close();
            } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Return) {
                curr_dialog += 1;
            }
        }
    }
    _inScenario = false;
}