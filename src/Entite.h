#pragma once
#include "box2d/box2d.h"

class Entite
{
public:
	Entite(b2World world, int x, int y, int givenHealth); //On prend un monde en argument pour cr�er l'entit� dedans => Peut �tre prendre un pointeur ??
	virtual void attaque() = 0;
	void Lose_health(int damage);

	b2Body* GetBody() { return body; }

	//Methodes ayant � voir avec l'allure du personnage

	sf::CircleShape GetShape() { return shape; }

protected:
	//Box2D attributes
	
	b2BodyDef bodyDef;
	b2Body* body;//Il faut un world pour le cr�er � partir de &bodyDef
	b2PolygonShape dynamic_box;
	b2FixtureDef fixtureDef;
	//SFML attributes
	// 	   
	sf::CircleShape shape;
	//Other
	int health;
};

