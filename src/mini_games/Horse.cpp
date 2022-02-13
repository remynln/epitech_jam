/*
** EPITECH PROJECT, 2022
** git
** File description:
** Horse
*/

#include <iostream>
#include "Horse.hpp"

Barrier::Barrier(float offset) 
{
    this->tex = new sf::Texture();
    this->tex->loadFromFile("assets/barrier.png");
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*this->tex);
    this->sprite->setOrigin(sf::Vector2f(20, 200));
    this->sprite->setPosition(offset, 600);
}

void Barrier::stop() 
{
    if (this->sprite->getRotation() != 0)
        return;
    this->sprite->rotate(10);
}

void Barrier::render(sf::RenderWindow *win, float prop)
{
    this->sprite->move(sf::Vector2f(-1.8, 0));
    win->draw(*this->sprite);
    if (prop < 5 && this->sprite->getPosition().x < 400 && this->sprite->getPosition().x > 395) {
        this->stop();
    }
    if (this->sprite->getRotation() != 0 && this->sprite->getRotation() < 90) {
        this->sprite->rotate(2);
    }
}

HorseBackground::HorseBackground(float offset) 
{

    this->tex = new sf::Texture();
    this->tex->loadFromFile("assets/HorseBg.png");
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*this->tex);
    this->sprite->setScale(sf::Vector2f((float) 800 / (float) 220, (float) 800 / (float) 220));
    this->sprite->setPosition(sf::Vector2f(offset, 0));
}

void HorseBackground::render(sf::RenderWindow *win) 
{
    sf::Vector2f pos = this->sprite->getPosition();
    if (pos.x + 2876 < 0) {
        this->sprite->setPosition(sf::Vector2f(1200, 0));
    } else {
        this->sprite->setPosition(pos + sf::Vector2f(-1.8, 0));
    }
    win->draw(*this->sprite);
}

Horse::Horse()
    : horseSprite(new sf::Sprite()),
    barriers({
        new Barrier(2000),
        new Barrier(3000),
        new Barrier(4000),
        new Barrier(5000)
    })
{
    for (size_t i = 0; i < 12; i++) {
        this->horseTex[i] = new sf::Texture();
        this->horseTex[i]->loadFromFile("assets/horse.png",
            sf::IntRect(
                600 * i, 0, 600, 239
        ));
    }
    this->horseSprite->setPosition(sf::Vector2f(0, 340));
    for (size_t i = 0; i < 2; i++) {
        this->bg[i] = new HorseBackground(i * 2876);
    }

}

Horse::~Horse()
{
}

void Horse::renderHorse(sf::RenderWindow *window) 
{
    sf::Event event;

    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::KeyPressed && this->propulsion == -667) {
            this->propulsion = 10;
        }
    }
    this->horseFrame += 0.02;
    if (this->horseFrame >= 12)
        this->horseFrame = 0;
    this->horseSprite->setTexture(*this->horseTex[(int) this->horseFrame]);
    sf::Vector2f horsePos = this->horseSprite->getPosition();
    if (horsePos.y >= 340 && this->propulsion <= 0) {
        this->horseSprite->setPosition(sf::Vector2f(0, 340));
        this->propulsion = -667;
    } else {
        this->propulsion -= 0.07;
        this->horseSprite->move(sf::Vector2f(0, -propulsion * 0.5));
    }
    window->clear();
    for (size_t i = 0; i < 2; i++)
        this->bg[i]->render(window);
    for (Barrier *bar : this->barriers) {
        bar->render(window, this->propulsion);
    }
    window->draw(*this->horseSprite);
    window->display();
}