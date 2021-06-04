#pragma once
#include "Entite.h"
#include "Monstre.h"

#include <string>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "SFMLOrthogonalLayer.h"

class PersonnageJoueur : public Entite
{
public:
	
	PersonnageJoueur(int initialCD, int initialVD, int initialPortee, int initialDegats, int x, int y, int givenHealth);
	void Deplacer(std::string direction);
	void Lose_health(int damage);
	void Lose_range(std::string typeObstacle);
	void Lose_damage(std::string typeObstacle);
	void Hit(Monstre& monstre);

	//Methodes ayant à voir avec l'allure du personnage

	sf::CircleShape GetShape() { return shape; }


protected:
	int Cooldown;
	int VitesseDeplacement;
	int Portee;
	int Degats;

	sf::CircleShape shape;
};

