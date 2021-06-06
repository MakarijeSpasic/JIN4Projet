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

void PersonnageJoueur::Deplacer(b2Vec2 dir_dt) { //dir_dt serait noté u*dt en physique avec u le vecteur de direction de l'attaque unitaire et dt le laps de temps

	b2Vec2 force = body->GetMass() * (VitesseDeplacement * dir_dt - body->GetLinearVelocity()); //F * dt = m * dv avec dv = vitesse voulue - vitesse actuelle => Faut diviser par dt !
	body->ApplyForceToCenter(force,true);
	//body->SetLinearVelocity(force);

}
void PersonnageJoueur::Attaquer(b2World* world, MyQueryCallback query)
{
	//On créer une zone rectangulaire devant le joueur (donc garder en tête la direction vers laquelle il va) si il peut attaquer (cooldown complet)
	//La taille de la zone rectangulaire dépends du paramètre portee
	//Puis pour chaque body qui croisait la zone, on fait les conversion qu'il faut (perte de portee, de force pour nous et de vie pour les ennemis )
	//Il faut aussi arriver a afficher un rectangle qui fait la même taille que la zone



	b2Vec2 bodyPosition = body->GetPosition();

	b2Vec2 normal((direction.x + direction.y) / 2,(direction.x - direction.y)/2 ); //On fait une rotation du vecteur de pi/2 

	float attackbox_lowerbound_x = bodyPosition.x + 10.f * direction.x;
	float attackbox_lowerbound_y = bodyPosition.y - 10.f * normal.y;
	float attackbox_upperbound_x = bodyPosition.x + Portee * 10.f * direction.x;
	float attackbox_upperbound_y = bodyPosition.y + 10.f * normal.y;
	//Je les stock sous forme de float pour ensuite faire des conversions et créer un sf::rectangleShape correctement
	//par contre comment l'afficher ...

	attackBox.lowerBound.Set(attackbox_lowerbound_x, attackbox_lowerbound_y);
	attackBox.upperBound.Set(attackbox_upperbound_x, attackbox_upperbound_y);

	//On définit la zone simplement : les 10.f c'est la taille du shape du joueur
	//A modifier



}
;


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

}

//Pour garder en mémoire la direction dans laquelle le joueur se déplace

void PersonnageJoueur::UpdateDirection()
{
	b2Vec2 v = body->GetLinearVelocity();
	v.Normalize();
	direction = v; //Vu que Normalize() modifie directement le vecteur faut que j'en utilise en intermédiaire : pas efficace du tout


}
