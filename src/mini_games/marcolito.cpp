/*
** EPITECH PROJECT, 2022
** epitech_jam
** File description:
** marcolito
*/

#include "../../headers/Scenario.hpp"
#include "marcolito.hpp"

sf::CircleShape *create_circle(void)
{
    sf::CircleShape *shape = new sf::CircleShape(50.f);

    shape->setPosition(sf::Vector2f(((std::rand() % (1100 - 127)) + 127), ((std::rand() % (716 - 183)) + 193)));
    shape->setFillColor(sf::Color::Transparent);
    shape->setOutlineThickness(10.f);
    shape->setOutlineColor(sf::Color::White);
    sf::FloatRect globalBounds = shape->getGlobalBounds();
    shape->setOrigin(globalBounds.width / 2 , globalBounds.height / 2);
    return shape;
}

void Drug::hit(void)
{
    sf::Texture *text = new sf::Texture;
    sf::Sprite *sprite = new sf::Sprite;

    text->loadFromFile("assets/hits.png");
    sprite->setTexture(*text);
    sprite->setOrigin(sprite->getGlobalBounds().width / 2, sprite->getGlobalBounds().height / 2);
    sprite->setPosition(event.mouseButton.x, event.mouseButton.y);
    hits.push_back(sprite);
}

void Drug::mouse_click_handle(sf::Event::MouseButtonEvent event)
{
    sf::Rect<float> rect = circle->getGlobalBounds();
    sf::SoundBuffer *buff = new sf::SoundBuffer;
    sf::Sound *sound = new sf::Sound;
    std::string aie[3] = {"assets/aie1.ogg", "assets/aie2.ogg", "assets/aie3.ogg"};


    if (rect.contains(event.x, event.y)) {
        rec_in.setSize(sf::Vector2f(rec_in.getSize().x + 10, rec_in.getSize().y));
        hit();
        fr = 0;
    } else {
        life_in.setSize(sf::Vector2f(life_in.getSize().x - (300/5), life_in.getSize().y));
        buff->loadFromFile(aie[rand() % 3]);
        sound->setBuffer(*buff);
        sound->setVolume(100);
        sound->play();
    }
}

void Drug::mouse_move_handle(sf::Event::MouseMoveEvent event)
{
    s_ser.setPosition(event.x, event.y);
}

void Drug::event_handler(void)
{
    if (event.type == sf::Event::Closed) {
        window->close();
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        mouse_click_handle(event.mouseButton);
    }
    if (event.type == sf::Event::MouseMoved) {
        mouse_move_handle(event.mouseMove);
    }
    return;
}


Drug::Drug(sf::RenderWindow *win):
window(win),
life_out(sf::Vector2f(300.f, 50.f)),
life_in(sf::Vector2f(300.f, 50.f)),
rec_out(sf::Vector2f(300.f, 50.f)),
rec_in(sf::Vector2f(0.f, 50.f))
{
    gl = 3000;
    fr = 0;

    rec_out.setPosition(1200 - 350, 100);
    rec_in.setPosition(rec_out.getPosition());
    rec_out.setFillColor(sf::Color::Transparent);
    rec_out.setOutlineThickness(5.f);
    rec_out.setOutlineColor(sf::Color::Black);
    rec_in.setFillColor(sf::Color::Green);

    life_out.setPosition(1200 - 350, 20);
    life_in.setPosition(life_out.getPosition());
    life_out.setFillColor(sf::Color::Transparent);
    life_out.setOutlineThickness(5.f);
    life_out.setOutlineColor(sf::Color::Black);
    life_in.setFillColor(sf::Color::Red);

    music.openFromFile("assets/marcolito.ogg");
    music.setVolume(25);

    window->setMouseCursorVisible(false);
    ser.loadFromFile("assets/seringe.png");
    arm.loadFromFile("assets/arm.png");
    s_arm.setTexture(arm);
    s_ser.setTexture(ser);
    s_ser.setOrigin(15 , 175);
    music.play();
}

void Drug::display(void *scene)
{
    window->clear(sf::Color::Black);
    window->draw(s_arm);
    window->draw(*circle);
    window->draw(life_in);
    window->draw(life_out);
    window->draw(rec_in);
    window->draw(rec_out);
    for (sf::Sprite *prout: hits) {
        window->draw(*prout);
    }
    window->draw(s_ser);
    ((Scenario *) scene)->displaySuccess(window);
    window->display();
}
