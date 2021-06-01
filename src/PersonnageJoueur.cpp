#include "Entite.h"
#include "PersonnageJoueur.h"

PersonnageJoueur::PersonnageJoueur(int initialCD, int initialVD, 
								   int initialPortee, int initialDegats,
	int x, int y, int givenHealth)
: Entite{ x,y,givenHealth }
, Cooldown{initialCD}
, VitesseDeplacement{initialCD}
, Portee{initialPortee}
, Degats{initialDegats}
{}

void PersonnageJoueur::Deplacer(std::string direction) {
	if (direction == "Gauche") {
		this->coord.x = this->coord.x - 1;
	}
	else if (direction == "Droite") {
		this->coord.x = this->coord.x + 1;
	}
	else if (direction == "Haut") {
		this->coord.y = this->coord.y + 1;
	}
	else if (direction == "Bas"){
		this->coord.y = this->coord.y - 1;
	}
};
void PersonnageJoueur::Apply_damage(int damage) {
	
};
void PersonnageJoueur::Lose_range(std::string typeObstacle) {
	if (typeObstacle == "Gauche") {
		this->coord.x = this->coord.x - 1;
	}
	else if (typeObstacle == "Droite") {
		this->coord.x = this->coord.x + 1;
	}
	else if (typeObstacle == "Haut") {
		this->coord.y = this->coord.y + 1;
	}
	else if (typeObstacle == "Bas") {
		this->coord.y = this->coord.y - 1;
	}
};
void Lose_damage(std::string typeObstacle) {

};
void Hit() {

};
