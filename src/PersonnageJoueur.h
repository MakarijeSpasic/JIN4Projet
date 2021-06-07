#pragma once
#include "Entite.h"
#include "Monstre.h"

#include <string>
#include <PlayerQueryCallback.h>

#include <SFML/Graphics/RectangleShape.hpp>




class PersonnageJoueur : public Entite
{
public:
	
	PersonnageJoueur(b2World* world, float wrld_x, float wrld_y, int givenHealth,int givenForce, int initialCD, int initialVD, int initialPortee);
	
	void Deplacer(b2Vec2 dir);
	void Attaquer(b2World* world, PlayerQueryCallback* callback);
	
	void Lose_range(std::string typeObstacle);
	void Lose_damage(std::string typeObstacle);
	void Hit(Monstre& monstre);

	//Méthodes pour les attaques
	void UpdateDirection(b2Vec2 dir);
	b2AABB GetAABB() { return attackBox; };
	sf::RectangleShape GetSword() { return sword; };
	bool isAttacking() { return attacking; };
	void setAttacking(bool v) { attacking = v; };

	b2Vec2 GetDirection() { return direction; };

protected:
	int Cooldown;
	int VitesseDeplacement;
	int Portee;
	
	//Pour les attaques
	b2Vec2 direction;
	b2AABB attackBox;
	sf::RectangleShape sword;
	bool attacking = false;
	

};

