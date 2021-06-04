#include "Entite.h"
#include "PersonnageJoueur.h"

PersonnageJoueur::PersonnageJoueur(int initialCD, int initialVD,int initialPortee, int initialDegats,int x, int y, int givenHealth):
	Entite(x,y,givenHealth),
	Cooldown(initialCD),
	VitesseDeplacement(initialVD),
	Portee(initialPortee),
	Degats(initialDegats)
	
{
	
	shape = sf::CircleShape(10);
	shape.setFillColor(sf::Color::Green); //On met la couleur verte pour différencier des monstres (on les mettra rouge ?)
	shape.setPosition(coord.x,coord.y);

}
;

int limitTerrainX;
int limitTerrainY;
void PersonnageJoueur::Deplacer(direction dir) {
	
	switch (dir) {
	case Haut:
		break;
	case Bas :
		break;
	case Gauche:
		break;
	case Droite:
		break;
	default:
		break;
	}
	
	
};
void PersonnageJoueur::Lose_health(int damage) {
	this->health = this->health - damage;
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
