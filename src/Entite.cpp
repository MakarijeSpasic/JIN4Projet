#include "Entite.h"
#include <iostream>

Entite::Entite(b2World* world, float wrld_x, float wrld_y, int health, int force) : 
	world(world),
	health(health),
	force(force)
{
	//Création d'un body que l'on va pouvoir manipuler

	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(wrld_x, wrld_y);//On bouge le body avant de le créer dans le monde : meilleur perf
	bodyDef.allowSleep = true;//Aussi pour les performances : si le body ne bouge pas il est mis au repos => moins de CPU
	bodyDef.awake = true;
	bodyDef.fixedRotation = true;//On ne veut pas qu'il tourne
	bodyDef.linearDamping = 10.f;//TEST
	bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(this);
	body = world->CreateBody(&bodyDef);
	std::cout << "Hitbox position : " << bodyDef.position.x << " " << bodyDef.position.y << std::endl;
	dynamic_box.SetAsBox(1.0f, 1.0f);//On fait une boite de cette taille là pour l'instant

	fixtureDef.shape = &dynamic_box;
	fixtureDef.density = 1.0f;
	body->CreateFixture(&fixtureDef);


}



void Entite::LoseHealth(int damage) {
	health -= damage;
	if (health <= 0) { //On clamp health au dessus de 0 pour ne pas avoir d'absurdité
		health = 0;
		//Destruction de l'object
		//Et faire en sorte qu'il ne s'affiche plus
		//à faire ...
	}
	
}

void Entite::LoseForce(int loss)
{
	force -= loss;
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
	

	b2Vec2 res(win_coord.x / 10, (608 - win_coord.y) / 10);

	return res;

}
sf::Vector2f Entite::convertCoord_fromWorld_toWindow(b2Vec2 wrld_coord)
{
	sf::Vector2f res(wrld_coord.x * 10, 608 - wrld_coord.y * 10);

	return res;
}
;