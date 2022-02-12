/*
** EPITECH PROJECT, 2022
** SCENARIO
** File description:
** SCENARIO
*/

#ifndef SCENARIO
    #define SCENARIO

    #include <string>
    #include <map>
    #include <vector>
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>

    class Scenario {
        public:
            Scenario();

            void setMap(std::string, void (*)(sf::RenderWindow *));
            void startScenario(sf::RenderWindow *);
            void setScenario(std::string name);
        private:
            std::string _name;
            std::map<std::string, void (*)(sf::RenderWindow *)> _choice;
    };

    Scenario init_scenario();

#endif /* !SCENARIO */