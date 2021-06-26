
#include "PersonnageJoueur.h"
#include <stdio.h>
#include <stdlib.h>

//demilargeur, demilongueur et ecart de base pour le shape d'un personnage
#define HX 1.f
#define HY 1.f
#define ECART 0.5f

PersonnageJoueur::PersonnageJoueur(b2World* world, float wrld_x, float wrld_y, int health, int force, int cooldown, float speed, int range, int pieces) :
	Entite(world, wrld_x, wrld_y, health, force),
	cooldown(cooldown),
	speed(speed),
	range(range),
	pieces(pieces)

{
	callback = std::make_unique<PlayerQueryCallback>(this);

	shape = sf::CircleShape(convertCoord_fromWorld_toWindow(b2Vec2(1.f, 1.f)).x);//On converti la largeur du rectangle en rayon du cercle
	shape.setFillColor(sf::Color::Green); //On met la couleur verte pour diff�rencier des monstres (on les mettra rouge ?)
	shape.setPosition(convertCoord_fromWorld_toWindow(body->GetTransform().p));

	sword.setFillColor(sf::Color::Blue);
	//this->initFont();
	//this->initHPBar();

	isPlayer = true;
	canAttack = true;
	
}
;

void PersonnageJoueur::Move(b2Vec2 dir_dt) { //dir_dt serait not� u*dt en physique avec u le vecteur de direction de l'attaque unitaire et dt le laps de temps

	b2Vec2 force = body->GetMass() / (1 / 60.f) * (speed * dir_dt - body->GetLinearVelocity()); //F  = mv/t
	body->ApplyForceToCenter(force,true);
	

}
void PersonnageJoueur::Attack()
{
	//On cr�er une zone rectangulaire devant le joueur (donc garder en t�te la direction vers laquelle il va) si il peut attaquer (cooldown complet)
	//La taille de la zone rectangulaire d�pends du param�tre portee
	//Puis pour chaque body qui croisait la zone, on fait les conversion qu'il faut (perte de portee, de force pour nous et de vie pour les ennemis )
	//Il faut aussi arriver a afficher un rectangle qui fait la m�me taille que la zone

	

	b2Vec2 bodyPosition = body->GetPosition();
	//printf("bodyPosition = (%f,%f) \n", bodyPosition.x, bodyPosition.y);

	b2Vec2 normal(-direction.y,direction.x); //On fait une rotation du vecteur de pi/2 sens antihoraire
	//printf("normal = (%f,%f) \n", normal.x, normal.y);

	b2Vec2 attackbox_corner1 = bodyPosition + (-HY) * normal + (ECART + HX) * direction; 
	b2Vec2 attackbox_corner2 = bodyPosition + HY * normal + (ECART + HX + range) * direction;

	//Un rectangle est defini par 2 coin. Mais il faut que ces coins soient bien alignés, c'est à dire que lowerbound_x(y) < upperbound_x(y)
	
	float lowerbound_x = std::min(attackbox_corner1.x, attackbox_corner2.x);
	float lowerbound_y = std::min(attackbox_corner1.y, attackbox_corner2.y);
	float upperbound_x = std::max(attackbox_corner1.x, attackbox_corner2.x);
	float upperbound_y = std::max(attackbox_corner1.y, attackbox_corner2.y);
	
	//printf("attackbox_lowerbound = (%f,%f) \n", lowerbound_x, lowerbound_y);
	//printf("attackbox_upperbound = (%f,%f) \n", upperbound_x, upperbound_y);

	

	//Calcul de coordonn�es
	attackBox.lowerBound.Set(lowerbound_x, lowerbound_y);
	attackBox.upperBound.Set(upperbound_x, upperbound_y);

	

	world->QueryAABB(callback.get(), attackBox); //On utilise unique_ptr::get pour avoir un raw pointer parceque sinon c'était pas possible à convertir correctement (peut être avec un move ?)
	
	//On fait passer le booleen en false pour signifier qu'on peut plus attaquer
	canAttack = false;
	//On positionne ensuite correctement le shape de l'epee : sword, pour l'affichage
	b2Vec2 sword_shape_center_inWorld = attackBox.GetCenter();
	b2Vec2 sword_shape_size_inWorld = 2 * attackBox.GetExtents();

	//printf("sword_shape_center_inworld = (%f,%f) \n", sword_shape_center_inWorld.x, sword_shape_center_inWorld.y);
	//printf("sword_shape_size_inworld = (%f,%f) \n", sword_shape_size_inWorld.x, sword_shape_size_inWorld.y);
	

	sword.setPosition(convertCoord_fromWorld_toWindow(sword_shape_center_inWorld));
	sword.setSize(sf::Vector2f(abs(sword_shape_size_inWorld.x * 10), abs(sword_shape_size_inWorld.y * 10) ) );
	sword.setPosition(sword.getPosition().x, sword.getPosition().y);
	//printf("sword position = (%f,%f) \n", sword.getPosition().x / 10, (608 - sword.getPosition().y) / 10 );



	//On peut pas utiliser la fonction de conversion, qui convient aux positions mais pas aux longueurs : il suffit n�amoins de multiplier par 10 :)
	//En effet le changement de systeme de coordonn�e entre world et window
	//ressemble a Ax + B avec A = 10*I, I = mat identit� : bref. On fait juste Ax pour conserver les longueurs
	//On prend aussi les valeurs absolu parcequ'une longueur négative ne veut rien dire
}
;

void PersonnageJoueur::SetStats(int cooldown_modif, float speed_modif, int range_modif) {
	cooldown = cooldown + cooldown_modif;
	speed = speed + speed_modif;
	range = range + range_modif;
}

int PersonnageJoueur::getPieces() {
	return pieces;
}

void PersonnageJoueur::setPieces(int newPieces) {
	pieces = newPieces;
}



void PersonnageJoueur::LoseRange(TypeMonstre type) {
	switch (type) {
	case Monstre1:
		range -= 3;
		break;
	case Monstre2:
		range -= 2;
		break;
	case Monstre3:
		range -= 1;
		break;
	}
}

void PersonnageJoueur::LoseForce(TypeMonstre type)
{
	switch (type) {
	case Monstre1:
		Entite::LoseForce(1);
		break;
	case Monstre2:
		Entite::LoseForce(2);
		break;
	case Monstre3:
		Entite::LoseForce(3);
		break;
	}
}




//Pour garder en m�moire la direction dans laquelle le joueur se d�place

void PersonnageJoueur::UpdateDirection(b2Vec2 dir)
{
	direction = dir;
}


void PersonnageJoueur::updateHPBar()
{
	hpBarInside.setSize(sf::Vector2f(health*10, 20));
}

void PersonnageJoueur::renderHPBar(sf::RenderWindow* window)
{
	window->draw(hpBarBack);
	window->draw(hpBarInside);
}


void PersonnageJoueur::initFont()
{
	font.loadFromFile("../../resources/mangat.ttf");
}


void PersonnageJoueur::initHPBar()
{
	hpBarBack.setSize(sf::Vector2f(100.f, 20.f));
	hpBarBack.setFillColor(sf::Color(sf::Color::Red));
	hpBarBack.setPosition(20.f, 20.f);

	hpBarInside.setSize(sf::Vector2f(100.f, 20.f));
	hpBarInside.setFillColor(sf::Color(sf::Color::Green));
	hpBarInside.setPosition(this->hpBarBack.getPosition());
}
