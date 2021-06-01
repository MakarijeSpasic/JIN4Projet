#pragma once
#include "Entite.h"
#include <string>

class PersonnageJoueur :
	public Entite
{
public:
	PersonnageJoueur(int initialCD, int initialVD, int initialPortee, int initialDegats,
		int x, int y, int givenHealth);
	void Deplacer(std::string direction);
	void Apply_damage(int damage);
	void Lose_range(std::string typeObstacle);
	void Lose_damage(std::string typeObstacle);
	void Hit();

protected:
	int Cooldown;
	int VitesseDeplacement;
	int Portee;
	int Degats;
};

