#pragma once
#include "Entite.h"
#include "Monstre.h"

#include <string>






class PersonnageJoueur : public Entite
{
public:
	
	PersonnageJoueur(b2World* world, int x, int y, int givenHealth, int initialCD, int initialVD, int initialPortee, int initialDegats);
	void Deplacer(b2Vec2 dir);
	
	void Lose_range(std::string typeObstacle);
	void Lose_damage(std::string typeObstacle);
	void Hit(Monstre& monstre);




protected:
	int Cooldown;
	int VitesseDeplacement;
	int Portee;
	int Degats;

};

