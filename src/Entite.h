#pragma once
#include "box2d/box2d.h"
#include <SFML/Graphics/CircleShape.hpp>

class Entite
{
public:
	Entite(b2World* world, float wrld_x, float wrld_y, int givenHealth, int giverForce);
	//On prend un monde en argument pour créer l'entité dedans => Peut être prendre un pointeur ??
	
	void Lose_health(int damage);

	b2Body* GetBody() { return body; };

//Methodes ayant à voir avec l'allure du personnage
	
	//Update shape position in windows according to position in b2World
	void UpdateWindowPosition();
	

	sf::CircleShape GetShape() { return shape; }

	int GetHealth() { return health; }
	int GetForce() { return force; }

private:
	
	

protected:

	
	//Pour faire des conversions
	b2Vec2 convertCoord_fromWindow_toWorld(sf::Vector2f win_coord);
	sf::Vector2f convertCoord_fromWorld_toWindow(b2Vec2 wrld_coord);

	//Box2D attributes
	
	b2BodyDef bodyDef;
	b2Body* body;//Il faut un world pour le créer à partir de &bodyDef
	b2PolygonShape dynamic_box;
	b2FixtureDef fixtureDef;
	//SFML attributes
	  
	sf::CircleShape shape;

	//Other
	int health;
	int force;//La force d'attaque d'une entité


};

