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

class KinderBueno {
    public:
    sf::Sprite KinderBuenoSprite;
    sf::Texture *KinderBuenoTexture;
    sf::Vector2f dir;
    KinderBueno(float x, float y, float playerx, float playery) {
        dir.x = (playerx - x) / 1000;
        dir.y = (playery - y) / 1000;
        KinderBuenoTexture = new sf::Texture;
        KinderBuenoTexture->loadFromFile("assets/kinderbueno.png");
        KinderBuenoSprite.setTexture(*KinderBuenoTexture);
        KinderBuenoSprite.setScale(0.1, 0.1);
        KinderBuenoSprite.setPosition(x, y);
        KinderBuenoSprite.rotate(0);
    }
    ~KinderBueno() = default;
};

class boss {
    public:
    sf::Sprite bossSprite;
    sf::Texture *bossTexture;
    int _id;
    float moveDelay;
    float kinderDelay;
    int lastMove;
    std::vector<KinderBueno> kinders;
    sf::RectangleShape rec_out;
    sf::RectangleShape rec_in;
    int _hp;
    boss() {
        bossTexture = new sf::Texture;
        bossTexture->loadFromFile("assets/boss.png");
        bossSprite.setTexture(*bossTexture);
        bossSprite.setScale(0.5, 0.5);
        bossSprite.setPosition(600, 0);
        rec_out = sf::RectangleShape(sf::Vector2f(300.f, 25.f));
        rec_in = sf::RectangleShape(sf::Vector2f(300.f, 25.f));
        rec_out.setPosition(600, 10);
        rec_in.setPosition(rec_out.getPosition());
        rec_out.setFillColor(sf::Color::Transparent);
        rec_out.setOutlineThickness(5.f);
        rec_out.setOutlineColor(sf::Color::Black);
        rec_in.setFillColor(sf::Color::Red);
        moveDelay = 0;
        kinderDelay = 0;
        _hp = 20;
        lastMove = rand() % 2;
    }
    ~boss() = default;
};

class life {
    public:
    life(int x, int y) {
        heartTexture = new sf::Texture;
        heartTexture->loadFromFile("assets/heart.png");
        heartSprite.setTexture(*heartTexture);
        heartSprite.setPosition(x, y);
        heartSprite.setScale(0.2, 0.2);
    }
    ~life() = default;
    sf::Texture *heartTexture;
    sf::Sprite heartSprite;
};

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
        ennemyTexture->loadFromFile("assets/ennemy.png");
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
    sf::Sprite bulletSprite;
    sf::Texture *bulletTexture;
    bullet(const sf::Vector2f &test) {
        bulletTexture = new sf::Texture;
        bulletTexture->loadFromFile("assets/fireball.png");
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
    std::vector<life> _hearts;
    int _hp;
    boss Johann;
    int phase;
    int ennemyKilled;
    poubelle() {
        window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Space mini game");
        movement = {0, 0};
        timestep = 1.0f / 60.0f;
        _hp = 6;
        phase = 0;
        ennemyKilled = 0;
        _hearts.push_back(life(1200 - 50, 0));
        _hearts.push_back(life(1200 - 105, 0));
        _hearts.push_back(life(1200 - 160, 0));
        _hearts.push_back(life(1200 - 220, 0));
        _hearts.push_back(life(1200 - 265, 0));
        _hearts.push_back(life(1200 - 320, 0));
        backgroundTexture.loadFromFile("assets/space_background.jpg");
        backgroundSprite.setTexture(backgroundTexture);

        spaceShipTexture.loadFromFile("assets/space_ship.png");
        spaceShipSprite.setTexture(spaceShipTexture);
        spaceShipSprite.setScale(0.2, 0.2);
        spaceShipSprite.setPosition(1280 / 2 - spaceShipSprite.getGlobalBounds().width, 600);
    }
    ~poubelle() = default;
    int loop();
    void draw();
};

