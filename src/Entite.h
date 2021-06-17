#pragma once
#include "box2d/box2d.h"
#include <SFML/Graphics/CircleShape.hpp>

enum TypeMonstre{Monstre1,Monstre2,Monstre3};



class Entite
{
public:
	Entite(b2World* world, float wrld_x, float wrld_y, int givenHealth, int giverForce);
	//On prend un monde en argument pour cr�er l'entit� dedans => Peut �tre prendre un pointeur ??
	
	void LoseHealth(int damage);
	void LoseForce(int loss);

	b2Body* GetBody() { return body; };

//Methodes ayant � voir avec l'allure du personnage
	
	//Update shape position in windows according to position in b2World
	void UpdateWindowPosition();
	

	sf::CircleShape GetShape() { return shape; }

	int GetHealth() { return health; }
	int GetForce() { return force; }
	int GetIsPlayer() { return isPlayer; }; //Syntaxe moche et pas raccord avec la fonction isAttacking() dans PersonnageJoueur.hpp mais on fera avec

protected:

	
	//Pour faire des conversions
	b2Vec2 convertCoord_fromWindow_toWorld(sf::Vector2f win_coord);
	sf::Vector2f convertCoord_fromWorld_toWindow(b2Vec2 wrld_coord);

	//Box2D attributes
	b2World* world;
	b2BodyDef bodyDef;
	b2Body* body;//Il faut un world pour le cr�er � partir de &bodyDef
	b2PolygonShape dynamic_box;
	b2FixtureDef fixtureDef;

	//SFML attributes  
	sf::CircleShape shape;

	//Other
	int health;
	int force;//La force d'attaque d'une entit�
	bool isPlayer; 
	//Dans le contactListener, on peut r�cup�rer un pointeur vers l'objet d�tenant le body qui est entr� en contact
	//Mais c'est un pointeur vers une entit� et on ne peux pas savoir si l'Entite point�
	//Est un PersonnageJoueur ou un Monstre
	//On va donc garder un bool�en en stock pour pouvoir downCaster sans erreur.
	//Entite �tant une classe abstraite 
	//Alors Entite est forc�ment un personnageJoueur ou un Monstre
	//On pourrait essayer de faire une fonction DynamicCast<T> comme j'ai pu voir surinternet

};

