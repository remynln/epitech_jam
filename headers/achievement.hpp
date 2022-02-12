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

class Success
{
    public:
        Success();
        ~Success();

        void displaySuccess(std::wstring text, std::string path, std::string audio = "ressources/baptiste.ogg");
    private:
        sf::RenderWindow _win;
        sf::Text _text;
        sf::Font _font;
        sf::Event _event;
        sf::Texture _monkeyT;
        sf::Texture _bananaT;
        sf::Sprite _monkeyS;
        sf::Sprite _bananaS;
        //sf::SoundBuffer _sb;
        //sf::Sound _sound;
};