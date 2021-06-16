#pragma once
#include "box2d/box2d.h"
#include "Monstre.h"

#include "PersonnageJoueur.h"
class PersonnageJoueur;

class PlayerQueryCallback : public b2QueryCallback
{
public:
    PlayerQueryCallback();
    PlayerQueryCallback(PersonnageJoueur* owner);
    void SetOwner(PersonnageJoueur* new_owner);
    bool ReportFixture(b2Fixture* fixture) override;

private:

    PersonnageJoueur* owner;

};
