#include "cake.hpp"

cake::cake()
{
    if (!_cakeT.loadFromFile("assets/cake.png"))
        throw 84;
    if (!_matrixT.loadFromFile("assets/matrix_cake.jpg"))
        throw 84;
    if (!_font.loadFromFile("assets/Roboto.ttf"))
        throw 84;
    _cakeS.setTexture(_cakeT);
    _cakeS.setOrigin(450, 600);
    _cakeS.setScale(0.7, 0.7);
    _cakeS.setPosition(600, 450);
    _matrixS.setTexture(_matrixT);
    _matrixS.setScale(1200.0f/_matrixS.getLocalBounds().width, 800.0f/ _matrixS.getLocalBounds().height);
    _return.setSize(sf::Vector2f(155, 50));
    _return.setFillColor(sf::Color::Black);
    _return.setOutlineColor(sf::Color(38, 255, 52));
    _return.setOutlineThickness(2);
    _return.setPosition(sf::Vector2f(1025, 725));
    _textArea.setSize(sf::Vector2f(1100, 50));
    _textArea.setFillColor(sf::Color::Black);
    _textArea.setOutlineColor(sf::Color(38, 255, 52));
    _textArea.setOutlineThickness(2);
    _textArea.setPosition(sf::Vector2f(50, 10));
    _text.setFont(_font);
    _text.setFillColor(sf::Color(38, 255, 52));
    _text.setCharacterSize(24);
    _text.setPosition(sf::Vector2f(60, 20));
    _text.setString(L"Ça sentait bon, j'avais faim, donc j'ai sauté la barrière");
    _returnT.setFont(_font);
    _returnT.setFillColor(sf::Color(38, 255, 52));
    _returnT.setCharacterSize(24);
    _returnT.setPosition(sf::Vector2f(1030, 735));
    _returnT.setString("J'ai plus faim");

}

cake::~cake()
{
}

int cake::checkClic(sf::RenderWindow &win)
{
    if (_cakeS.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win)))) {
        _cakeS.setScale(_cakeS.getScale().x * 0.9, _cakeS.getScale().y * 0.9);
        _text.setString(_lies[rand()%11]);
    }
    if (_return.getGlobalBounds().contains(win.mapPixelToCoords(sf::Mouse::getPosition(win)))) {
        return 1;
    }
    return 0;
}

void cake::startCake(sf::RenderWindow &win)
{
    while (win.isOpen()) {
        while (win.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                win.close();
            if (_event.type == sf::Event::MouseButtonPressed && _event.mouseButton.button == sf::Mouse::Left)
                if (checkClic(win) == 1)
                    return;
        }
        win.clear(sf::Color::Black);
        win.draw(_matrixS);
        win.draw(_textArea);
        win.draw(_cakeS);
        win.draw(_text);
        win.draw(_return);
        win.draw(_returnT);
        win.display();
    }
}

int main()
{
    srand(time(0));
    try {
    cake kek;
    sf::RenderWindow win(sf::VideoMode(1200, 800), "pouet");
    kek.startCake(win);
    }
    catch (int a) {
        std::cerr << "pouet" << std::endl;
    }
}