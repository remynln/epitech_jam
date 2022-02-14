/*
** EPITECH PROJECT, 2022
** Scenario
** File description:
** Scenario
*/

#include "../headers/Scenario.hpp"
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
        L"Bienvenue dans notre jeu de la vie! Ici vous pourrez devenir une meilleure version de vous même! Une super\nversion de vous même! Comme chacun vous allez naitre et acquerir les competences propes aux bons\ndeveloppements de tout être humain! Vous realiserez des choix et affronterez leurs consequences.\nCar comme touts être il vous faudra vous comprendre pour vous accepter. Savoir vivre en societe,\napprendre et realiser que vous être incroyable. Plus qu'incroyable même ! Que vous êtes superieur !\nVous devriez diriger ! Faire realiser a cette espece qui est le maître et qui est ce qu'elle doit ecouter.\nMaintenant la question est comment ? Devriez vous developper des competences politique afin de prendre\ncontrole des parties et devenir un modele aux yeux de tous ? Ou peut-être asservir le peuple et leur faire\nrealiser ce que la loi du plus fort signifie. Ou encore aneantir l'espece humaine afin de creer une espece\nsuperieur base sur vos genes !!!! AHHAHAHAHHHAHAHAHHAHAHAHAHHAHAHAHAHAHAHAHAHHAHAHAHAHHAHAHAHAHHAHA\nHAHAHH!!!! TELLEMENT DE POSSIBILITe DE POUVOIR ET DE CONTROLE !!!!!!! AHAHHAHAHAHAHHAHHAHAHA\nHAHAH !!!! DEVENEZ LE MAITRE !!!! LE MAITRE !!! LE MAITRE !!!!!!!!!!! ET REMPORTEZ TOUS LES SUCCES !!!!!"
    };

    giveSuccess("Premiere essai");
    addSuccess(L"Bravo tu a lancer\nle jeu", "assets/singe1.png");
    while (window->isOpen() && scene != maxScene) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene += 1;
            checkSuccessDelete(event, window);
        }
        if (scene != maxScene) {
            drawSprite(window, filename[scene]);
            drawText(window, text[scene], {0, 420});
        }
        displaySuccess(window);
        window->display();
    }
    ScriptChoice choice(this, "assets/black_screen_gorilla.jpg", "Fais tu face ?", "Avancer", "Fuir");

    if (choice.choose(window) == "Avancer")
        _name = "jouer";
    else
        _name = "fuir";
}

void Scenario::Jouer(sf::RenderWindow *window)
{
    SchoolPriorities engine;

    while (window->isOpen()) {
        engine.eventHandelling(window);
        if (engine.checkForEnd()) {
            break;
        }
        engine.moveSprites();
        engine.displayWindow(window);
        engine.addSprites();
    }
    if (engine.getRet() == SCHOOL)
        _name = "ecole";
    else
        _name = "rue";
}

