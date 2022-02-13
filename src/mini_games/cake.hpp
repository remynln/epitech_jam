/*
** EPITECH PROJECT, 2022
** game_jam
** File description:
** cake.hpp
*/

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <random>

class cake
{
public:
    cake();
    ~cake();
    void startCake(sf::RenderWindow &win);
    int checkClic(sf::RenderWindow &win);
    sf::Event _event;
    sf::Texture _cakeT;
    sf::Texture _matrixT;
    sf::Sprite _cakeS;
    sf::Sprite _matrixS;
    sf::RectangleShape _textArea;
    sf::RectangleShape _return;
    sf::Text _text;
    sf::Text _returnT;
    sf::Font _font;
    std::wstring _lies[11] = {L"La terre est plate",
                         L"Le vaccin empêche d'attrapper le COVID",
                         L"La Volvic est meilleure que la Cristaline",
                         L"Epitech Digital est le meilleur cursus",
                         L"L'intra a toujours raison",
                         L"Le compilo ne ment jamais",
                         L"Michael Jackson est vivant",
                         L"Le gouvernement américain n'a rien à voir avec le 11 septembre",
                         L"Manger de la soupe fait grandir",
                         L"Les carottes rendent aimable",
                         L"Vous allez bientôt trouver l'amour"};
};