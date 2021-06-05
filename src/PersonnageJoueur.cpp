#include "Entite.h"
#include "PersonnageJoueur.h"

PersonnageJoueur::PersonnageJoueur(b2World* world, float wrld_x, float wrld_y, int givenHealth, int initialCD, int initialVD, int initialPortee, int initialDegats):
	Entite(world, wrld_x, wrld_y, givenHealth),
	Cooldown(initialCD),
	VitesseDeplacement(initialVD),
	Portee(initialPortee),
	Degats(initialDegats)
	
{
	
}
;

void PersonnageJoueur::Deplacer(b2Vec2 dir) {

	b2Vec2 force = VitesseDeplacement * dir; //Attention de mettre la constante devant 
	body->ApplyForceToCenter(force,true);

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
	}
}
void PersonnageJoueur::Hit(Monstre& monstre) { //On tape des monstres

};
