#pragma once
#include "box2d/box2d.h"
#include "Monstre.h"

class PlayerQueryCallback : public b2QueryCallback
{
public:
    bool ReportFixture(b2Fixture* fixture);


    //PersonnageJoueur* owner; //On veut un unique_ptr<PersonnageJoueur> qu'on initialise dans le constructeur avec make_unique(...) 
    //Mais ça marche pas donc on va faire sans, tant pis. 
    //Et même en ajoutant le pointeur simple rien ne marche, pourtant c'est possible d'ajouter des attributs
    //A une classe héritante ... 
};
