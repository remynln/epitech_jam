/*
** EPITECH PROJECT, 2022
** johann_push
** File description:
** DecisionWall
*/

#include "DecisionWall.hpp"

DecisionWall::~DecisionWall()
{
}

bool DecisionWall::isInWall(sf::Vector2f vect) 
{
    return (vect.y < this->_y);
}

void DecisionWall::checkCollisions() 
{
    sf::Vector2f pos = this->_game.player.pos;
    for (Door *door : this->_doors) {
        door->checkCollisions(pos);
    }
}

void DecisionWall::renderDoors() 
{
    for (Door *door : _doors) {
        door->sprite.setPosition(sf::Vector2f(door->x1, door->yOffset + this->_y) - _game.player.pos);
        _game.win.draw(door->sprite);
    }
}

DecisionWall::DecisionWall(float y, std::vector<Door *> doors, Game &game) : _y(y), _game(game), _doors(doors)
{
    
}

Door::Door(float _x1, float _x2, std::string _imagefile, void (*_callback)()) 
    : x1(_x1), x2(_x2), callback(_callback)
{
    this->tex = sf::Texture();
    this->sprite = sf::Sprite();

    this->tex.loadFromFile(_imagefile);
    sf::Vector2u imageSize = this->tex.getSize();
    float ratio = ((x2 - x1) / (float) imageSize.x);
    this->sprite.setTexture(tex);
    this->sprite.setScale(sf::Vector2f(ratio, ratio));

    this->yOffset = (imageSize.y * ratio) / 2;
}

void Door::checkCollisions(sf::Vector2f const &/*pos*/) 
{
    if (this->sprite.getGlobalBounds().contains(sf::Vector2f(600, 400)))
        this->callback(); 
}
