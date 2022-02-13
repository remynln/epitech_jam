/*
** EPITECH PROJECT, 2022
** epitech_jam
** File description:
** laruelavré
*/

#include "laruelavrai.hpp"
#include <iostream>

Button::Button(std::string str)
{
    this->rect.setSize(sf::Vector2f(95, 50));
    this->rect.setFillColor(sf::Color::Green);

    this->font.loadFromFile("assets/Roboto.ttf");
    this->text.setFont(this->font);
    this->text.setCharacterSize(30);
    this->text.setFillColor(sf::Color::Black);
    this->text.setStyle(sf::Text::Bold);
    this->text.setString(str);
}

Button::~Button()
{
}

LaRue::LaRue(sf::RenderWindow *win):
window(win)
{
    font.loadFromFile("assets/Roboto.ttf");
    score = 0;
    e_score = 0;
    t_background.loadFromFile("assets/koba_cite.png");
    s_background.setTexture(t_background);
    
    e_rect = sf::IntRect(0, 0, 204, 408);
    rect = sf::IntRect(e_rect);

    et_hands.loadFromFile("assets/rps.png");
    es_hands.setTexture(et_hands);
    es_hands.setOrigin(sf::Vector2f(es_hands.getGlobalBounds().width / 2, es_hands.getGlobalBounds().height / 2));
    
    t_hands.loadFromFile("assets/rps.png");
    s_hands.setTexture(t_hands);
    s_hands.setOrigin(sf::Vector2f(s_hands.getGlobalBounds().width / 2, s_hands.getGlobalBounds().height / 2));
    
    es_hands.setPosition(sf::Vector2f(200 + es_hands.getGlobalBounds().width / 2, 800 - es_hands.getGlobalBounds().height / 2));
    es_hands.setTextureRect(e_rect);

    s_hands.setPosition(sf::Vector2f(800 + s_hands.getGlobalBounds().width / 2, 800 - s_hands.getGlobalBounds().height / 2));
    s_hands.setTextureRect(rect);
    
    t_score.setFont(font);
    t_score.setCharacterSize(40);
    t_score.setFillColor(sf::Color::Black);
    t_score.setPosition(sf::Vector2f(700, 300));

    te_score.setFont(font);
    te_score.setCharacterSize(40);
    te_score.setFillColor(sf::Color::Black);
    te_score.setPosition(sf::Vector2f(300, 300));

    buttons.push_back(new Button("Rock"));
    buttons.push_back(new Button("Scisor"));
    buttons.push_back(new Button("Paper"));
    buttons[ROCK]->text.setPosition(sf::Vector2f(1000, 300));
    buttons[PAPER]->text.setPosition(sf::Vector2f(1000, 400));
    buttons[SCISOR]->text.setPosition(sf::Vector2f(1000, 500));
    buttons[ROCK]->rect.setPosition(sf::Vector2f(1000, 300));
    buttons[PAPER]->rect.setPosition(sf::Vector2f(1000, 400));
    buttons[SCISOR]->rect.setPosition(sf::Vector2f(1000, 500));

    t_score.setString("Your score : \n");
    te_score.setString("Enemy score : \n");
}

void LaRue::game()
{
    int random = rand() % 3;
    sf::IntRect h_rect(e_rect);

    h_rect.left = (random * 204);
    es_hands.setTextureRect(h_rect);
    if (choosen == ROCK && random == SCISOR ||
        choosen == PAPER && random == ROCK ||
        choosen == SCISOR && random == PAPER) {
        e_score++;
    } else if (choosen == ROCK && random == PAPER ||
        choosen == PAPER && random == SCISOR ||
        choosen == SCISOR && random == ROCK) {
        score++;
    } else if (choosen == ROCK && random == ROCK ||
        choosen == PAPER && random == PAPER ||
        choosen == SCISOR && random == SCISOR) {
        score += 0;
        e_score += 0;
    }
    t_score.setString("Your score : \n" + std::to_string(score));
    te_score.setString("Enemy score : \n" + std::to_string(e_score));
}

void LaRue::handle(sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        for (int i = 0; i < buttons.size(); i++) {
            sf::Rect<float> rect = buttons[i]->rect.getGlobalBounds();
            if (rect.contains(event.mouseButton.x, event.mouseButton.y)) {
                choosen = i;
                break;
            }
        }
        sf::IntRect h_rect(e_rect);

        h_rect.left = (choosen * 204);
        s_hands.setTextureRect(h_rect);
        game();
    }
}