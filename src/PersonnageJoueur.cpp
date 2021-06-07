
#include "PersonnageJoueur.h"

//demilargeur, demilongueur et ecart de base pour le shape d'un personnage
#define HX 1.f
#define HY 1.f
#define ECART 1.f

PersonnageJoueur::PersonnageJoueur(b2World* world, float wrld_x, float wrld_y, int givenHealth, int givenForce, int initialCD, int initialVD, int initialPortee) :
	Entite(world, wrld_x, wrld_y, givenHealth, givenForce),
	Cooldown(initialCD),
	VitesseDeplacement(initialVD),
	Portee(initialPortee)

{
	//callback = PlayerQueryCallback(this);

	shape = sf::CircleShape(convertCoord_fromWorld_toWindow(b2Vec2(1.f, 1.f)).x);//On converti la largeur du rectangle en rayon du cercle
	shape.setFillColor(sf::Color::Green); //On met la couleur verte pour différencier des monstres (on les mettra rouge ?)
	shape.setPosition(convertCoord_fromWorld_toWindow(body->GetTransform().p));

	sword.setFillColor(sf::Color::Blue);
}
;

void PersonnageJoueur::Deplacer(b2Vec2 dir_dt) { //dir_dt serait noté u*dt en physique avec u le vecteur de direction de l'attaque unitaire et dt le laps de temps

	b2Vec2 force = body->GetMass() * (VitesseDeplacement * dir_dt - body->GetLinearVelocity()); //F * dt = m * dv avec dv = vitesse voulue - vitesse actuelle => Faut diviser par dt !
	body->ApplyForceToCenter(force,true);
	

}
void PersonnageJoueur::Attaquer(b2World* world, PlayerQueryCallback* callback)
{
	//On créer une zone rectangulaire devant le joueur (donc garder en tête la direction vers laquelle il va) si il peut attaquer (cooldown complet)
	//La taille de la zone rectangulaire dépends du paramètre portee
	//Puis pour chaque body qui croisait la zone, on fait les conversion qu'il faut (perte de portee, de force pour nous et de vie pour les ennemis )
	//Il faut aussi arriver a afficher un rectangle qui fait la même taille que la zone

	

	b2Vec2 bodyPosition = body->GetPosition();

	b2Vec2 normal(direction.y,-direction.x); //On fait une rotation du vecteur de pi/2 sens antihoraire

	b2Vec2 attackbox_lowerbound = bodyPosition + (-HY) * normal + (ECART + HX) * direction; 
	b2Vec2 attackbox_upperbound = bodyPosition + HY * normal + (ECART + HX + Portee) * direction;
	//Calcul de coordonnées

	attackBox.lowerBound.Set(attackbox_lowerbound.x, attackbox_lowerbound.y);
	attackBox.upperBound.Set(attackbox_upperbound.x, attackbox_upperbound.y);

	
	

	world->QueryAABB(callback, attackBox); //idéalement, callback étant un attribut de la classe! pas le cas ici parceque c'est impossible de trop modifier b2QueryCallback
	
	//On fait passer le booléen en true pour signifier qu'on attaque et qu'on doit afficher le rectangle
	attacking = true;
	//On positionne ensuite correctement le shape de l'épée : sword
	b2Vec2 sword_shape_center_inWorld = bodyPosition + (ECART + HX + Portee / 2) * direction;
	b2Vec2 sword_shape_size_inWorld = Portee * direction + 2 * HX * normal;

	

	sword.setPosition(convertCoord_fromWorld_toWindow(sword_shape_center_inWorld));
	sword.setSize(sf::Vector2f(abs(sword_shape_size_inWorld.x * 10), abs(sword_shape_size_inWorld.y * 10) ) );
	//On peut pas utiliser la fonction de conversion, qui convient aux positions mais pas aux longueurs : il suffit néamoins de multiplier par 10 :)
	//En effet le changement de systeme de coordonnée entre world et window
	//ressemble a Ax + B avec A = 10*I, I = mat identité : bref. On fait juste Ax pour conserver les longueurs
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
		force--;
	}
	else if (typeObstacle == "Monstre2") {
		force-=2;
	}
	else if (typeObstacle == "Monstre3") {
		force-=3;
	}
	else if (typeObstacle == "Mur") {
		force-=1;
	}
}
void PersonnageJoueur::Hit(Monstre& monstre) { //On tape des monstres

}

//Pour garder en mémoire la direction dans laquelle le joueur se déplace

void PersonnageJoueur::UpdateDirection(b2Vec2 dir)
{
	direction = dir;
}
