/*
** EPITECH PROJECT, 2022
** SPACE
** File description:
** SPACE
*/

#ifndef SPACE
    #define SPACE

    #include <iostream>
    #include <vector>
    #include <list>

    class KinderBueno {
        public:
        sf::Sprite KinderBuenoSprite;
        sf::Texture *KinderBuenoTexture;
        sf::Vector2f dir;
        KinderBueno(float x, float y, float playerx, float playery) {
            dir.x = (playerx - x) / 1000;
            dir.y = (playery - y) / 1000;
            KinderBuenoTexture = new sf::Texture;
            KinderBuenoTexture->loadFromFile("assets/kinderbueno.png");
            KinderBuenoSprite.setTexture(*KinderBuenoTexture);
            KinderBuenoSprite.setScale(0.1, 0.1);
            KinderBuenoSprite.setPosition(x, y);
            KinderBuenoSprite.rotate(0);
        }
        ~KinderBueno() = default;
    };

    class boss {
        public:
        sf::Sprite bossSprite;
        sf::Texture *bossTexture;
        int _id;
        float moveDelay;
        float kinderDelay;
        int lastMove;
        std::vector<KinderBueno> kinders;
        sf::RectangleShape rec_out;
        sf::RectangleShape rec_in;
        int _hp;
        boss() {
            bossTexture = new sf::Texture;
            bossTexture->loadFromFile("assets/boss.png");
            bossSprite.setTexture(*bossTexture);
            bossSprite.setScale(0.5, 0.5);
            bossSprite.setPosition(600, 0);
            rec_out = sf::RectangleShape(sf::Vector2f(300.f, 25.f));
            rec_in = sf::RectangleShape(sf::Vector2f(300.f, 25.f));
            rec_out.setPosition(600, 10);
            rec_in.setPosition(rec_out.getPosition());
            rec_out.setFillColor(sf::Color::Transparent);
            rec_out.setOutlineThickness(5.f);
            rec_out.setOutlineColor(sf::Color::Black);
            rec_in.setFillColor(sf::Color::Red);
            moveDelay = 0;
            kinderDelay = 0;
            _hp = 20;
            lastMove = rand() % 2;
        }
        ~boss() = default;
    };

    class life {
        public:
        life(int x, int y) {
            heartTexture = new sf::Texture;
            heartTexture->loadFromFile("assets/heart.png");
            heartSprite.setTexture(*heartTexture);
            heartSprite.setPosition(x, y);
            heartSprite.setScale(0.2, 0.2);
        }
        ~life() = default;
        sf::Texture *heartTexture;
        sf::Sprite heartSprite;
    };

    class ennemy {
        public:
        int _x;
        int _y;
        sf::Sprite ennemySprite;
        sf::Texture *ennemyTexture;
        int _id;
        ennemy(int x, int y) {
            _x = x;
            _y = y;
            static int id = 0;
            _id = id;
            id++;
            ennemyTexture = new sf::Texture;
            ennemyTexture->loadFromFile("assets/ennemy.png");
            ennemySprite.setTexture(*ennemyTexture);
            ennemySprite.setScale(0.1, 0.1);
            ennemySprite.setPosition(x + ennemySprite.getGlobalBounds().width / 4, y);
        }
        ~ennemy() = default;
        bool operator==(const ennemy &toTest) {
            if (_id == toTest._id)
                return true;
            return false;
        }
    };

    class bullet {
        public:
        sf::Sprite bulletSprite;
        sf::Texture *bulletTexture;
        bullet(const sf::Vector2f &test) {
            bulletTexture = new sf::Texture;
            bulletTexture->loadFromFile("assets/fireball.png");
            bulletSprite.setTexture(*bulletTexture);
            bulletSprite.setScale(0.2, 0.2);
            bulletSprite.setPosition(test.x + bulletSprite.getGlobalBounds().width / 4, test.y);
            bulletSprite.rotate(-90);
        }
        ~bullet() = default;
    };

    class poubelle {
        public:
        enum direction {
            UP,
            DOWN,
            LEFT,
            RIGHT
        };
        sf::RenderWindow *window;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
        sf::Texture spaceShipTexture;
        sf::Sprite spaceShipSprite;
        sf::Clock clock;
        float timestep;
        sf::Vector2f movement;
        sf::Event event;
        float accumulator = 0;
        std::vector<bullet> bullets;
        std::list<ennemy> ennemies;
        float rocketDelay = 0;
        float ennemyDelay = 0;
        std::vector<life> _hearts;
        int _hp;
        boss Johann;
        int phase;
        int ennemyKilled;
        poubelle(sf::RenderWindow *win) {
            window = win;
            movement = {0, 0};
            timestep = 1.0f / 60.0f;
            _hp = 6;
            phase = 0;
            ennemyKilled = 0;
            _hearts.push_back(life(1200 - 50, 0));
            _hearts.push_back(life(1200 - 105, 0));
            _hearts.push_back(life(1200 - 160, 0));
            _hearts.push_back(life(1200 - 220, 0));
            _hearts.push_back(life(1200 - 265, 0));
            _hearts.push_back(life(1200 - 320, 0));
            backgroundTexture.loadFromFile("assets/space_background.jpg");
            backgroundSprite.setTexture(backgroundTexture);

            spaceShipTexture.loadFromFile("assets/space_ship.png");
            spaceShipSprite.setTexture(spaceShipTexture);
            spaceShipSprite.setScale(0.2, 0.2);
            spaceShipSprite.setPosition(1280 / 2 - spaceShipSprite.getGlobalBounds().width, 600);
        }
        ~poubelle() = default;
        int loop();
        void draw();
    };

#endif /* !SPACE */
