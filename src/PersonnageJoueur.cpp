
#include "PersonnageJoueur.h"

//demilargeur, demilongueur et ecart de base pour le shape d'un personnage
#define HX 1.f
#define HY 1.f
#define ECART 1.f

PersonnageJoueur::PersonnageJoueur(b2World* world, float wrld_x, float wrld_y, int health, int force, int cooldown, float speed, int range) :
	Entite(world, wrld_x, wrld_y, health, force),
	cooldown(cooldown),
	speed(speed),
	range(range)

{
	callback = std::make_unique<PlayerQueryCallback>(PlayerQueryCallback(this));

	shape = sf::CircleShape(convertCoord_fromWorld_toWindow(b2Vec2(1.f, 1.f)).x);//On converti la largeur du rectangle en rayon du cercle
	shape.setFillColor(sf::Color::Green); //On met la couleur verte pour diff�rencier des monstres (on les mettra rouge ?)
	shape.setPosition(convertCoord_fromWorld_toWindow(body->GetTransform().p));

	sword.setFillColor(sf::Color::Blue);
	//this->initFont();
	//this->initHPBar();

	isPlayer = true;
}
;

void PersonnageJoueur::Move(b2Vec2 dir_dt) { //dir_dt serait not� u*dt en physique avec u le vecteur de direction de l'attaque unitaire et dt le laps de temps

	b2Vec2 force = body->GetMass() * (speed * dir_dt - body->GetLinearVelocity()); //F * dt = m * dv avec dv = vitesse voulue - vitesse actuelle => Faut diviser par dt !
	body->ApplyForceToCenter(force,true);
	

}
void PersonnageJoueur::Attack()
{
	//On cr�er une zone rectangulaire devant le joueur (donc garder en t�te la direction vers laquelle il va) si il peut attaquer (cooldown complet)
	//La taille de la zone rectangulaire d�pends du param�tre portee
	//Puis pour chaque body qui croisait la zone, on fait les conversion qu'il faut (perte de portee, de force pour nous et de vie pour les ennemis )
	//Il faut aussi arriver a afficher un rectangle qui fait la m�me taille que la zone

	

	b2Vec2 bodyPosition = body->GetPosition();

	b2Vec2 normal(direction.y,-direction.x); //On fait une rotation du vecteur de pi/2 sens antihoraire

	b2Vec2 attackbox_lowerbound = bodyPosition + (-HY) * normal + (ECART + HX) * direction; 
	b2Vec2 attackbox_upperbound = bodyPosition + HY * normal + (ECART + HX + range) * direction;
	//Calcul de coordonn�es

	attackBox.lowerBound.Set(attackbox_lowerbound.x, attackbox_lowerbound.y);
	attackBox.upperBound.Set(attackbox_upperbound.x, attackbox_upperbound.y);

	
	

	world->QueryAABB(callback, attackBox); //id�alement, callback �tant un attribut de la classe! pas le cas ici parceque c'est impossible de trop modifier b2QueryCallback
	
	//On fait passer le bool�en en true pour signifier qu'on attaque et qu'on doit afficher le rectangle
	attacking = true;
	//On positionne ensuite correctement le shape de l'�p�e : sword
	b2Vec2 sword_shape_center_inWorld = bodyPosition + (ECART + HX + range / 2) * direction;
	b2Vec2 sword_shape_size_inWorld = range * direction + 2 * HX * normal;

	

	sword.setPosition(convertCoord_fromWorld_toWindow(sword_shape_center_inWorld));
	sword.setSize(sf::Vector2f(abs(sword_shape_size_inWorld.x * 10), abs(sword_shape_size_inWorld.y * 10) ) );
	//On peut pas utiliser la fonction de conversion, qui convient aux positions mais pas aux longueurs : il suffit n�amoins de multiplier par 10 :)
	//En effet le changement de systeme de coordonn�e entre world et window
	//ressemble a Ax + B avec A = 10*I, I = mat identit� : bref. On fait juste Ax pour conserver les longueurs
}
;


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
	hpBarBack.setSize(sf::Vector2f(health, 20));
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
