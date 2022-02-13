/*
** EPITECH PROJECT, 2022
** epitech_jam
** File description:
** marcolito
*/

#ifndef MARCOLITO_HPP_
    #define MARCOLITO_HPP_

    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>
    #include <random>
    #include <iostream>
    #include <vector>

    class Drug {
        public:
            Drug(sf::RenderWindow *win);
            void mouse_move_handle(sf::Event::MouseMoveEvent event);
            void mouse_click_handle(sf::Event::MouseButtonEvent event);
            void event_handler(void);
            void hit(void);
            void create_circle(void);
            void display(void);


            sf::RenderWindow *window;
            sf::Event event;
            sf::CircleShape *circle;
            sf::Texture arm;
            sf::Sprite s_arm;
            sf::Texture ser;
            sf::Sprite s_ser;
            sf::RectangleShape life_out;
            sf::RectangleShape life_in;
            sf::RectangleShape rec_out;
            sf::RectangleShape rec_in;
            std::vector<sf::Sprite *> hits;
            sf::Music music;
            int gl;
            int fr;
    };

    sf::CircleShape *create_circle(void);

#endif /* !MARCOLITO_HPP_ */
