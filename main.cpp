/*
** EPITECH PROJECT, 2022
** mainGame
** File description:
** main
*/

#include "headers/Game.hpp"
#include <iostream>
#include <vector>
#include <list>

class ennemy {
    public:
    int _x;
    int _y;
    sf::Sprite ennemySprite;
    sf::Texture *ennemyTexture;
    int _id;
    ennemy(int x, int y) {
        _x = x;
        _y = y;
        static int id = 0;
        _id = id;
        id++;
        ennemyTexture = new sf::Texture;
        ennemyTexture->loadFromFile("ennemy.png");
        ennemySprite.setTexture(*ennemyTexture);
        ennemySprite.setScale(0.1, 0.1);
        ennemySprite.setPosition(x + ennemySprite.getGlobalBounds().width / 4, y);
    }
    ~ennemy() = default;
    bool operator==(const ennemy &toTest) {
        if (_id == toTest._id)
            return true;
        return false;
    }
};

class bullet {
    public:
    int _x;
    int _y;
    sf::Sprite bulletSprite;
    sf::Texture *bulletTexture;
    bullet(const sf::Vector2f &test) {
        _x = test.x;
        _y = test.y;
        bulletTexture = new sf::Texture;
        bulletTexture->loadFromFile("fireball.png");
        bulletSprite.setTexture(*bulletTexture);
        bulletSprite.setScale(0.2, 0.2);
        bulletSprite.setPosition(test.x + bulletSprite.getGlobalBounds().width / 4, test.y);
        bulletSprite.rotate(-90);
    }
    ~bullet() = default;
};

class poubelle {
    public:
    enum direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    sf::RenderWindow *window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Texture spaceShipTexture;
    sf::Sprite spaceShipSprite;
    sf::Clock clock;
    float timestep;
    sf::Vector2f movement;
    sf::Event event;
    float accumulator = 0;
    std::vector<bullet> bullets;
    std::list<ennemy> ennemies;
    float rocketDelay = 0;
    float ennemyDelay = 0;
    poubelle() {
        window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Space mini game");
        movement = {0, 0};
        timestep = 1.0f / 60.0f;
        backgroundTexture.loadFromFile("background.jpg");
        backgroundSprite.setTexture(backgroundTexture);

        spaceShipTexture.loadFromFile("space_ship.png");
        spaceShipSprite.setTexture(spaceShipTexture);
        spaceShipSprite.setScale(0.2, 0.2);
        spaceShipSprite.setPosition(1280 / 2 - spaceShipSprite.getGlobalBounds().width, 600);
    }
    ~poubelle() = default;
    void loop();
    void draw();
};

void poubelle::loop()
{
    while (window->pollEvent(event))
        if (event.type == sf::Event::Closed)
            window->close();
    if (ennemyDelay <= 0) {
        ennemies.push_back(ennemy(rand() % 1200 - 100 , 0));
        ennemyDelay = 1;
    }
    ennemyDelay -= 0.01;
    accumulator += clock.restart().asSeconds();
    while (accumulator >= timestep) {
        accumulator -= timestep;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) &&
        spaceShipSprite.getPosition().x - 10 > 0)
            spaceShipSprite.move(-10, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
        spaceShipSprite.getPosition().x + 10 < 1200 - spaceShipSprite.getGlobalBounds().width)
            spaceShipSprite.move(10, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
        spaceShipSprite.getPosition().y - 10 > 0)
            spaceShipSprite.move(0, -10);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
        spaceShipSprite.getPosition().y + 10 < 700)
            spaceShipSprite.move(0, 10);
        if (rocketDelay <= 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            bullets.push_back(bullet(spaceShipSprite.getPosition()));
            rocketDelay = 1;
        }
    }
    rocketDelay -= 0.01;
    for (auto it = ennemies.begin(); it != ennemies.end(); ++it) {
        for (auto &bullet : bullets) {
            if (it->ennemySprite.getGlobalBounds().intersects(bullet.bulletSprite.getGlobalBounds())) {
                ennemies.erase(it++);
            }
        }
    }
    for (auto &bullet : bullets) {
        if (bullet.bulletSprite.getGlobalBounds().height > 0)
            bullet.bulletSprite.move(0, -2);
    }
    for (auto &ennemy : ennemies) {
        if (ennemy.ennemySprite.getPosition().y + 10 < 900)
            ennemy.ennemySprite.move(0, 1);
    }
}

void poubelle::draw()
{
    window->clear();
    window->draw(backgroundSprite);
    for (auto &bullet : bullets)
        window->draw(bullet.bulletSprite);
    for (auto &ennemy : ennemies)
        window->draw(ennemy.ennemySprite);
    window->draw(spaceShipSprite);
    window->display();
}

int main(void)
{
    poubelle oui;
    while (oui.window->isOpen()) {
        oui.loop();
        oui.draw();
    }
    return 0;
}