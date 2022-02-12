/*
** EPITECH PROJECT, 2022
** game_jam
** File description:
** achievement.cpp
*/

#include "achievement.hpp"

Success::Success()
{
    if (!_font.loadFromFile("assets/Roboto.ttf"))
        throw 84;
    _text.setFont(_font);
    _text.setCharacterSize(24);
    _text.setFillColor(sf::Color::Blue);
    _text.setPosition({300, 100});
    _text.setOutlineThickness(2);
    if (!_bananaT.loadFromFile("assets/school.png"))
        throw 84;
    _bananaS.setTexture(_bananaT);
    _bananaS.setScale(300.0f/_bananaS.getLocalBounds().width, 300.0f/_bananaS.getLocalBounds().height);
    _bananaS.setPosition({300, 0});
    //if (!_sb.loadFromFile("ressources/baptiste.ogg"))
    //    throw 84;
    //_sound.setBuffer(_sb);
}

/**
 * @brief Crée une fenêtre et affiche le succès "text", avec l'image "path", et joue le son "audio"
 * 
 * @param text Le nom du succès, doit être formaté en dur, pcq je suis un schlag
 * @param path Le path de l'image du singe
 * @param audio Le path du son à jouer, (défaut = baptiste.ogg)
 */
void Success::displaySuccess(std::wstring text, std::string path, std::string audio)
{
    _text.setString(text);
    if (!_monkeyT.loadFromFile(path))
        throw 84;
    if (audio != "ressources/baptiste.ogg") {
        //if (!_sb.loadFromFile(audio))
        //    throw 84;
        //_sound.setBuffer(_sb);
    }
    _monkeyS.setTexture(_monkeyT);
    _monkeyS.setScale(300.0f/_monkeyS.getLocalBounds().width, 300.0f/_monkeyS.getLocalBounds().height);
    _win.create(sf::VideoMode(600, 300), text);
    //_sound.play();
    while (_win.isOpen()) {
        while (_win.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                _win.close();
        }
        _win.clear(sf::Color::Black);
        _win.draw(_bananaS);
        _win.draw(_monkeyS);
        _win.draw(_text);
        _win.display();
    }
}


Success::~Success()
{
}

// int main()
// {
//     try {
//         success suc;
//         suc.displaySuccess(L"     Succès déverouillé !\n         Première éjac", "ressources/singe_etude.jpg");
//     }
//     catch (int i) {
//         std::cerr << "Error loading file" << std::endl;
//     }
// }