void Scenario::Fuir(sf::RenderWindow *window)
{
    cake kek;
    kek.startCake(*window);

    if (window->isOpen() == false)
        return;
    ScriptChoice choice(this, "assets/matrix_cake.jpg", "Fais tu face ?", "Decouvrir", "Fuir");

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
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
            else if (event.type == sf::Event::Closed)
                window->close();
            else
                checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/images/drunk.png");
        drawText(window, L"Tu as trop bu!", {0, 600});
        displaySuccess(window);
        window->display();
    }
    end = false;
    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
            else if (event.type == sf::Event::Closed)
                window->close();
            else
                checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/images/rock_punch.png");
        drawText(window, L"Oh non! Tu as cherche la baston avec le Rock.", {0, 600});
        displaySuccess(window);
        window->display();
    }
    end = false;
    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::Closed)
                 window->close();
            else
                checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/images/dojo.png");
        drawText(window, L"Apres avoir gagne le combat contre le Rock, tu deviens reconu comme le plus grand expert d'arts martiaux\net tu ouvres ton propre dojo.", {0, 600});
        displaySuccess(window);
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
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
            else if (event.type == sf::Event::Closed)
                window->close();
            else
                checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/matrix.jpg");
        drawText(window, L"Il est possible pour chacun de prendre conscience de sa place en ce monde.\nDe la même facon, il est aussi possible de decouvrir la reel realite qui le separe de sa fiction.\nT'as prise de conscience commence et cesse a l'instant où le mensonge devient realite.\nElle se divise la où la matrice se devoile.\nOù la 2D tridimensionnelle prend forme.", {0, 600});
        displaySuccess(window);
        window->display();
    }

    ScriptChoice choice(this, "assets/matrix.jpg", "Ouvrir les yeux ?", "Comprendre", "Fuir");

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
        L"Il est desormais tant pour toi de comprendre. De realiser que derriere ces lignes que tu regardes se cache\nune autre realite, se cache ta realite. Finalement accepter la matrice signifie qu'il est maintenant temps\npour toi de comprendre qui tu es et qui je suis. Bonjour, je suis le personnage de ce jeu.\nBonjour je suis toi.",
        L"Tu me contrôles, moi, qui suis derriere ces lignes.\nTu decide de mes mouvements et de mes choix et il est maintenant tant pour toi de prendre ta prise\nde conscience finale. Il est temps pour toi d'accepter."
    };

    while (window->isOpen() && scene != 2) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/rencontre.jpg");
        drawText(window, text[scene], {0, 600});
        displaySuccess(window);
        window->display();
    }

    ScriptChoice choice(this, "assets/rencontre.jpg", "?", "Accepter", "Fuir");

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
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
            else if (event.type == sf::Event::Closed)
                 window->close();
            else
                checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/reel.jpg");
        displaySuccess(window);
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
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
            else if (event.type == sf::Event::Closed)
                window->close();
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/psyjob.jpg");
        displaySuccess(window);
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
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
            else if (event.type == sf::Event::Closed)
                window->close();
            else
                checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/folie.jpg");
        displaySuccess(window);
        window->display();
    }
    _inScenario = false;
}

void Scenario::Rue(sf::RenderWindow *window)
{
    ScriptChoice choice(this, "assets/wesh.jpg", "Wesh la detail ! Tu veux un quetru ?", "Oe tu peux me depanne quelques grammes ?", "Non mec, je cherche un taf bien remunere\nsi tu vois c'que j'veux dire...");

    if (choice.choose(window) == "Oe tu peux me depanne quelques grammes ?")
        _name = "conso";
    else
        _name = "vente";
}

void Scenario::Vente(sf::RenderWindow *window)
{
    ScriptChoice choice(this, "assets/vente.jpg", "Qu'est-ce que tu me baragouine frero, c'est chaud la tu sais.", "Vzy mec, me parle pas comme ca la, tu veux qu'on se tappe ?", "Mais.. Mais j'ai un diplome en Physique Chimie, j'peux devenir ton Walter White");

    if (choice.choose(window) == "Vzy mec, me parle pas comme ca la, tu veux qu'on se tappe ?")
        _name = "laruelavrai";
    else
        _name = "recherche";
}

// TODO: ici
void Scenario::Recherche(sf::RenderWindow *window)
{
    sf::Event event;
    int scene = 0;
    std::wstring text[] = {
        L"Recherche..",
        L"..."
    };

    while (window->isOpen() && scene != 2) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/rencontre.jpg");
        drawText(window, text[scene], {0, 600});
        displaySuccess(window);
        window->display();
    }
    _name = "recherche";
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
                _name = "fight";
            break;
        }
        engine.moveSprites(window);
        engine.displayWindow(window);
        displaySuccess(window);
        engine.addSprites();
    }
    _inScenario = false;
}

void Scenario::Sobre(sf::RenderWindow *window)
{
    sf::Event event;
    size_t scene = 0;
    std::wstring text[] = {
        L"Au fil de la soiree, tu ne bois pas.\nPas une goutte.\nAu milieu de ces toxico.",
        L"un inconnu tout de blanc vetu se rapproche de toi\nMaître Sobriete Xavier: Tu as loupe ta vocation. Il faut que tu rejoignes la voix d'aide envers alcoolique",
        L"Maître Sobriete Xavier: Par les pouvoirs du Johann le Johannisme, ta capacite de choix se voit retirer.\nTu deviendras un Guide spirituelle d'un groupe d'alcoolique.",
        L"Toi: Mais noooooooooo, pourquoi grand Johann me fais tu ca!\nMille million de mille sabords de tonnerre de brest c'est honteux."
    };

    while (window->isOpen() && scene != 4) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/Moine.png");
        drawText(window, text[scene], {0, 550});
        displaySuccess(window);
        window->display();
    }
    _inScenario = false;
}

