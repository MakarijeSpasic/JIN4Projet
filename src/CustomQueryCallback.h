#pragma once
#include "box2d/box2d.h"
#include "PersonnageJoueur.h"
#include "Monstre.h"

class CustomQueryCallback : public b2QueryCallback
{
public:
    bool ReportFixture(b2Fixture* fixture);
    

};