int poubelle::loop()
{
    while (window->pollEvent(event))
        if (event.type == sf::Event::Closed)
            window->close();
    if (phase == 0 && ennemyDelay <= 0) {
        ennemies.push_back(ennemy(rand() % 1200 - 100 , 0));
        ennemyDelay = 1;
    }
    if (phase == 1) {
        if (Johann.moveDelay <= 0) {
            if (Johann.lastMove == 1 && rand() % 10 <= 8) {
                if (Johann.bossSprite.getPosition().x + 10 < 1200 - Johann.bossSprite.getGlobalBounds().width) {
                    if (Johann._hp <= 10)
                        window->setPosition(sf::Vector2i(window->getPosition().x - 10, window->getPosition().y));
                    Johann.bossSprite.move(10, 0);
                    Johann.lastMove = 1;
                }
                else {
                    if (Johann._hp <= 10)
                        window->setPosition(sf::Vector2i(window->getPosition().x + 10, window->getPosition().y));
                    Johann.bossSprite.move(-10, 0);
                    Johann.lastMove = 0;
                }
            }
            else {
                if (Johann.bossSprite.getPosition().x - 10 > 0) {
                    if (Johann._hp <= 10)
                        window->setPosition(sf::Vector2i(window->getPosition().x + 10, window->getPosition().y));
                    Johann.bossSprite.move(-10, 0);
                    Johann.lastMove = 0;   
                }
                else {
                    if (Johann._hp <= 10)
                        window->setPosition(sf::Vector2i(window->getPosition().x - 10, window->getPosition().y));
                    Johann.bossSprite.move(10, 0);
                    Johann.lastMove = 1;
                }
            }
            Johann.moveDelay = 20;
        }
    }
    Johann.moveDelay -= 1;
    ennemyDelay -= 0.01;
    accumulator += clock.restart().asSeconds();
    while (accumulator >= timestep) {
        accumulator -= timestep;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) &&
        spaceShipSprite.getPosition().x - 10 > 0) {
            if (Johann._hp <= 10)
                window->setPosition(sf::Vector2i(window->getPosition().x + 10, window->getPosition().y));
            spaceShipSprite.move(-10, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
        spaceShipSprite.getPosition().x + 10 < 1200 - spaceShipSprite.getGlobalBounds().width) {
            if (Johann._hp <= 10)
                window->setPosition(sf::Vector2i(window->getPosition().x - 10, window->getPosition().y));
            spaceShipSprite.move(10, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) &&
        spaceShipSprite.getPosition().y - 10 > 0) {
            if (Johann._hp <= 10)
                window->setPosition(sf::Vector2i(window->getPosition().x, window->getPosition().y + 10));
            spaceShipSprite.move(0, -10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
        spaceShipSprite.getPosition().y + 10 < 700) {
            if (Johann._hp <= 10)
                window->setPosition(sf::Vector2i(window->getPosition().x, window->getPosition().y - 10));
            spaceShipSprite.move(0, 10);
        }
        if (rocketDelay <= 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            bullets.push_back(bullet(spaceShipSprite.getPosition()));
            rocketDelay = 1;
        }
    }
    rocketDelay -= 0.01;
    if (Johann.kinderDelay <= 0 && phase == 1) {
            Johann.kinders.push_back(KinderBueno(Johann.bossSprite.getPosition().x + Johann.bossSprite.getGlobalBounds().width, Johann.bossSprite.getPosition().y + Johann.bossSprite.getGlobalBounds().height
            ,spaceShipSprite.getPosition().x, spaceShipSprite.getPosition().y));
            Johann.kinderDelay = 5;
    }
    Johann.kinderDelay -= 0.01;
    for (auto ennemy = ennemies.begin(); ennemy != ennemies.end(); ++ennemy) {
        for (auto bullet = bullets.begin(); bullet != bullets.end(); ++bullet) {
            if (ennemy->ennemySprite.getGlobalBounds().intersects(bullet->bulletSprite.getGlobalBounds())) {
                bullets.erase(bullet);
                ennemies.erase(ennemy++);
                ennemyKilled++;
                break;
            }
        }
        if (ennemy->ennemySprite.getGlobalBounds().intersects(spaceShipSprite.getGlobalBounds())) {
            ennemies.erase(ennemy++);
            _hp -= 1;
        }
    }
    for (auto kinder = Johann.kinders.begin(); kinder != Johann.kinders.end(); ++kinder) {
        if (kinder->KinderBuenoSprite.getGlobalBounds().intersects(spaceShipSprite.getGlobalBounds())) {
            _hp -= 1;
            Johann.kinders.erase(kinder++);
            break;
        }
    }
    for (auto bullet = bullets.begin(); bullet != bullets.end(); ++bullet) {
        if (phase == 1 && bullet->bulletSprite.getGlobalBounds().intersects(Johann.bossSprite.getGlobalBounds())) {
            Johann._hp -= 1;
            bullets.erase(bullet++);
            Johann.rec_in.setSize(sf::Vector2f(Johann.rec_in.getSize().x - 15, Johann.rec_in.getSize().y));
            break;
        }
    }
    if (_hp <= 0) {
        window->close();
        return -1;
    }
    if (Johann._hp <= 0) {
        window->close();
        return 1;
    }
    for (auto it = bullets.begin(); it != bullets.end(); ++it) {
        if (it->bulletSprite.getGlobalBounds().height > 0)
            it->bulletSprite.move(0, -2);
        else 
            bullets.erase(it++);
    }
    for (auto kinder = Johann.kinders.begin(); kinder != Johann.kinders.end(); ++kinder) {
        if (kinder->KinderBuenoSprite.getGlobalBounds().height < 1200)
            kinder->KinderBuenoSprite.move(kinder->dir);
        else
            Johann.kinders.erase(kinder++);
    }
    for (auto ennemy = ennemies.begin(); ennemy != ennemies.end(); ++ennemy) {
        if (ennemy->ennemySprite.getPosition().y + 10 < 900)
            ennemy->ennemySprite.move(0, 1);
        else
            ennemies.erase(ennemy++);
    }
    Johann.rec_out.setPosition(Johann.bossSprite.getPosition().x, Johann.bossSprite.getPosition().y + 30);
    Johann.rec_in.setPosition(Johann.rec_out.getPosition());
    if (ennemyKilled > 10)
        phase = 1;
    return 0;
}

void poubelle::draw()
{
    window->clear();
    window->draw(backgroundSprite);
    for (auto &bullet : bullets)
        window->draw(bullet.bulletSprite);
    for (auto &kinder : Johann.kinders)
        window->draw(kinder.KinderBuenoSprite);
    for (auto &ennemy : ennemies)
        window->draw(ennemy.ennemySprite);
    if (phase == 1) {
        window->draw(Johann.bossSprite);
        window->draw(Johann.rec_in);
        window->draw(Johann.rec_out);
    }
    for (int i = 0; i < _hp; i++)
        window->draw(_hearts[i].heartSprite);
    window->draw(spaceShipSprite);
    window->display();
}

int main(void)
{
    poubelle oui;
    srand(time(0));
    int ret = 0;
    while (oui.window->isOpen()) {
        ret = oui.loop();
        oui.draw();
        if (ret)
            return 1;
        if (ret == -1)
            return 0;
    }
    return 0;
}