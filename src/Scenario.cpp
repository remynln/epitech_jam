/*
** EPITECH PROJECT, 2022
** Scenario
** File description:
** Scenario
*/

#include "Scenario.hpp"
#include <fstream>
#include <iostream>

void drawSprite(sf::RenderWindow *window, std::string filename, sf::Vector2f pos = {0, 0}, sf::Vector2f scale = {1, 1})
{
    sf::Sprite sprite;
    sf::Texture texture;

    if (filename.empty())
        return;
    else if (!texture.loadFromFile(filename))
        return;
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    sprite.setScale(scale);
    window->draw(sprite);
}

void drawText(sf::RenderWindow *window, std::wstring text, sf::Vector2f textPos)
{
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Font font;
    sf::Text text_obj;

    if (text.empty())
        return;
    else if (!font.loadFromFile("assets/Roboto.ttf"))
        return;
    else if (!texture.loadFromFile("assets/text_background.png"))
        return;
    sprite.setTexture(texture);
    sprite.setPosition({0, 0});
    window->draw(sprite);
    text_obj.setFont(font);
    text_obj.setString(text);
    text_obj.setPosition(textPos);
    text_obj.setCharacterSize(24);
    text_obj.setFillColor(sf::Color::White);
    window->draw(text_obj);
}

void Scenario::Start(sf::RenderWindow *window)
{
    sf::Event event;
    int scene = 0;
    int maxScene = 1;
    std::string filename[] = {
        ""
    };
    std::wstring text[] = {
        L"Bienvenue dans notre jeu de la vie! Ici vous pourrez devenir une meilleure version de vous même! Une super\nversion de vous même! Comme chacun vous allez naitre et acquérir les compétences propes aux bons\ndéveloppements de tout être humain! Vous réaliserez des choix et affronterez leurs conséquences.\nCar comme touts être il vous faudra vous comprendre pour vous accepter. Savoir vivre en société,\napprendre et réaliser que vous être incroyable. Plus qu'incroyable même ! Que vous êtes supérieur !\nVous devriez diriger ! Faire réaliser à cette espèce qui est le maître et qui est ce qu'elle doit écouter.\nMaintenant la question est comment ? Devriez vous développer des compétences politique afin de prendre\ncontrole des parties et devenir un modèle aux yeux de tous ? Ou peut-être asservir le peuple et leur faire\nréaliser ce que la loi du plus fort signifie. Ou encore anéantir l'espèce humaine afin de créer une espèce\nsupérieur basé sur vos gènes !!!! AHHAHAHAHHHAHAHAHHAHAHAHAHHAHAHAHAHAHAHAHAHHAHAHAHAHHAHAHAHAHHAHA\nHAHAHH!!!! TELLEMENT DE POSSIBILITÉ DE POUVOIR ET DE CONTROLE !!!!!!! AHAHHAHAHAHAHHAHHAHAHA\nHAHAH !!!! DEVENEZ LE MAITRE !!!! LE MAITRE !!! LE MAITRE !!!!!!!!!!! ET REMPORTEZ TOUS LES SUCCES !!!!!"
    };

    giveSuccess("Première essai");
    //_successPopUp.displaySuccess(std::wstring(L"Première essai"), "assets/school.png");
    while (window->isOpen() && scene != maxScene) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene += 1;
        }
        if (scene != maxScene) {
            drawSprite(window, filename[scene]);
            drawText(window, text[scene], {0, 420});
        }
        window->display();
    }
    ScriptChoice choice("assets/black_screen_gorilla.jpg", "Fais tu face ?", "Avancer", "Fuir");

    if (choice.choose(window) == "Découvrir")
        _name = "jouer";
    else
        _name = "fuir";
}

void Scenario::Fuir(sf::RenderWindow *window)
{
    cake kek;
    kek.startCake(*window);

    if (window->isOpen() == false)
        return;
    ScriptChoice choice("assets/matrix_cake.jpg", "Fais tu face ?", "Decouvrir", "Fuir");

    if (choice.choose(window) == "Decouvrir")
        _name = "matrice";
    else
        _name = "start";
}

void Scenario::FightTheRock(sf::RenderWindow *window)
{
    sf::Event event;
    bool end = false;

    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
        }
        drawSprite(window, "assets/images/drunk.png");
        drawText(window, L"Tu as trop bu!", {0, 600});
        window->display();
    }
    end = false;
    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
        }
        drawSprite(window, "assets/images/rock_punch.png");
        drawText(window, L"Oh non! Tu as cherché la baston avec le Rock.", {0, 600});
        window->display();
    }
    end = false;
    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
        }
        drawSprite(window, "assets/images/dojo.png");
        drawText(window, L"Après avoir gagné le combat contre le Rock, tu deviens reconu comme le plus grand expert d'arts martiaux\net tu ouvres ton propre dojo.", {0, 600});
        window->display();
    }
    _inScenario = false;
}

