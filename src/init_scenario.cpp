/*
** EPITECH PROJECT, 2022
** init_fuite
** File description:
** init_fuite
*/

#include "scenario.hpp"

static Scenario *getFuir()
{
    Scenario *fuir = new Scenario("fuir");

    return (fuir);
}

static Scenario *getMatrice()
{
    Scenario *matrice = new Scenario("matrice");

    return (matrice);
}

void init_scenario()
{
    Scenario *scenario = new Scenario("start");

    scenario->addScene("Bienvenue dans notre jeu de la vie! Ici vous pourrez devenir une meilleure version de vous même! Une super version de vous même! Comme chacun vous allez naitre et acquérir les compétences propes aux bons développements de tout être humain! Vous réaliserez des choix et affronterez leurs conséquences. Car comme touts être il vous faudra vous comprendre pour vous accepter. Savoir vivre en société, apprendre et réaliser que vous être incroyable. Plus qu'incroyable même ! Que vous êtes supérieur ! Vous devriez diriger ! Faire réaliser à cette espèce qui est le maître et qui est ce qu'elle doit écouter. Maintenant la question est comment ? Devriez vous développer des compétences politique afin de prendre controle des parties et devenir un modèle aux yeux de tous ? Ou peut-être asservir le peuple et leur faire réaliser ce que la loi du plus fort signifie. Ou encore anéantir l'espèce humaine afin de créer une espèce supérieur basé sur vos gènes !!!! AHHAHAHAHHHAHAHAHHAHAHAHAHHAHAHAHAHAHAHAHAHHAHAHAHAHHAHAHAHAHHAHAHAHAHH!!!! TELLEMENT DE POSSIBILITÉ DE POUVOIR ET DE CONTROLE !!!!!!! AHAHHAHAHAHAHHAHHAHAHAHAHAH !!!! DEVENEZ LE MAITRE !!!! LE MAITRE !!! LE MAITRE !!!!!!!!!!! ET REMPORTEZ TOUS LES SUCCES !!!!!", "");
    scenario->addScene("", "assets/black_screen_gorilla.jpg");
    scenario->setMap("Fuir?", getFuir());
    scenario->setMap("Accepter", getMatrice());
    delete scenario;
}