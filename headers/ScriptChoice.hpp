/*
** EPITECH PROJECT, 2022
** JAM
** File description:
** ScriptChoice
*/

#ifndef SCRIPTCHOICE_HPP_
#define SCRIPTCHOICE_HPP_

#include <string>
#include <list>
#include <SFML/Graphics.hpp>

class ScriptChoice {
    public:
        ScriptChoice(std::string filename, std::string dialog);
        ScriptChoice(std::string filename, std::string dialog, std::string a);
        ScriptChoice(std::string filename, std::string dialog, std::string a, std::string b);
        ScriptChoice(std::string filename, std::string dialog, std::string a, std::string b, std::string c);
        ScriptChoice(std::string filename, std::string dialog, std::string a, std::string b, std::string c, std::string d);
        ScriptChoice(std::string filename, std::string dialog, std::string a, std::string b, std::string c, std::string d, std::string e);
        ~ScriptChoice();
        std::string choose(sf::RenderWindow *window);
        void eventHandelling(sf::RenderWindow *window);
        void displayWindow(sf::RenderWindow *window);
        bool checkEnd();

    private:
        sf::Font _font;
        sf::Texture _bg_texture;
        sf::Sprite _bg_sprite;
        std::string _dialog;
        sf::Text _dialog_disp;
        std::list<std::string> _choice_text;
        std::list<sf::Text *> _choice_text_disp;
        std::string _ret;
};

#endif /* !SCRIPTCHOICE_HPP_ */
