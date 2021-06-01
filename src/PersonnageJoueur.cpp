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
int limitTerrainX;
int limitTerrainY;
void PersonnageJoueur::Deplacer(std::string direction) {
	if (direction == "Gauche") {
		if (this->coord.x > 0) {
			this->coord.x = this->coord.x - 1;
		}
	}
	else if (direction == "Droite") {
		if (this->coord.x < limitTerrainX) {
			this->coord.x = this->coord.x + 1;
		}
	}
	else if (direction == "Haut") {
		if (this->coord.y < limitTerrainY) {
			this->coord.y = this->coord.y + 1;
		}
	}
	else if (direction == "Bas"){
		if (this->coord.y > 0) {
			this->coord.y = this->coord.y - 1;
		}
	}
};
void PersonnageJoueur::Apply_damage(int damage) {
	
};
void PersonnageJoueur::Lose_range(std::string typeObstacle) {
	if (typeObstacle == "Monstre1") {
		this->Portee = this->Portee - 1;
	}
	else if (typeObstacle == "Monstre2") {
		this->Portee = this->Portee - 2;
	}
	else if (typeObstacle == "Monstre3") {
		this->Portee = this->Portee - 3;
	}
	else if (typeObstacle == "Mur") {
		this->Portee = this-> Portee - 1;
	}
};
void PersonnageJoueur::Lose_damage(std::string typeObstacle) {
	if (typeObstacle == "Monstre1") {
		this->Degats = this->Degats - 1;
	}
	else if (typeObstacle == "Monstre2") {
		this->Degats = this->Degats - 2;
	}
	else if (typeObstacle == "Monstre3") {
		this->Degats = this->Degats - 3;
	}
	else if (typeObstacle == "Mur") {
		this->Degats = this->Degats - 1;
	};
}
void PersonnageJoueur::Hit() {

};