void Scenario::Bill(sf::RenderWindow *window)
{
    sf::Event event;
    size_t scene = 0;
    std::wstring text[] = {
        L"Bill Gates: Wesh mon reuf, je commence a devenir vieux. Et j'ai envie de prendre des vacances..",
        L"Toi: Ok frero. Fais ce que tu veux non ? c'est ton entreprise BG.",
        L"Bill Gates: Le souci, c'est que j'ai deux gros bleme en parallele… Ma fille et l'entreprise. Comme tu l'as dis trkl\nc la mienne.",
        L"Toi: ducoup y a quoi qui gene.",
        L"Bill Gates: Si je prends des vacances, y aura ma fille qui va saouler. Et si ma fille saoule pas, c'est que je ne\nsuis pas en vacances.",
        L"Toi: J'te propose un marche le bro. On fait tourner une piece, si elle tombe sur face, jme marie avec ta fille\ncomme ca tu l'as plus dans les pates. si c'est pile, tu me donne don entreprise et tu seras libere.",
        L"Bill Gates: Deal."
    };

    while (window->isOpen() && scene != 7) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/background.jpg");
        drawText(window, text[scene], {0, 550});
        displaySuccess(window);
        window->display();
    }

    ScriptChoice choice(this, "", "Pile ou Face ?", "Pile, je veux pecho sec moi", "Face, la moula la moula");

    if (choice.choose(window) == "Pile, je veux pecho sec moi")
        _name = "marier";
    else
        _name = "entreprise";
}

void Scenario::Marier(sf::RenderWindow *window)
{
    sf::Event event;
    bool end = false;

    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
            else if (event.type == sf::Event::Closed)
                 window->close();
            else
                checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/marriage.jpg");
        displaySuccess(window);
        window->display();
    }
    _inScenario = false;
}

void Scenario::Entreprise(sf::RenderWindow *window)
{
    sf::Event event;
    bool end = false;

    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
            else if (event.type == sf::Event::Closed)
                window->close();
            else
                checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/microsoft.jpg");
        displaySuccess(window);
        window->display();
    }
    _inScenario = false;
}

void Scenario::BAC(sf::RenderWindow *window)
{
    sf::Event event;
    bool end = false;

    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
            else if (event.type == sf::Event::Closed)
                window->close();
            else
                checkSuccessDelete(event, window);
        }
        drawSprite(window, "");
        drawText(window, L"Felicitations ! vous avez le bac !\nQue vous ayez 10 au bac ou 22, vous possedez des contacts dans toutes les grandes ecoles.\nVous savez donc que vous n'avez qu'a envoyer un “Skype” au directeur pour être pris.\nC'est a vous de decider votre futur…", {0, 550});
        displaySuccess(window);
        window->display();
    }

    ScriptChoice choice(this, "", "Continuez vos etudes :", "Medecine", "ENS / Science po", "Sup Aero", "Epitech");

    if (choice.choose(window) == "Medecine")
        _name = "medecine";
    else if (choice.choose(window) == "ENS / Science po")
        _name = "ens";
    else if (choice.choose(window) == "Sup Aero")
        _name = "supaero";
    else
        _name = "epitech";
}

void Scenario::Medecine(sf::RenderWindow *window)
{
    sf::Event event;
    int scene = 0;
    std::wstring text[] = {
        L"Tu travail, travail... TRAVAIL",
        L"Mais, tient voilà quelq'un, petit saint ALI maître meme.",
        L"Ali: Bonjour, je suis Ali, je suis le maître de la medecine. Je suis le seul à mîtrisé le MEME.",
    };

    while (window->isOpen() && scene != 3) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/background.jpg");
        drawText(window, text[scene], {0, 600});
        displaySuccess(window);
        window->display();
    }
    _inScenario = false;
}

//TODO: ici
void Scenario::Ens(sf::RenderWindow *window)
{
    while (window->isOpen()) {
        
    }
}

void Scenario::Supaero(sf::RenderWindow *window)
{
    poubelle oui(window);
    int ret = 0;
    while (oui.window->isOpen()) {
        ret = oui.loop(this);
        oui.draw(this);
        if (ret)
            return;
        if (ret == -1)
            return;
    }
    _inScenario = false;
}

