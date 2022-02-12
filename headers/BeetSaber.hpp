//
// EPITECH PROJECT, 2022
// epitech jam
// File description:
// header for beetsaber
//

#ifndef BEETSABER_H_
    #define BEETSABER_H_

    #include <SFML/Graphics/RenderWindow.hpp>
    #include <SFML/Graphics/Sprite.hpp>
    #include <SFML/Window/Keyboard.hpp>

    #define NB_CUBES 20
    #define Y_MAX 800
    #define X_MAX 1200
    #define SCALE_OFFSET 0.2
    #define RATIO_SCALE 3
    #define PAD_SPACE_KEY 200

class CubeComming {
    public:
        CubeComming();
        ~CubeComming();

        void update(float delatime);
        bool check_collision(sf::RenderWindow *window, bool *first_flech);
        void draw(sf::RenderWindow *window);

        sf::Texture *texture;
        sf::Sprite sprite;
        sf::Keyboard::Key key;
        float times;
        int flech_direction;
        bool is_touched;

    protected:
    private:
};

#endif