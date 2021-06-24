#pragma once
#include "Entite.h"

#include <vector>
#include <memory>
#include <string>
#include <myMain.h>

class TiledMapConverter {
public:
	TiledMapConverter(b2World* world, sf::RenderWindow* window);
	void createWalls(tmx::Map* map);
	sf::RectangleShape createHitbox(float position_X, float position_Y, float height, float width);
	void renderHitbox();

private:
	b2World* world;

	//pour les tests de dessin de hitbox:
	sf::RenderWindow* window;
	std::vector<sf::RectangleShape> hitboxes;
};

