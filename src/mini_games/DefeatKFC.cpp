/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** DefeatKFC
*/

#include "../../headers/DefeatKFC.hpp"

DefeatKFC::DefeatKFC()
{
    _score = 0;
    _bg_texture.loadFromFile("assets/images/defeatKFC/background.png");
    _bg_sprite.setTexture(_bg_texture);
    _bucket_texture.loadFromFile("assets/images/defeatKFC/bucket.png");
    _bucket_sprite.setTexture(_bucket_texture);
    _bucket_sprite.setPosition(1100, 700);
    _chicken_texture.loadFromFile("assets/images/defeatKFC/chicken.png");
    _chicken_sprite.setTexture(_chicken_texture);
    _chicken_sprite.setPosition(175, 475);
    _going_left = true;
    _is_flying = false;
    _is_won = false;
    _move_chicken = false;
    _vector.x = 0;
    _vector.y = 0;
}

DefeatKFC::~DefeatKFC()
{
}

void DefeatKFC::eventHandelling(sf::RenderWindow *window)
{
    sf::Event event;
    sf::Vector2i pos;

    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::MouseButtonPressed && !this->_is_flying) {
            pos = sf::Mouse::getPosition(*window);
            this->_chicken_sprite.setPosition(pos.x, pos.y);
            this->_move_chicken = true;
        }
        if (this->_move_chicken && event.type == sf::Event::MouseMoved) {
            pos = sf::Mouse::getPosition(*window);
            this->_chicken_sprite.setPosition(pos.x - 25, pos.y - 25);
        }
        if (this->_move_chicken && event.type == sf::Event::MouseButtonReleased) {
            pos = sf::Mouse::getPosition(*window);
            this->_move_chicken = false;
            this->_is_flying = true;
            this->_vector.x = (200 - pos.x) * 0.005;
            this->_vector.y = (500 - pos.y) * 0.005;
        }
    }
}

void DefeatKFC::displayWindow(sf::RenderWindow *window)
{
    window->clear();
    window->draw(this->_bg_sprite);
    window->draw(this->_chicken_sprite);
    window->draw(this->_bucket_sprite);
    window->display();
}

void DefeatKFC::moveSprites()
{
    sf::Time time = this->clock.restart();
    sf::Vector2f pos;
    sf::Vector2f bucket_pos;

    if (this->_going_left)
        this->_bucket_sprite.move(-(time.asMilliseconds()) * 1.5, 0);
    else
        this->_bucket_sprite.move((time.asMilliseconds()) * 1.5, 0);
    if (this->_going_left && this->_bucket_sprite.getPosition().x < 400)
        this->_going_left = false;
    if (!this->_going_left && this->_bucket_sprite.getPosition().x > 1000)
        this->_going_left = true;
    this->_chicken_sprite.move(this->_vector);
    pos = this->_chicken_sprite.getPosition();
    bucket_pos = this->_bucket_sprite.getPosition();
    if (pos.x > bucket_pos.x - 50 && pos.x < bucket_pos.x + 100 &&
    pos.y > bucket_pos.y - 50 && pos.y < bucket_pos.y + 50)
        this->_is_won = true;
    if (this->_is_flying)
        this->_vector.y += 0.0005;
    if (pos.x < 0 || pos.x > 1150 || pos.y < 0 || pos.y > 750) {
        this->_chicken_sprite.setPosition(175, 475);
        this->_vector.x = 0;
        this->_vector.y = 0;
        this->_is_flying = false;
    }
}

bool DefeatKFC::checkWon()
{
    return (this->_is_won);
}
