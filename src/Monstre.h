#pragma once
#include "Entite.h"
#include <string>
#include <vector>
#include <memory>

class Monstre :
	public Entite
{
public:
	Monstre(b2World* world, int zoneActivation, std::string typeMonstre, float wrld_x, float wrld_y, int givenHealth);
	void MouvementPredefini(std::vector<std::unique_ptr<struct mouvementAtomique>>, int zoneActivation);
protected:
	int zoneActivation;
	std::string typeMonstre;
};

struct mouvementAtomique {
	int distance; // en pixels
	std::string direction; // Haut, Bas, Gauche, Droite

};

