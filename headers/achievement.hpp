/*
** EPITECH PROJECT, 2022
** game_jam
** File description:
** achievement.hpp
*/

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class success
{
public:
    success(std::wstring text, std::string path, std::string audio="assets/baptiste.ogg");
    ~success();
    void displaySuccess(sf::RenderWindow &win, int i);
    bool _firstCall = true;
    sf::Text _text;
    sf::Font _font;
    sf::RectangleShape _rect;
    sf::Texture _monkeyT;
    sf::Texture _bananaT;
    sf::Texture _crossT;
    sf::RectangleShape _crossS;
    sf::Sprite _monkeyS;
    sf::Sprite _bananaS;
    sf::SoundBuffer _sb;
    sf::Sound _sound;
};