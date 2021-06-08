#include "Monstre.h"

Monstre::Monstre(b2World* world, int zoneActivation, TypeMonstre type, float wrld_x, float wrld_y, int health, int force)
	: Entite(world,wrld_x,wrld_y, health,force)
	, zoneActivation(zoneActivation)
	, type(type)
{
	shape = sf::CircleShape(convertCoord_fromWorld_toWindow(b2Vec2(1.f, 1.f)).x);//On converti la largeur du rectangle en rayon du cercle
	shape.setFillColor(sf::Color::Red); //On met la couleur rouge pour différencier du joueur
	shape.setPosition(convertCoord_fromWorld_toWindow(body->GetTransform().p));
	isPlayer = false;
};

void Monstre::MouvementPredefini(std::vector<std::unique_ptr<struct mouvementAtomique>> mouvements, int zoneActivation) {
	/*
	if (distance()) {
		for (auto mouvementAtomique : mouvements) {

		}
	}
	*/
}