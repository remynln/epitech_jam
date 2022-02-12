/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** ScriptChoice
*/

#include "../headers/ScriptChoice.hpp"

ScriptChoice::ScriptChoice(std::string filename, std::string dialog) {
    _font.loadFromFile("assets/Roboto.ttf");
    _bg_texture.loadFromFile(filename);
    _bg_sprite.setTexture(_bg_texture);
    _dialog = dialog;
    _dialog_disp.setString(_dialog);
    _dialog_disp.setPosition(20, 20);
    _dialog_disp.setCharacterSize(30);
    _dialog_disp.setFont(_font);
    _ret = "";
}

ScriptChoice::ScriptChoice(std::string filename, std::string dialog, std::string a) {
    _font.loadFromFile("assets/Roboto.ttf");
    _bg_texture.loadFromFile(filename);
    _bg_sprite.setTexture(_bg_texture);
    _dialog = dialog;
    _dialog_disp.setString(_dialog);
    _dialog_disp.setPosition(20, 20);
    _dialog_disp.setCharacterSize(30);
    _dialog_disp.setFont(_font);
    _choice_text.push_back(a);
    _choice_text_disp.push_back(new sf::Text(a, _font, 20));
    int c = 0;
    for (sf::Text *curr : _choice_text_disp) {
        curr->setPosition(50 + (600 * (c % 2)), 100 + (100 * (c / 2)));
        c++;
    }
    _ret = "";
}

ScriptChoice::ScriptChoice(std::string filename, std::string dialog, std::string a, std::string b) {
    _font.loadFromFile("assets/Roboto.ttf");
    _bg_texture.loadFromFile(filename);
    _bg_sprite.setTexture(_bg_texture);
    _dialog = dialog;
    _dialog_disp.setString(_dialog);
    _dialog_disp.setPosition(20, 20);
    _dialog_disp.setCharacterSize(30);
    _dialog_disp.setFont(_font);
    _choice_text.push_back(a);
    _choice_text.push_back(b);
    _choice_text_disp.push_back(new sf::Text(a, _font, 20));
    _choice_text_disp.push_back(new sf::Text(b, _font, 20));
    int c = 0;
    for (sf::Text *curr : _choice_text_disp) {
        curr->setPosition(50 + (600 * (c % 2)), 100 + (100 * (c / 2)));
        c++;
    }
    _ret = "";
}

ScriptChoice::ScriptChoice(std::string filename, std::string dialog, std::string a, std::string b, std::string c) {
    _font.loadFromFile("assets/Roboto.ttf");
    _bg_texture.loadFromFile(filename);
    _bg_sprite.setTexture(_bg_texture);
    _dialog = dialog;
    _dialog_disp.setString(_dialog);
    _dialog_disp.setPosition(20, 20);
    _dialog_disp.setCharacterSize(30);
    _dialog_disp.setFont(_font);
    _choice_text.push_back(a);
    _choice_text.push_back(b);
    _choice_text.push_back(c);
    _choice_text_disp.push_back(new sf::Text(a, _font, 20));
    _choice_text_disp.push_back(new sf::Text(b, _font, 20));
    _choice_text_disp.push_back(new sf::Text(c, _font, 20));
    int i = 0;
    for (sf::Text *curr : _choice_text_disp) {
        curr->setPosition(50 + (600 * (i % 2)), 100 + (100 * (i / 2)));
        i++;
    }
    _ret = "";
}

ScriptChoice::ScriptChoice(std::string filename, std::string dialog, std::string a, std::string b, std::string c, std::string d) {
    _font.loadFromFile("assets/Roboto.ttf");
    _bg_texture.loadFromFile(filename);
    _bg_sprite.setTexture(_bg_texture);
    _dialog = dialog;
    _dialog_disp.setString(_dialog);
    _dialog_disp.setPosition(20, 20);
    _dialog_disp.setCharacterSize(30);
    _dialog_disp.setFont(_font);
    _choice_text.push_back(a);
    _choice_text.push_back(b);
    _choice_text.push_back(c);
    _choice_text.push_back(d);
    _choice_text_disp.push_back(new sf::Text(a, _font, 20));
    _choice_text_disp.push_back(new sf::Text(b, _font, 20));
    _choice_text_disp.push_back(new sf::Text(c, _font, 20));
    _choice_text_disp.push_back(new sf::Text(d, _font, 20));
    int i = 0;
    for (sf::Text *curr : _choice_text_disp) {
        curr->setPosition(50 + (600 * (i % 2)), 100 + (100 * (i / 2)));
        i++;
    }
    _ret = "";
}

ScriptChoice::ScriptChoice(std::string filename, std::string dialog, std::string a, std::string b, std::string c, std::string d, std::string e) {
    _font.loadFromFile("assets/Roboto.ttf");
    _bg_texture.loadFromFile(filename);
    _bg_sprite.setTexture(_bg_texture);
    _dialog = dialog;
    _dialog_disp.setString(_dialog);
    _dialog_disp.setPosition(20, 20);
    _dialog_disp.setCharacterSize(30);
    _dialog_disp.setFont(_font);
    _choice_text.push_back(a);
    _choice_text.push_back(b);
    _choice_text.push_back(c);
    _choice_text.push_back(d);
    _choice_text.push_back(e);
    _choice_text_disp.push_back(new sf::Text(a, _font, 20));
    _choice_text_disp.push_back(new sf::Text(b, _font, 20));
    _choice_text_disp.push_back(new sf::Text(c, _font, 20));
    _choice_text_disp.push_back(new sf::Text(d, _font, 20));
    _choice_text_disp.push_back(new sf::Text(e, _font, 20));
    int i = 0;
    for (sf::Text *curr : _choice_text_disp) {
        curr->setPosition(50 + (600 * (i % 2)), 100 + (100 * (i / 2)));
        i++;
    }
    _ret = "";
}

ScriptChoice::~ScriptChoice()
{
}

std::string ScriptChoice::choose(sf::RenderWindow *window)
{
    while (true) {
        this->eventHandelling(window);
        if (!window->isOpen())
            return "";
        if (this->checkEnd())
            return this->_ret;
        this->displayWindow(window);
    }
}

void ScriptChoice::eventHandelling(sf::RenderWindow *window)
{
    sf::Event event;
    sf::Vector2i pos;
    int c = 0;

    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::MouseButtonPressed) {
            pos = sf::Mouse::getPosition(*window);
            for (sf::Text *curr : _choice_text_disp) {
                if (50 + (600 * (c % 2)) < pos.x && pos.x < 50 + (600 * (c % 2)) + 400 &&
                100 + (100 * (c / 2)) < pos.y && pos.y < 100 + (100 * (c / 2)) + 80)
                    this->_ret = curr->getString();
                c++;
            }
        }
    }
}

void ScriptChoice::displayWindow(sf::RenderWindow *window)
{
    window->clear();
    window->draw(this->_bg_sprite);
    window->draw(this->_dialog_disp);
    for (sf::Text *curr : _choice_text_disp)
        window->draw(*curr);
    window->display();
}

bool ScriptChoice::checkEnd()
{
    if (this->_ret != "")
        return (true);
    return (false);
}