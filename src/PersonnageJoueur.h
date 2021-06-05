#pragma once
#include "Entite.h"
#include "Monstre.h"

#include <string>
#include <SFML/Graphics/CircleShape.hpp>

#include "SFMLOrthogonalLayer.h"

enum direction {Haut,Bas,Gauche,Droite};

class PersonnageJoueur : public Entite
{
public:
	
	PersonnageJoueur(b2World world,int initialCD, int initialVD, int initialPortee, int initialDegats, int x, int y, int givenHealth);
	void Deplacer(direction dir);
	
	void Lose_range(std::string typeObstacle);
	void Lose_damage(std::string typeObstacle);
	void Hit(Monstre& monstre);

	


protected:
	int Cooldown;
	int VitesseDeplacement;
	int Portee;
	int Degats;
	direction Direction = Haut;

};

