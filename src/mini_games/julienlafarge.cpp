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

static void set_sprite(sf::Sprite *sprite)
{
    sf::FloatRect rect;

    rect = sprite->getGlobalBounds();
    sprite->setOrigin(rect.width / 2, rect.height / 2);
    sprite->setPosition((int) (1200 / 2), (int) (800 / 2));
}

static void set_text(sf::Text *text, sf::Font *font)
{
    font->loadFromFile("assets/Roboto.ttf");
    text->setFont(*font);
    text->setCharacterSize(30);
}

void Scenario::JulienLaFarge(sf::RenderWindow *window)
{
    sf::Texture texture_lafarge;
    sf::Texture texture_julien;
    sf::Texture texture_guy;
    sf::Event event;
    sf::Font font;
    sf::Text text;
    sf::FloatRect rect;
    int scene_max = 4;
    int curr_dialog = 0;
    std::wstring dialog[] = {
        L"Aujourd'hui c'est David Lafarge, On se Retrouve avec un Individu de KALITAY ...\nQue vous connaissez peut-être déjà\n(appui sur 'entrée')",
        L"JULIENNNNNNNN!!!!!!!!\n(appui sur 'entrée')",
        L"Et un autre Gens, ...\n(appui sur 'entrée')",
        L"Guy Guy (= toi)!!!"
    };
    
    texture_lafarge.loadFromFile("assets/images/julienlafarge/LAFARGE.png");
    sf::Sprite sprite_lafarge(texture_lafarge);
    set_sprite(&sprite_lafarge);
    texture_julien.loadFromFile("assets/images/julienlafarge/JULIEN.png");
    sf::Sprite sprite_julien(texture_julien);
    set_sprite(&sprite_julien);
    texture_guy.loadFromFile("assets/guy_guy.png");
    sf::Sprite sprite_guy(texture_guy);
    set_sprite(&sprite_guy);
    set_text(&text, &font);
    while (window->isOpen() && curr_dialog < scene_max) {
        window->clear();
        text.setString(dialog[curr_dialog]);
        sprite_julien.rotate(0.1);
        sprite_lafarge.rotate(-0.1);
        window->draw(sprite_lafarge);
        if (curr_dialog != 0) {
            window->draw(sprite_julien);
        }
        if (curr_dialog == 3) {
            window->draw(sprite_guy);
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