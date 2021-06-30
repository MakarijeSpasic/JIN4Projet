#include "Monstre.h"

Monstre::Monstre(b2World* world, int zoneActivation, TypeMonstre type, float wrld_x, float wrld_y, int health, int force)
	: Entite(world,wrld_x,wrld_y, health,force)
	, zoneActivation(zoneActivation)
	, type(type)
{
	switch (type) {
	case Monstre1:
		shape = sf::CircleShape(convertCoord_fromWorld_toWindow(b2Vec2(1.f, 1.f)).x, 3); //C'est un triangle
		break;
	case Monstre2:
		shape = sf::CircleShape(convertCoord_fromWorld_toWindow(b2Vec2(1.f, 1.f)).x, 4); //C'est un pentagone
		break;
	case Monstre3:
		shape = sf::CircleShape(convertCoord_fromWorld_toWindow(b2Vec2(1.f, 1.f)).x,5); //C'est un octogone
	}
	//au dessus : On converti la largeur du rectangle(la boite qui sert de body à l'entite) en rayon du cercle pour que ce soit cohérent
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