#include "Entite.h"

Entite::Entite(b2World* world, float x, float y, int givenHealth) 
	: health(givenHealth)
{
	//Création d'un body que l'on va pouvoir manipuler

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);
	body = world->CreateBody(&bodyDef);
	dynamic_box.SetAsBox(1.0f, 1.0f);//On fait une boite de cette taille là pour l'instant
	fixtureDef.shape = &dynamic_box;
	fixtureDef.density = 1.0f;
	body->CreateFixture(&fixtureDef);


	shape = sf::CircleShape(10);
	shape.setFillColor(sf::Color::Green); //On met la couleur verte pour différencier des monstres (on les mettra rouge ?)
	//shape.setPosition(coord.x; coord.y);

}

void Entite::Attaque()
{
}

void Entite::Lose_health(int damage) {
	this->health = this->health - damage;
}

void Entite::UpdateWindowPosition()
{
	shape.setPosition(convertCoord_fromWorld_toWindow(body->GetTransform().p));
}

b2Vec2 Entite::convertCoord_fromWindow_toWorld(sf::Vector2f win_coord)
{
	//On va partir sur un écran de 600 par 800 de base et fixer ça pour pas s'emmerder pcq sinon c'est juste chiant
	//Faudrait le mettre en variable de la méthode
	//Ou bien trouver un moyen de stocker ça
	//-> flemme

	b2Vec2 res(win_coord.x / 10, (800 - win_coord.y) / 10);

	return res;

}
sf::Vector2f Entite::convertCoord_fromWorld_toWindow(b2Vec2 wrld_coord)
{
	sf::Vector2f res(wrld_coord.x * 10, (800 - wrld_coord.y) * 10);

	return res;
}
;