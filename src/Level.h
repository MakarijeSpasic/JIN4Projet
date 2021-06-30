#pragma once
#include <map>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics.hpp>
#include "SFMLOrthogonalLayer.h"

#include <tmxlite/Map.hpp>

#include "box2d/box2d.h"
#include <PersonnageJoueur.h>
#include <Monstre.h>

//cette classe permet de définir les niveaux qui seront construits via le builder

class Level
{
public:
	//Chaque niveau est défini par sa map, la position initiale du joueur sur la map, les monstres qui sont dessus et la carte à dessiner.

	tmx::Map* Map;
	float InitPlayerX;
	float InitPlayerY;
	std::vector<Monstre> monsters;
	MapLayer* MapToDraw;

};
