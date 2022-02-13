/*
** EPITECH PROJECT, 2022
** epitech_jam
** File description:
** laruelavré
*/

#ifndef LARUELAVR__HPP_
    #define LARUELAVR__HPP_

    #include <SFML/Graphics.hpp>

    class Button {
        public:
            Button(std::string text);
            ~Button();

            sf::Text text;
            sf::Font font;
            sf::RectangleShape rect;
    };

    class LaRue {
        public:
            enum RPS {
                ROCK,
                PAPER,
                SCISOR,
                MAX
            };

            LaRue(sf::RenderWindow *win);
            void handle(sf::Event &event);
            void game();
            int multiplicator = 204;

            sf::Sprite s_background;
            sf::Texture t_background;
            sf::Sprite s_hands;
            sf::Texture t_hands;
            sf::Sprite es_hands;
            sf::Texture et_hands;
            sf::IntRect e_rect;
            sf::IntRect rect;
            std::vector<Button *> buttons;
            sf::RenderWindow *window;
            sf::Font font;
            sf::Text t_score;
            sf::Text te_score;
            int score;
            int e_score;
            int choosen;
    };


#endif /* !LARUELAVR__HPP_ */
