#pragma once
#include "Entite.h"

#include <vector>
#include <memory>
#include <string>

class Monstre :
	public Entite
{
public:
	Monstre(b2World* world, int zoneActivation, TypeMonstre type, float wrld_x, float wrld_y, int health, int force);
	
	void MouvementPredefini(std::vector<std::unique_ptr<struct mouvementAtomique>> mouvements, int zoneActivation);

	TypeMonstre GetType() { return type; }

protected:
	int zoneActivation;
	TypeMonstre type; //le type de monstre
};

struct mouvementAtomique {
	int distance; // en pixels
	std::string direction; // Haut, Bas, Gauche, Droite

};

