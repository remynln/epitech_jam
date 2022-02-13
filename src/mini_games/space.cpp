/*
** EPITECH PROJECT, 2022
** mainGame
** File description:
** main
*/

#include "../../headers/Game.hpp"
#include "../../headers/Space.hpp"
#include <iostream>
#include <vector>
#include <list>

int poubelle::loop(void *scene)
{
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        ((Scenario *) scene)->checkSuccessDelete(event, window);
    }
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

void poubelle::draw(void *scene)
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
    ((Scenario *) scene)->displaySuccess(this->window);
    window->display();
}