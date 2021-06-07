#include "Entite.h"

Entite::Entite(b2World* world, float wrld_x, float wrld_y, int givenHealth) 
	: health(givenHealth)
{
	//Création d'un body que l'on va pouvoir manipuler

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(wrld_x, wrld_y);//On bouge le body avant de le créer dans le monde : meilleur perf
	bodyDef.allowSleep = true;//Aussi pour les performances : si le body ne bouge pas il est mis au repos => moins de CPU
	bodyDef.awake = true;
	bodyDef.fixedRotation = true;//On ne veut pas qu'il tourne
	bodyDef.linearDamping = 0.1f;//TEST
	body = world->CreateBody(&bodyDef);
	dynamic_box.SetAsBox(1.0f, 1.0f);//On fait une boite de cette taille là pour l'instant
	fixtureDef.shape = &dynamic_box;
	fixtureDef.density = 1.0f;
	body->CreateFixture(&fixtureDef);


	shape = sf::CircleShape(convertCoord_fromWorld_toWindow(b2Vec2(1.f,1.f)).x);//On converti la largeur du rectangle en rayon du cercle
	shape.setFillColor(sf::Color::Green); //On met la couleur verte pour différencier des monstres (on les mettra rouge ?)
	shape.setPosition(convertCoord_fromWorld_toWindow(body->GetTransform().p));

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
	sf::Vector2f res(wrld_coord.x * 10, 800 - wrld_coord.y * 10);

	return res;
}
;