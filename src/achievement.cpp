/*
** EPITECH PROJECT, 2022
** game_jam
** File description:
** achievement.cpp
*/

#include "../headers/achievement.hpp"
#include <vector>

success::success(std::wstring text, std::string path, std::string audio)
{
    if (!_font.loadFromFile("assets/Roboto.ttf"))
        throw 84;

    _text.setFont(_font);
    _text.setCharacterSize(18);
    _text.setFillColor(sf::Color::Blue);
    _text.setOutlineThickness(2);
    _text.setString(text);

    _rect.setSize(sf::Vector2f(300, 150));
    _rect.setOutlineColor(sf::Color(211, 211, 211));
    _rect.setOutlineThickness(5);

    if (!_crossT.loadFromFile("assets/croix.png"))
        throw 84;
    _crossS.setSize(sf::Vector2f(15, 15));
    _crossS.setTexture(&_crossT, true);
    _crossS.setOutlineColor(sf::Color(211, 211, 211));
    _crossS.setOutlineThickness(5);

    if (!_bananaT.loadFromFile("assets/banana.jpg"))
        throw 84;
    _bananaS.setTexture(_bananaT);
    _bananaS.setScale(150.0f/_bananaS.getLocalBounds().width, 150.0f/_bananaS.getLocalBounds().height);

    if (!_sb.loadFromFile(audio))
        throw 84;
    _sound.setBuffer(_sb);
        
    if (!_monkeyT.loadFromFile(path))
        throw 84;
    _monkeyS.setTexture(_monkeyT);
    _monkeyS.setScale(150.0f/_monkeyS.getLocalBounds().width, 150.0f/_monkeyS.getLocalBounds().height);
}

void success::displaySuccess(sf::RenderWindow &win, int i)
{
    if (_firstCall) {
        _sound.play();
        _firstCall = false;
    }
    _monkeyS.setPosition((sf::Vector2f(895, (800 - 155 * (i+1)))));
    _bananaS.setPosition((sf::Vector2f(1045, (800 - 155 * (i+1)))));
    _text.setPosition(sf::Vector2f(1045, (800 - 155 * (i+1))));
    _rect.setPosition(sf::Vector2f(895, (800 - 155 * (i+1))));
    _crossS.setPosition(sf::Vector2f(1180, (800 - 155 * (i+1))));
    win.draw(_rect);
    win.draw(_bananaS);
    win.draw(_monkeyS);
    win.draw(_text);
    win.draw(_crossS);
}

success::~success()
{
}

// int main()
// {
//     try {
//         std::vector<success *> achievement;
//         success *suc = new success(L"\n\n         Succès !\n     Première éjac", "ressources/singe_etude.jpg");
//         success *truc = new success(L"\n\n         Succès !\n     Première éjac", "ressources/cake.jpg");
//         achievement.push_back(suc);
//         achievement.push_back(truc);
//         sf::RenderWindow win(sf::VideoMode(1200, 800), "pouet");
//         sf::Event event;
//         while (win.isOpen()) {
//             while (win.pollEvent(event)) {
//                 if (event.type == sf::Event::Closed)
//                     win.close();
//                 for (int it = 0; it < achievement.size(); it++) {
//                     if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left &&
//                         achievement[it]->_crossS.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win)))) {
//                             std::vector<success *>::iterator iterator = achievement.begin() + it;
//                             delete achievement[it];
//                             achievement.erase(iterator);
//                     }
//                 }
//             }
//             win.clear(sf::Color::Black);
//             for (int it = 0; it < achievement.size(); it++) {
//                 achievement[it]->displaySuccess(win, it);
//             }
//             win.display();
//         }
//     }
//     catch (int i) {
//         std::cerr << "Error loading file" << std::endl;
//     }
// }