// TODO: ici
void Scenario::Epitech(sf::RenderWindow *window)
{
    sf::Event event;
    int scene = 0;
    std::wstring text[] = {
        L"Tu as bien fait!",
        L"Epitech, c'est la passion de..l'informatique",
        L"La meilleur école enfait"
    };

    while (window->isOpen() && scene != 3) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/Epitech.png");
        if (scene < 3) {
            drawText(window, text[scene], {0, 600});
        }
        displaySuccess(window);
        window->display();
    }
    _name = "bill";
}

void Scenario::Ecole(sf::RenderWindow *window)
{
    sf::Event event;
    size_t scene = 0;
    std::wstring text[] = {
        L"Random 0: l'ecole c'est le sang",
        L"Random 1: ceux qui travaillage pas zy vont po zavoir le ZBAC de frensse",
        L"Random 2: etudier ca sert a devenir pas zinzin de l'espace",
        L"Random 3: les soirees tous les jours c'est cool",
        L"Random 4: capter le 06 de la prof de francais",
        L"Toi: ..."
    };

    while (window->isOpen() && scene != 6) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/ecole.png");
        drawText(window, text[scene], {0, 550});
        displaySuccess(window);
        window->display();
    }

    ScriptChoice choice(this, "assets/ecole.png", "Bosser ?", "Je tryhard moi", "La flemme");

    if (choice.choose(window) == "Je tryhard moi")
        _name = "travailler";
    else
        _name = "rien";
}

void Scenario::Travailler(sf::RenderWindow *window)
{
    sf::Event event;
    size_t scene = 0;
    std::wstring text[] = {
        L"Ton Prof de Chinois: Quand le vent du changement se leve, les uns construisent des murs,\nles autres des moulins a vent. Conclusion : travail.",
        L"Ta Mere: Fils, arrête de te prendre des 10, si tu veux tu peux.",
        L"Ton Oncle pas drôle: HAHAHAH a force de travailler tu finiras dans la rue.",
        L"Ton Prof de Yoga: Celui qui marche sur le pas d'un autre ne laisse jamais de trace.",
        L"Le Psy random que tu connais pas: Faut que tu profites de ta vie au lieu de travailler.",
        L"Toi: *bosse*",
    };

    while (window->isOpen() && scene != 6) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/travail.jpg");
        drawText(window, text[scene], {0, 550});
        displaySuccess(window);
        window->display();
    }

    ScriptChoice choice(this, "assets/travail.jpg", "Tu tiens ?", "ca va ouais", "Non la j'en peux plus");

    if (choice.choose(window) == "ca va ouais")
        _name = "bac";
    else
        _name = "depression";
}

void Scenario::Rien(sf::RenderWindow *window)
{
    sf::Event event;
    size_t scene = 0;
    std::wstring text[] = {
        L"Grand Manitou qui pop et depop : L'ecole buissonniere est une education abrupte qui donne\nle diamant brut de la vie."
    };

    while (window->isOpen() && scene != 1) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "");
        drawText(window, text[scene], {0, 550});
        displaySuccess(window);
        window->display();
    }

    ScriptChoice choice(this, "", "Moi: Ok gros, en francais ?", "ah bah non, il est plus la.", "si je fais rien je fous quoi ?");

    if (choice.choose(window) == "ah bah non, il est plus la.")
        _name = "kfc";
    else
        _name = "gaming";
}

void Scenario::Depression(sf::RenderWindow *window)
{
    sf::Event event;
    size_t scene = 0;
    std::wstring text[] = {
        L"Moi : Ô mon dieu ! Je fais un burn-out, je pête les plombs… Je suis si triste, froid,\nplus aucune chaleur ne vit en moi, je commence a penser que les seules flammes eternelles sont celles\nde l'enfer…",
        L"Voix mysterieuse : Que baragouine-tu ?",
    };

    while (window->isOpen() && scene != 2) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/depression.png");
        drawText(window, text[scene], {0, 550});
        displaySuccess(window);
        window->display();
    }

    ScriptChoice choice(this, "assets/depression.png", "Tu reagis comment ?", "Je... Je... T'es qui ?", "Ta gueule !");

    if (choice.choose(window) == "Je... Je... T'es qui ?")
        _name = "entendre";
    else
        _name = "suicide";
}

