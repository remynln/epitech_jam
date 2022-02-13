//
// EPITECH PROJECT, 2022
// JAM
// File description:
// psykologue part
//

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "../../headers/Scenario.hpp"

static int set_basic(sf::Texture *texture, sf::Sprite *sprite, sf::Font *font, sf::Text *text)
{
    if (!texture->loadFromFile("assets/images/pshykoloke/psy.jpg")) {
        return (84);
    }
    sprite->setTexture(*texture);
    if (!font->loadFromFile("assets/Roboto.ttf")) {
        return (84);
    }
    text->setFont(*font);
    text->setCharacterSize(20);
    text->setFillColor(sf::Color::Black);
    return (0);
}

static void event_handle(sf::RenderWindow *window)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }
}

void Scenario::Psykoloke_MiniScene(sf::RenderWindow *window)
{
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font;
    sf::Text text;
    sf::Clock clock;
    sf::Time time;
    bool speak_mr = true;

    if (set_basic(&texture, &sprite, &font, &text) == 84) {
        return;
    }
    std::wstring str[] = {
        L"Pourquoi vivre ?\nPourquoi la vie ?\nPourquoi la non mort ?",
        L"Pensez à ce que vous avez bien fait,\nque pouvez vous dire de ce que vous avez bien fait."
    };

    for (int i = 0; i < 2; i++) {
        text.setString(str[i]);
        if (speak_mr) {
            text.setPosition(0, 0);
        } else {
            text.setPosition(50, 50);
        }
        speak_mr = !speak_mr;
        clock.restart();
        time = clock.getElapsedTime();
        while (window->isOpen() && time.asSeconds() < 5.0) {
            window->clear();
            window->draw(sprite);
            window->draw(text);
            window->display();
            time = clock.getElapsedTime();
            event_handle(window);
        }
    }
    ScriptChoice choice("assets/images/pshykoloke/psy.jpg", "Hummm.. Qu'est ce que je dis ?", "Je suis meilleur, laisse moi ta place", "Je suis le christ cosmique !");

    if (choice.choose(window) == "Je suis meilleur, laisse moi ta place")
        _name = "psyjob";
    else
        _name = "folie";
}

//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(1200, 800), "TEST");
//    Scenario scene;
//
//    scene.Psykoloke_MiniScene(&window);
//    return (0);
//}
