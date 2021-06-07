#include "Monstre.h"

Monstre::Monstre(b2World* world, int zoneActivation, std::string typeMonstre, int x, int y, int givenHealth) 
	: Entite(world,x, y, givenHealth)
	, zoneActivation{zoneActivation}
	, typeMonstre{typeMonstre}
{};

void Monstre::MouvementPredefini(std::vector<std::unique_ptr<struct mouvementAtomique>> mouvements, int zoneActivation) {
	/*
	if (distance()) {
		for (auto mouvementAtomique : mouvements) {

		}
	}
	*/
}