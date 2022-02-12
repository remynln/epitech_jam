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

    class Scenario {
        public:
            Scenario(std::string name);
            ~Scenario();

            const std::string &getName() const;
            void addScene(std::string text, std::string picture);
            void setMap(std::string, Scenario *);
        private:
            const std::string _name;
            std::vector<std::pair<std::string, std::string>> _scene;
            std::map<std::string, Scenario *> _choice;
    };

    void init_scenario();

#endif /* !SCENARIO */