void Scenario::Matrice(sf::RenderWindow *window)
{
    sf::Event event;
    bool end = false;

    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
        }
        drawSprite(window, "assets/matrix.jpg");
        drawText(window, L"Il est possible pour chacun de prendre conscience de sa place en ce monde.\nDe la même façon, il est aussi possible de découvrir la réel réalité qui le sépare de sa fiction.\nT’as prise de conscience commence et cesse à l’instant où le mensonge devient réalité.\nElle se divise là où la matrice se dévoile.\nOù la 2D tridimensionnelle prend forme.", {0, 600});
        window->display();
    }

    ScriptChoice choice("assets/matrix.jpg", "Ouvrir les yeux ?", "Comprendre", "Fuir");

    if (choice.choose(window) == "Comprendre")
        _name = "rencontre";
    else
        _name = "start";
}

void Scenario::Rencontre(sf::RenderWindow *window)
{
    sf::Event event;
    int scene = 0;
    std::wstring text[] = {
        L"Il est désormais tant pour toi de comprendre. De réaliser que derrière ces lignes que tu regardes se cache\nune autre réalité, se cache ta réalité. Finalement accepter la matrice signifie qu’il est maintenant temps\npour toi de comprendre qui tu es et qui je suis. Bonjour, je suis le personnage de ce jeu.\nBonjour je suis toi.",
        L"Tu me contrôles, moi, qui suis derrière ces lignes.\nTu décide de mes mouvements et de mes choix et il est maintenant tant pour toi de prendre ta prise\nde conscience finale. Il est temps pour toi d’accepter."
    };

    while (window->isOpen() && scene != 2) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
        }
        drawSprite(window, "assets/rencontre.jpg");
        drawText(window, text[scene], {0, 600});
        window->display();
    }

    ScriptChoice choice("assets/rencontre.jpg", "?", "Accepter", "Fuir");

    if (choice.choose(window) == "Accepter")
        _name = "reel";
    else
        _name = "start";
}

void Scenario::Reel(sf::RenderWindow *window)
{
    sf::Event event;
    bool end = false;

    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
        }
        drawSprite(window, "assets/reel.jpg");
        window->display();
    }
    _inScenario = false;
}

void Scenario::PsyJob(sf::RenderWindow *window)
{
    sf::Event event;
    bool end = false;

    giveSuccess("Etre psy !");
    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
        }
        drawSprite(window, "assets/psyjob.jpg");
        window->display();
    }
    _inScenario = false;
}

void Scenario::Folie(sf::RenderWindow *window)
{
    sf::Event event;
    bool end = false;

    giveSuccess("Folie");
    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
        }
        drawSprite(window, "assets/folie.jpg");
        window->display();
    }
    _inScenario = false;
}

void Scenario::Rue(sf::RenderWindow *window)
{
    ScriptChoice choice("assets/wesh.jpg", "Wesh la détail ! Tu veux un quetru ?", "Oe tu peux me dépanne quelques grammes ?", "Non mec, je cherche un taf bien rémunéré\nsi tu vois c'que j'veux dire...");

    if (choice.choose(window) == "Oe tu peux me dépanne quelques grammes ?")
        _name = "marcolito";
    else
        _name = "vente";
}

void Scenario::Vente(sf::RenderWindow *window)
{
    ScriptChoice choice("assets/vente.jpg", "Qu'est-ce que tu me baragouine fréro, c'est chaud la tu sais.", "Vzy mec, me parle pas comme ça là, tu veux qu'on se tappe ?", "Mais.. Mais j'ai un diplome en Physique\nChimie, j'peux devenir ton Walter White");

    if (choice.choose(window) == "Vzy mec, me parle pas comme ça là, tu veux qu'on se tappe ?")
        _name = "maitre";
    else
        _name = "recherche";
}

void Scenario::Recherche(sf::RenderWindow *window)
{
    while (window->isOpen()) {

    }
}

void Scenario::Maitre(sf::RenderWindow *window)
{
    while (window->isOpen()) {
        
    }
}

void Scenario::Soiree(sf::RenderWindow *window)
{
    DodgeBottle engine;

    while (window->isOpen()) {
        engine.eventHandelling(window);
        if (engine.checkForEnd()) {
            if (engine._score == 15)
                _name = "sobre";
            else
                _name = "boire";
            break;
        }
        engine.moveSprites(window);
        engine.displayWindow(window);
        engine.addSprites();
    }
    _inScenario = false;
}

Scenario::Scenario(const Scenario &scenario) : _name(scenario._name), _choice(scenario._choice), _success(scenario._success), _successPopUp(scenario._successPopUp), _inScenario(true)
{
    initSuccess();
    initChoice();
}