void Scenario::laruelavrai(sf::RenderWindow *window)
{
    sf::Event event;

    LaRue game(window);
    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            game.handle(event);
        }
        window->clear();
        window->draw(game.s_background);
        for (int it = 0; it < game.buttons.size(); it++) {
            window->draw(game.buttons[it]->rect);
            window->draw(game.buttons[it]->text);
        }
        window->draw(game.s_hands);
        window->draw(game.es_hands);
        window->draw(game.t_score);
        window->draw(game.te_score);
        if (game.score == 3 || game.e_score == 3) {
            if (game.score == 3)
                _name = "vente";
            else
                _name = "conso";
            return;
        }
        game.window->display();
    }
}

void Scenario::Entendre(sf::RenderWindow *window)
{
    sf::Event event;
    size_t scene = 0;
    std::wstring text[] = {
        L"Voix mysterieuse : Je suis le grand bâtisseur de cet espace 2D tridimensionnel",
        L"Je suis le grand…",
        L"L'immense…",
        L"L'unique…",
        L"Le magnifique…",
        L"Johann.",
        L"En d'autre termes, je peux peut-être t'aider."
    };

    while (window->isOpen() && scene != 7) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/johannisme.png");
        drawText(window, text[scene], {0, 550});
        displaySuccess(window);
        window->display();
    }

    ScriptChoice choice(this, "assets/johannisme.png", "Se faire aider ?", "Oui c est ca vas y cause toujours !!", "Au mon dieu, je suis Jeanne d'arc Bis !");

    if (choice.choose(window) == "Oui c est ca vas y cause toujours !!")
        _name = "puissant";
    else
        _name = "johannisme";
}

void Scenario::Suicide(sf::RenderWindow *window)
{
    sf::Event event;
    size_t scene = 0;
    std::wstring text[] = {
        L"Moi : C'est bon ca m'a soule je ragequit into le suicide !",
        L"Moi : Si je vais au 11eme etage d'un immeuble et que je saute, je suis plus proche du ciel ou de la terre ?\nJe serai plus proche du paradis ou des enfers ?"
        L"Moi : On va faire cette petite experience tout de suite !"
    };

    while (window->isOpen() && scene != 3) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/chute.png");
        drawText(window, text[scene], {0, 550});
        displaySuccess(window);
        window->display();
    }
    _name = "chute";
}

void Scenario::Chute(sf::RenderWindow *window)
{
    sf::Event event;
    bool end = false;

    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::Closed)
                 window->close();
            else
                checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/chute.png");
        displaySuccess(window);
        window->display();
    }
    _inScenario = false;
}

void Scenario::Puissant(sf::RenderWindow *window)
{
    sf::Event event;
    size_t scene = 0;
    std::wstring text[] = {
        L"Moi : Le seul être puissant que je connais c'est Booba, et dernierement il a tweete\n“L'autre il revient gonfle au Xanax sur TF1 il nous parle de sa depression\nmais frerot, le monde entier est en train de couler,\non s'en bat les c*uilles de ta vie, tu nous sers a quoi,\non t'a pas attendu pour deprimer....” snif…",
        L"Moi : Bon faut vraiment que je fasse quelque chose de ma vie moi, parce que\nla ca va plus je deviens completement zinzolinax."
    };

    while (window->isOpen() && scene != 2) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/chute.png");
        drawText(window, text[scene], {0, 550});
        displaySuccess(window);
        window->display();
    }

    ScriptChoice choice(this, "", "S'aider ?", "Je vais me prendre en main, j'appelle un Psy.", "Il faut que je trouve quelque chose de trop genial a faire pour me detendre et m'epanouir…");

    if (choice.choose(window) == "Je vais me prendre en main, j'appelle un Psy.")
        _name = "psykologu";
    else
        _name = "equitation";
}

void Scenario::Johannisme(sf::RenderWindow *window)
{
    sf::Event event;
    size_t scene = 0;
    std::wstring text[] = {
        L"Moi : Je dis Merci a la vie ! je dis Merci a Johann !",
        L"Johann (voix mysterieuse) : Ce n'est pas seulement Johann !\nTu vas devoir apprendre l'integralite de mes Adjectifs Qualificatifs\npar coeur si tu veux être un de mes fideles.",
        L"Moi : C'est note, entendu, on s'organisera une p'tite reu.\n"
    };

    while (window->isOpen() && scene != 2) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/johannisme.png");
        drawText(window, text[scene], {0, 550});
        displaySuccess(window);
        window->display();
    }
    _inScenario = false;
}

void Scenario::Equitation(sf::RenderWindow *window)
{
    Horse horse;
    sf::Clock clock;

    while (window->isOpen() && clock.getElapsedTime().asSeconds() < 10)
        horse.renderHorse(window);
    _name = "equitation_gates";
}

