#include "Entite.h"

Entite::Entite(b2World world, int x, int y, int givenHealth) 
	:health(givenHealth)
{
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);
	body = world.CreateBody(&bodyDef);
	dynamic_box.SetAsBox(1.0f, 1.0f);//On fait une boite de cette taille là pour l'instant
	fixtureDef.shape = &dynamic_box;
	fixtureDef.density = 1.0f;
	body->CreateFixture(&fixtureDef);
}


void Entite::Lose_health(int damage) {
	this->health = this->health - damage;
};