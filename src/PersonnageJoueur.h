#pragma once
#include "Entite.h"
#include "Monstre.h"

#include <string>
#include "../build/src/MyQueryCallback.h"

#include <SFML/Graphics/RectangleShape.hpp>




class PersonnageJoueur : public Entite
{
public:
	
	PersonnageJoueur(b2World* world, float wrld_x, float wrld_y, int givenHealth, int initialCD, int initialVD, int initialPortee, int initialDegats);
	
	void Deplacer(b2Vec2 dir);
	void Attaquer(b2World* world, MyQueryCallback query);
	
	void Lose_range(std::string typeObstacle);
	void Lose_damage(std::string typeObstacle);
	void Hit(Monstre& monstre);

	//M�thodes pour les attaques
	void UpdateDirection();
	b2AABB GetAABB() { return attackBox; };


protected:
	int Cooldown;
	int VitesseDeplacement;
	int Portee;
	int Degats;
	//Pour les attaques
	b2Vec2 direction;
	b2AABB attackBox;
	sf::RectangleShape sword;
};
