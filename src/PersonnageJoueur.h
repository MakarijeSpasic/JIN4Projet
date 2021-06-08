#pragma once
#include "Entite.h"
#include "Monstre.h"

#include <string>
#include <PlayerQueryCallback.h>

#include <SFML/Graphics/RectangleShape.hpp>




class PersonnageJoueur : public Entite
{
public:
	
	PersonnageJoueur(b2World* world, float wrld_x, float wrld_y, int health,int force, int cooldown, int speed, int range);
	
	void Move(b2Vec2 dir);
	void Attack(b2World* world, PlayerQueryCallback* callback);
	
	void LoseRange(TypeMonstre type);
	void LoseForce(TypeMonstre type); //N'override pas la fonction LoseForce de Entite car l'utilise pour modifier la force

	//M�thodes pour les attaques
	void UpdateDirection(b2Vec2 dir);
	b2AABB GetAABB() { return attackBox; };
	sf::RectangleShape GetSword() { return sword; };
	bool isAttacking() { return attacking; };
	void setAttacking(bool v) { attacking = v; };

	b2Vec2 GetDirection() { return direction; };

protected:
	int cooldown;
	int speed;
	int range;
	
	//Pour les attaques
	b2Vec2 direction;
	b2AABB attackBox;
	sf::RectangleShape sword;
	bool attacking = false;
	

};