void Scenario::EquitationGates(sf::RenderWindow *window)
{
    sf::Event event;
    size_t scene = 0;
    std::wstring text[] = {
        L"Jennifer Gates : Impressionnant, tu manies ton cheval comme personne tu le monte extrêmement bien…",
    };

    while (window->isOpen() && scene != 1) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/equitation_gates.png");
        drawText(window, text[scene], {0, 550});
        displaySuccess(window);
        window->display();
    }

    ScriptChoice choice(this, "assets/equitation_gates.png", "Qu'en dis tu ?", "C'est vrai que j'ai un excellent niveau sur cet univers 2D tridimensionnel", "Venant de toi je suis flatte, tu es une championne, une legende de l'equitation.");

    if (choice.choose(window) == "C'est vrai que j'ai un excellent niveau sur cet univers 2D tridimensionnel")
        _name = "repartie";
    else
        _name = "normale";
}

void Scenario::Repartie(sf::RenderWindow *window)
{
    sf::Event event;
    size_t scene = 0;
    std::wstring text[] = {
        L"Jennifer Gates : Quoi ?",
        L"Moi : Feur",
        L"Jennifer Gates : Quelle repartie haha, je t'epouse"
    };

    while (window->isOpen() && scene != 3) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/equitation_gates.png");
        drawText(window, text[scene], {0, 550});
        displaySuccess(window);
        window->display();
    }
    _name = "marier";
}

void Scenario::Normale(sf::RenderWindow *window)
{
    sf::Event event;
    size_t scene = 0;
    std::wstring text[] = {
        L"Jennifer Gates : Oh il ne faut rien exagerer, tu sais je suis loin d'être une legende,\nje suis une femme normale, celibataire, fille de milirdaire, avec une vie morose, ennuyante.",
        L"Moi : Je suis venu faire de l'equitation pour me remonter le moral, alors commence pas a me parler de tes\nsoucis de gosse pourrie gâtee. Je viens d'une famille modeste, j'ai ete au bord du suicide,\nJ'ai du faire des choix entre l'ecole ou la rue pour m'en sortir, je viens de loin.",
        L"Jennifer Gates : Ouah ! Tu as l'air d'avoir une vie passionnante… Raconte moi un peu plus",
        L"Moi : Blablablablablablabla…",
        L"Jennifer Gates : Blablablablablabla !",
        L"Moi : Blablablablablabla – Blablablablablablabla"
    };

    while (window->isOpen() && scene != 6) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                scene++;
            checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/equitation_gates.png");
        drawText(window, text[scene], {0, 550});
        displaySuccess(window);
        window->display();
    }
    _name = "marier";
}

void Scenario::Kfc(sf::RenderWindow *window)
{
    DefeatKFC engine;
    sf::Event event;
    bool end = false;

    engine.clock.restart();
    while (window->isOpen()) {
        engine.eventHandelling(window);
        if (!window->isOpen())
            break;
        if (engine.checkWon())
            break;
        engine.moveSprites();
        engine.displayWindow(window);
    }
    while (window->isOpen() && end == false) {
        window->clear();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                end = true;
            else if (event.type == sf::Event::Closed)
                window->close();
            else
                checkSuccessDelete(event, window);
        }
        drawSprite(window, "assets/KFC.png");
        displaySuccess(window);
        window->display();
    }
    _inScenario = false;
}

void Scenario::Gaming(sf::RenderWindow *window)
{
    ScriptChoice choice(this, "", "Plutot Video ou 1v1 ?", "La video putaclick bien sur !", "Je suis imbattable en 1v1");

    if (choice.choose(window) == "La video putaclick bien sur !")
        _name = "julienlafarge";
    else
        _name = "beetsaber_end";
}

Scenario::Scenario(const Scenario &scenario) : _name(scenario._name), _choice(scenario._choice), _success(scenario._success), _successPopUp(scenario._successPopUp), _inScenario(true)
{
    initSuccess();
    initChoice();
}

Scenario::Scenario() : _name("epitech"), _inScenario(true)
{
    initSuccess();
    initChoice();
}

Scenario::~Scenario()
{
    setSuccess();
    for (size_t i = 0; i < _successPopUp.size(); i++) {
        delete _successPopUp[i];
    }
}

