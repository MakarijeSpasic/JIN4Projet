#include "Monstre.h"

Monstre::Monstre(b2World* world, int zoneActivation, std::string typeMonstre, float wrld_x, float wrld_y, int givenHealth)
	: Entite(world,wrld_x,wrld_y, givenHealth)
	, zoneActivation{zoneActivation}
	, typeMonstre{typeMonstre}
{
	shape = sf::CircleShape(convertCoord_fromWorld_toWindow(b2Vec2(1.f, 1.f)).x);//On converti la largeur du rectangle en rayon du cercle
	shape.setFillColor(sf::Color::Red); //On met la couleur rouge pour différencier du joueur
	shape.setPosition(convertCoord_fromWorld_toWindow(body->GetTransform().p));
};

void Monstre::MouvementPredefini(std::vector<std::unique_ptr<struct mouvementAtomique>> mouvements, int zoneActivation) {
	/*
	if (distance()) {
		for (auto mouvementAtomique : mouvements) {

		}
	}
	*/
}