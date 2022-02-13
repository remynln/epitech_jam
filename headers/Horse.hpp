/*
** EPITECH PROJECT, 2022
** git
** File description:
** Horse
*/

#ifndef HORSE_HPP_
    #define HORSE_HPP_

    #include <vector>
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>

class Barrier {
public:
    Barrier(float offset);
    void render(sf::RenderWindow *win, float prop);
    void stop();
private:
    sf::Texture *tex;
    sf::Vector2f pos;
    sf::Sprite *sprite;

};





struct HorseBackground {
    HorseBackground(float offset);
    sf::Texture *tex;
    sf::Sprite *sprite;
    void render(sf::RenderWindow *win);
};





class Horse {
    public:
        Horse();
        ~Horse();

        void renderHorse(sf::RenderWindow *win);

    protected:
    private:
        sf::Sprite *horseSprite;
        sf::Texture *horseTex[12];
        HorseBackground *bg[2];
        sf::Texture *bgTex;
        float horseFrame = 0;
        float propulsion = -667;
        std::vector<Barrier *> barriers;
};




#endif /* !HORSE_HPP_ */