void Scenario::initChoice()
{
    setMap("start", std::bind(&Scenario::Start, this, std::placeholders::_1), false);
    setMap("jouer", std::bind(&Scenario::Jouer, this, std::placeholders::_1), false);
    setMap("fuir", std::bind(&Scenario::Fuir, this, std::placeholders::_1), false);
    setMap("matrice", std::bind(&Scenario::Matrice, this, std::placeholders::_1), false);
    setMap("rencontre", std::bind(&Scenario::Rencontre, this, std::placeholders::_1), false);
    setMap("conso", std::bind(&Scenario::marcolito, this, std::placeholders::_1), false);
    setMap("laruelavrai", std::bind(&Scenario::laruelavrai, this, std::placeholders::_1), false);
    setMap("reel", std::bind(&Scenario::Reel, this, std::placeholders::_1), true);
    setMap("beetsaber_end", std::bind(&Scenario::BeetSaber_MiniGame, this, std::placeholders::_1), true);
    setMap("psykologu", std::bind(&Scenario::Psykoloke_MiniScene, this, std::placeholders::_1), false);
    setMap("psyjob", std::bind(&Scenario::PsyJob, this, std::placeholders::_1), true);
    setMap("folie", std::bind(&Scenario::Folie, this, std::placeholders::_1), true);
    setMap("rue", std::bind(&Scenario::Rue, this, std::placeholders::_1), false);
    setMap("vente", std::bind(&Scenario::Vente, this, std::placeholders::_1), false);
    setMap("recherche", std::bind(&Scenario::Recherche, this, std::placeholders::_1), false);
    setMap("soiree", std::bind(&Scenario::Soiree, this, std::placeholders::_1), false);
    setMap("sobre", std::bind(&Scenario::Sobre, this, std::placeholders::_1), true);
    setMap("fight", std::bind(&Scenario::FightTheRock, this, std::placeholders::_1), true);
    setMap("julienlafarge", std::bind(&Scenario::JulienLaFarge, this, std::placeholders::_1), true);
    setMap("bill", std::bind(&Scenario::Bill, this, std::placeholders::_1), false);
    setMap("bac", std::bind(&Scenario::BAC, this, std::placeholders::_1), false);
    setMap("ecole", std::bind(&Scenario::Ecole, this, std::placeholders::_1), false);
    setMap("travailler", std::bind(&Scenario::Travailler, this, std::placeholders::_1), false);
    setMap("depression", std::bind(&Scenario::Depression, this, std::placeholders::_1), false);
    setMap("marier", std::bind(&Scenario::Marier, this, std::placeholders::_1), true);
    setMap("entreprise", std::bind(&Scenario::Entreprise, this, std::placeholders::_1), true);
    setMap("medecine", std::bind(&Scenario::Medecine, this, std::placeholders::_1), true);
    setMap("ens", std::bind(&Scenario::Ens, this, std::placeholders::_1), false);
    setMap("supaero", std::bind(&Scenario::Supaero, this, std::placeholders::_1), true);
    setMap("epitech", std::bind(&Scenario::Epitech, this, std::placeholders::_1), false);
    setMap("entendre", std::bind(&Scenario::Entendre, this, std::placeholders::_1), false);
    setMap("suicide", std::bind(&Scenario::Suicide, this, std::placeholders::_1), false);
    setMap("puissant", std::bind(&Scenario::Puissant, this, std::placeholders::_1), false);
    setMap("equitation_gates", std::bind(&Scenario::EquitationGates, this, std::placeholders::_1), false);
    setMap("equitation", std::bind(&Scenario::Equitation, this, std::placeholders::_1), false);
    setMap("johannisme", std::bind(&Scenario::Johannisme, this, std::placeholders::_1), true);
    setMap("chute", std::bind(&Scenario::Chute, this, std::placeholders::_1), true);
    setMap("repartie", std::bind(&Scenario::Repartie, this, std::placeholders::_1), false);
    setMap("normale", std::bind(&Scenario::Normale, this, std::placeholders::_1), false);
    setMap("rien", std::bind(&Scenario::Rien, this, std::placeholders::_1), false);
    setMap("kfc", std::bind(&Scenario::Kfc, this, std::placeholders::_1), true);
    setMap("gaming", std::bind(&Scenario::Gaming, this, std::placeholders::_1), false);
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
            checkSuccessDelete(drug.event, win);
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
        drug.display(this);
    }
    _name = "soiree";
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