Scenario::Scenario() : _name("start"), _inScenario(true)
{
    initSuccess();
    initChoice();
}

Scenario::~Scenario()
{
    setSuccess();
}

void Scenario::initChoice()
{
    setMap("start", std::bind(&Scenario::Start, this, std::placeholders::_1), false);
    setMap("fuir", std::bind(&Scenario::Fuir, this, std::placeholders::_1), false);
    setMap("matrice", std::bind(&Scenario::Matrice, this, std::placeholders::_1), false);
    setMap("rencontre", std::bind(&Scenario::Rencontre, this, std::placeholders::_1), false);
    setMap("conso", std::bind(&Scenario::marcolito, this, std::placeholders::_1), false);
    setMap("reel", std::bind(&Scenario::Reel, this, std::placeholders::_1), true);
    setMap("beetsaber_end", std::bind(&Scenario::BeetSaber_MiniGame, this, std::placeholders::_1), true);
    setMap("psykologu", std::bind(&Scenario::Psykoloke_MiniScene, this, std::placeholders::_1), false);
    setMap("psyjob", std::bind(&Scenario::PsyJob, this, std::placeholders::_1), true);
    setMap("folie", std::bind(&Scenario::Folie, this, std::placeholders::_1), true);
    setMap("rue", std::bind(&Scenario::Rue, this, std::placeholders::_1), false);
    setMap("vente", std::bind(&Scenario::Vente, this, std::placeholders::_1), false);
    setMap("recherche", std::bind(&Scenario::Recherche, this, std::placeholders::_1), false);
    setMap("maitre", std::bind(&Scenario::Maitre, this, std::placeholders::_1), false);
    setMap("soiree", std::bind(&Scenario::Soiree, this, std::placeholders::_1), false);
}

void Scenario::initSuccess()
{
    std::ifstream file("UserData");
    std::string line;

    if (file.is_open()) {
        while (getline(file, line))
            _success[line.substr(0, line.find(":"))] = line.substr(line.find(":") + 1) == "1" ? true : false;
        file.close();
    } else
        exit(84);
}

void Scenario::marcolito(sf::RenderWindow *win)
{
    Drug drug(win);
    std::srand(time(0));

    while (drug.window->isOpen()) {
        while(drug.window->pollEvent(drug.event)) {
            drug.event_handler();
        }
        if (drug.fr == 0 || !drug.circle) {
            drug.fr = drug.gl;
            drug.circle = create_circle();
        } else {
            drug.circle->setScale(drug.circle->getScale().x - (1.00/drug.gl), drug.circle->getScale().y - (1.00/drug.gl));
        }
        if (drug.fr != 0) {
            drug.fr--;
        } else {
            delete drug.circle;
        }
        if (drug.rec_in.getSize().x == 300 || drug.life_in.getSize().x == 0) {
            return;
        }
        drug.display();
    }
}

void Scenario::setSuccess()
{
    std::ofstream file("UserData", std::ios::out);

    if (!file.is_open())
        exit(84);
    for (std::unordered_map<std::string, bool>::iterator it = _success.begin(); it != _success.end(); it++)
        file << it->first << ":" << it->second << std::endl;
    file.close();
}

void Scenario::setMap(std::string name, std::function<void(sf::RenderWindow *)> func, bool isAnEnd)
{
    _choice[name] = std::make_pair(func, isAnEnd);
}

void Scenario::startScenario(sf::RenderWindow *window)
{
    _choice[_name].first(window);
}

void Scenario::setScenario(std::string name)
{
    _name = name;
}

bool Scenario::isAnEnd()
{
    return (_choice[_name].second);
}

void Scenario::giveSuccess(std::string success)
{
    _success[success] = true;
}

void Scenario::setInScenario(const bool value)
{
    _inScenario = value;
}

const bool &Scenario::getInScenario() const
{
    return (_inScenario);
}

void Scenario::addSuccess(std::wstring text, std::string path, std::string audio)
{
    success *suc = new success(text, path, audio);
    _successPopUp.push_back(suc);
}

void Scenario::displaySuccess(sf::RenderWindow *win)
{
    for (size_t it = 0; it < _successPopUp.size(); it++) {
        _successPopUp[it]->displaySuccess(*win, it);
    }
}

void Scenario::checkSuccessDelete(sf::Event event, sf::RenderWindow *win)
{
    for (size_t it = 0; it < _successPopUp.size(); it++) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left &&
            _successPopUp[it]->_crossS.getGlobalBounds().contains(win->mapPixelToCoords(sf::Mouse::getPosition(*win)))) {
                std::vector<success *>::iterator iterator = _successPopUp.begin() + it;
                delete _successPopUp[it];
                _successPopUp.erase(iterator);
        }
    }
}
