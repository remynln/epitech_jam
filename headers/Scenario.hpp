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
    #include <functional>
    #include "achievement.hpp"
    #include <unordered_map>
    #include "ScriptChoice.hpp"

    class Scenario {
        public:
            Scenario();
            ~Scenario();
            Scenario(const Scenario &scenario);

            void setMap(std::string, std::function<void(sf::RenderWindow *)>, bool isAnEnd);
            void startScenario(sf::RenderWindow *);
            void setScenario(std::string name);
            bool isAnEnd();
            void giveSuccess(std::string);

            void setInScenario(const bool value);
            const bool &getInScenario() const;

            void Start(sf::RenderWindow *window);
            void Fuir(sf::RenderWindow *window);
            void Matrice(sf::RenderWindow *window);
            void Rencontre(sf::RenderWindow *window);
            void Reel(sf::RenderWindow *window);

            void BeetSaber_MiniGame(sf::RenderWindow *window);

            void Psykoloke_MiniScene(sf::RenderWindow *window);
            void PsyJob(sf::RenderWindow *window);
            void Folie(sf::RenderWindow *window);

        private:
            void initChoice();
            void initSuccess();
            void setSuccess();
            std::string _name;
            std::map<std::string, std::pair<std::function<void(sf::RenderWindow *)>, bool>> _choice;
            std::unordered_map<std::string, bool> _success;
            Success _successPopUp;
            bool _inScenario;
    };

    Scenario init_scenario();

#endif /* !SCENARIO */