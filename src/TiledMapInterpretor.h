#pragma once
#include "Entite.h"

#include <vector>
#include <memory>
#include <string>
#include <myMain.h>

class TiledMapConverter {
public:
	TiledMapConverter(b2World* world, sf::RenderWindow* window);

	//Permet de cr�er les objets de hitbox associ�s aux murs via le layer d'objects fourni dans le fichier tmx
	void createWalls(tmx::Map* map);

	//Permet de dessiner l'endroit th�orique o� devraient se trouver les hitbox sur l'�cran de jeu, plus facile � d�bugger ainsi
	sf::RectangleShape createHitbox(float position_X, float position_Y, float height, float width);
	void renderHitbox();

private:
	b2World* world;

	//pour les tests de dessin de hitbox:
	sf::RenderWindow* window;
	std::vector<sf::RectangleShape> hitboxes;
};

